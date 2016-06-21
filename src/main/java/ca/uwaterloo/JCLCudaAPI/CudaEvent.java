package ca.uwaterloo.JCLCudaAPI;

public class CudaEvent implements Event {

  static {
    System.loadLibrary("JCLCudaAPI");
  }
  
  /** A handle (memory address) to the C++ object. */
  private long nativeHandle;
  
  public CudaEvent() {
    init();
  }
  
  private native void init();
  
  @Override
  public native float getElapsedTime();

  @Override
  public native void waitForCompletion();

  @Override
  public String toString() {
    return "CudaEvent [nativeHandle=" + nativeHandle + "]";
  }

}
