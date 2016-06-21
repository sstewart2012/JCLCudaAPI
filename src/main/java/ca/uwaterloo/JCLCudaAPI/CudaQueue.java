package ca.uwaterloo.JCLCudaAPI;

public class CudaQueue implements Queue {

  static {
    System.loadLibrary("JCLCudaAPI");
  }
  
  /** A handle (memory address) to the C++ object. */
  private long nativeHandle;

  public CudaQueue(final CudaContext context, final CudaDevice device) {
    init(context, device);
  }
  
  private native void init(final CudaContext context, final CudaDevice device);
  
  @Override
  public native void finish(Event e);

  @Override
  public native void finish();

  @Override
  public native Context getContext();

  @Override
  public native Device getDevice();

  @Override
  public String toString() {
    return "CudaQueue [nativeHandle=" + nativeHandle + "]";
  }

}
