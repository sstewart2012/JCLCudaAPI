package ca.uwaterloo.JCLCudaAPI;

public class Context {

  static {
    String type = System.getProperty("deviceType");
    if (type == null || type.equals("opencl"))
      System.loadLibrary("JCLCudaAPI_opencl");
    else
      System.loadLibrary("JCLCudaAPI_cuda");
  }

  /** A handle (memory address) to the C++ object. */
  private long nativeHandle;

  public Context(final Device device) {
    init(device);
  }

  private native void init(final Device device);

  @Override
  public String toString() {
    return "CudaContext [nativeHandle=" + nativeHandle + "]";
  }

}
