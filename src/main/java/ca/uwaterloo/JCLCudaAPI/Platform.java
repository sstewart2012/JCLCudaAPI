package ca.uwaterloo.JCLCudaAPI;

public final class Platform {

  static {
    if (System.getProperty("deviceType").equals("cuda"))
      System.loadLibrary("JCLCudaAPI_cuda");
    else
      System.loadLibrary("JCLCudaAPI_opencl");
  }

  /** A handle (memory address) to the C++ object. */
  private long nativeHandle;

  public Platform(final int platformId) {
    init(platformId);
  }

  private native void init(final int platformId);

  public native int numDevices();

  @Override
  public String toString() {
    return "CudaPlatform [nativeHandle=" + nativeHandle + "]";
  }

}
