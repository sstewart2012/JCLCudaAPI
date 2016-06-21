package ca.uwaterloo.JCLCudaAPI;

import java.util.ArrayList;

public class Main {

  public static void main(String[] args) {
    final Platform platform = new CudaPlatform(0);
    System.out.println(platform);
    
    final Device device = new CudaDevice((CudaPlatform)platform, 0);
    System.out.println(device);
    System.out.println("Name                         : " + device.name());
    System.out.println("Driver version               : " + device.version());
    System.out.println("Type                         : " + device.type());
    System.out.println("Vendor                       : " + device.vendor());
    System.out.println("Compute units                : " + device.computeUnits());
    System.out.println("Capabilities                 : " + device.capabilities());
    
    final Context context = new CudaContext((CudaDevice)device);
    System.out.println(context);
    
    String source = "__global__ void a() {int idx = threadIdx.x;}";
    final Program program = new CudaProgram((CudaContext)context, source);
    System.out.println(program);
    
    program.build(device, new ArrayList<>());
    
    final Queue queue = new CudaQueue((CudaContext)context, (CudaDevice)device);
    System.out.println(queue);
    
    final Event event = new CudaEvent();
    System.out.println(event);
  }

}
