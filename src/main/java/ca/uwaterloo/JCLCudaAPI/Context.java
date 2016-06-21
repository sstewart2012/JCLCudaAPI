package ca.uwaterloo.JCLCudaAPI;

public class Context {

  static {
    if (System.getProperty("deviceType").equals("cuda"))
      System.loadLibrary("JCLCudaAPI_cuda");
    else
      System.loadLibrary("JCLCudaAPI_opencl");
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
