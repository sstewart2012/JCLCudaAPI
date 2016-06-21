package ca.uwaterloo.JCLCudaAPI;

public class CudaContext implements Context {

  static {
    System.loadLibrary("JCLCudaAPI");
  }

  /** A handle (memory address) to the C++ object. */
  private long nativeHandle;

  public CudaContext(final CudaDevice device) {
    init(device);
  }

  private native void init(final CudaDevice device);

  @Override
  public String toString() {
    return "CudaContext [nativeHandle=" + nativeHandle + "]";
  }

}
