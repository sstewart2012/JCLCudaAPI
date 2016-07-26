package samples;

import java.util.ArrayList;

import ca.uwaterloo.JCLCudaAPI.Buffer;
import ca.uwaterloo.JCLCudaAPI.BufferHost;
import ca.uwaterloo.JCLCudaAPI.Context;
import ca.uwaterloo.JCLCudaAPI.Device;
import ca.uwaterloo.JCLCudaAPI.Event;
import ca.uwaterloo.JCLCudaAPI.Kernel;
import ca.uwaterloo.JCLCudaAPI.Platform;
import ca.uwaterloo.JCLCudaAPI.Program;
import ca.uwaterloo.JCLCudaAPI.Program.BuildStatus;
import ca.uwaterloo.JCLCudaAPI.Queue;

public class Simple {

  final static String cudaProgramString =
      "extern \"C\" __global__ void multiply(float *x, float *y, const int factor) { const int tid = threadIdx.x + blockDim.x*blockIdx.x; y[tid] = x[tid] * factor; }\n";

  final static String openclProgramString =
      "__kernel void multiply(__global float *x, __global float *y, const int factor) { const int tid = get_global_id(0); y[tid] = x[tid] * factor; }\n";

  public static void main(String[] args) {
    final int workgroupSize = 128; // # of threads per workgroup
    final int platformId = 0;
    final int deviceId = 0;
    final int size = 256 * 256;
    final int multiplyFactor = 2;

    String programSource;
    String requestedDeviceType = System.getProperty("deviceType");
    if (requestedDeviceType == null || requestedDeviceType.equals("opencl"))
      programSource = openclProgramString;
    else
      programSource = cudaProgramString;

    // Initializes the platform and device
    System.out.println("\n## Initializing...");
    final Platform platform = new Platform(platformId);
    final Device device = new Device((Platform) platform, deviceId);
    System.out.printf(" > Running on device '%s' of '%s'\n", device.name(), device.vendor());

    // Creates a new context and queue for the device
    final Context context = new Context(device);
    final Queue queue = new Queue(context, device);

    // Creates a new event for timing kernels
    final Event event = new Event();

    // Creates a new program based on the kernel string, then builds the program, checking for any
    // compilation errors.
    System.out.println("## Compiling the kernel...");
    final Program program = new Program(context, programSource);

    final ArrayList<String> compilerOptions = new ArrayList<>();
    BuildStatus buildStatus = program.build(device, compilerOptions);
    System.out.println(buildStatus);
    if (buildStatus != BuildStatus.Success) {
      String message = program.getBuildInfo(device);
      System.out.printf(" > Compiler error(s)/warning(s) found:\n%s\n", message);
      System.exit(1);
    }

    // Populates regular host vectors with example data
    BufferHost h_A = new BufferHost(context, size * 4);
    BufferHost h_B = new BufferHost(context, size * 4);
    for (int i = 0; i < size; i++) {
      h_A.data().asFloatBuffer().put(i, (float) i);
      h_B.data().asFloatBuffer().put(i, 0.0f);
    }

    // Creates two new device buffers and copies the host data to these device buffers
    Buffer d_A = new Buffer(context, h_A.getSize());
    Buffer d_B = new Buffer(context, h_B.getSize());
    d_A.write(queue, h_A.getSize(), h_A, 0L);
    d_B.write(queue, h_B.getSize(), h_B, 0L);

    // Creates the 'multiply' kernel from the compiled program and sets the three arguments. Note
    // that the indices of the arguments have to be set according to their order in the kernel.
    Kernel kernel = new Kernel(program, "multiply");
    kernel.setArgument(0, d_A);
    kernel.setArgument(1, d_B);
    kernel.setArgument(2, multiplyFactor);

    // Creates a 1D thread configuration ith thread-blocks/workgroups of 256 threads and a total
    // number of threads equal to the number of elements in the input/output vectors.
    final long[] global = {size};
    final long[] local = {workgroupSize};

    // Enqueues the kernel and waits for the result. Note that launching the kernel is always
    // asynchronous and thus requires finishing the queue in order to complete the operation.
    System.out.println("## Running the kernel...");
    kernel.launch(queue, global, local, event);
    queue.finish();
    System.out.printf(" > Took %.3f ms\n", event.getElapsedTime());

    // Reads the results back to the host memory
    d_B.read(queue, h_B.getSize(), h_B, 0);

    // Prints the results for a couple of indices to verify that the work has been done
    System.out.println("## All done. Sampled verification:");
    final int[] verificationIndices = {4, 900};
    for (Integer idx : verificationIndices) {
      float valA = h_A.data().asFloatBuffer().get(idx);
      float valB = h_B.data().asFloatBuffer().get(idx);
      System.out.printf(" > %f*%d = %f\n", valA, multiplyFactor, valB);
    }

  }

}
