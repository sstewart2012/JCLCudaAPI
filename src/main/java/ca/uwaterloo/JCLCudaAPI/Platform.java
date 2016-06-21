package ca.uwaterloo.JCLCudaAPI;

public final class Platform {

  static {
    String type = System.getProperty("deviceType");
    if (type == null || type.equals("opencl"))
      System.loadLibrary("JCLCudaAPI_opencl");
    else
      System.loadLibrary("JCLCudaAPI_cuda");
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
