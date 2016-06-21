import java.util.ArrayList;

import ca.uwaterloo.JCLCudaAPI.Buffer;
import ca.uwaterloo.JCLCudaAPI.BufferHost;
import ca.uwaterloo.JCLCudaAPI.Context;
import ca.uwaterloo.JCLCudaAPI.Device;
import ca.uwaterloo.JCLCudaAPI.Event;
import ca.uwaterloo.JCLCudaAPI.Kernel;
import ca.uwaterloo.JCLCudaAPI.Platform;
import ca.uwaterloo.JCLCudaAPI.Program;
import ca.uwaterloo.JCLCudaAPI.Queue;
import ca.uwaterloo.JCLCudaAPI.Program.BuildStatus;

public class Smallest {

  final static String cudaProgramString =
      "extern \"C\" __global__ void add(const float* a, const float* b, float* c) { const int idx = threadIdx.x + blockDim.x*blockIdx.x; c[idx] = a[idx] + b[idx]; }\n";

  final static String openclProgramString =
      "__kernel void add(__global const float *a, __global const float *b, __global float* c) { unsigned idx = get_global_id(0); c[idx] = a[idx] + b[idx]; }\n";

  public static void main(String[] args) {
    String programSource;
    String requestedDeviceType = System.getProperty("deviceType");
    if (requestedDeviceType == null || requestedDeviceType.equals("opencl"))
      programSource = openclProgramString;
    else
      programSource = cudaProgramString;
    
    final int platformId = 0;
    final int deviceId = 0;
    final Platform platform = new Platform(platformId);
    final Device device = new Device(platform, deviceId);
    final Context context = new Context(device);
    final Queue queue = new Queue(context, device);
    final Event event = new Event();
    
    // Creates and populates device memory
    final long nelems = 1024;
    final long nbytes = nelems * 4;
    final BufferHost h_data = new BufferHost(context, nbytes);
    for (int i = 0; i < nelems; i++) {
      h_data.data().asFloatBuffer().put(i, i);
    }
    final Buffer d_A = new Buffer(context, nbytes);
    final Buffer d_B = new Buffer(context, nbytes);
    final Buffer d_C = new Buffer(context, nbytes);
    d_A.write(queue, nbytes, h_data, 0L);
    d_B.write(queue, nbytes, h_data, 0L);
    
    // Compiles and launches the kernel
    final Program program = new Program(context, programSource);
    ArrayList<String> compilerOptions = new ArrayList<>();
    BuildStatus buildStatus = program.build(device, compilerOptions);
    System.out.println(buildStatus);
    if (buildStatus != BuildStatus.Success) {
      String message = program.getBuildInfo(device);
      System.out.printf(" > Compiler error(s)/warning(s) found:\n%s\n", message);
      System.exit(1);
    }
    final Kernel kernel = new Kernel(program, "add");
    kernel.setArgument(0, d_A);
    kernel.setArgument(1, d_B);
    kernel.setArgument(2, d_C);
    kernel.launch(queue, new long[] {nelems}, new long[] {128}, event);
    queue.finish();
    
    // Reads the results back to the host memory
    BufferHost h_result = new BufferHost(context, nbytes);
    d_C.read(queue, nbytes, h_result, 0L);
    for (int i = 0; i < nelems; i++) {
      System.out.println(h_result.data().asFloatBuffer().get(i));
    }
  }

}
