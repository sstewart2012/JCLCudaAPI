package ca.uwaterloo.JCLCudaAPI;

public final class CudaPlatform implements Platform {

  static {
    System.loadLibrary("JCLCudaAPI");
  }

  /** A handle (memory address) to the C++ object. */
  private long nativeHandle;

  public CudaPlatform(final long platformId) {
    init(platformId);
  }

  private native void init(final long platformId);

  @Override
  public native int numDevices();

  @Override
  public String toString() {
    return "CudaPlatform [nativeHandle=" + nativeHandle + "]";
  }

}
