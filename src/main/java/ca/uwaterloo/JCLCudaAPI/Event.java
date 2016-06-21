package ca.uwaterloo.JCLCudaAPI;

public class Event {

  static {
    if (System.getProperty("deviceType").equals("cuda"))
      System.loadLibrary("JCLCudaAPI_cuda");
    else
      System.loadLibrary("JCLCudaAPI_opencl");
  }
  
  /** A handle (memory address) to the C++ object. */
  private long nativeHandle;
  
  public Event() {
    init();
  }
  
  private native void init();
  
  public native float getElapsedTime();

  public native void waitForCompletion();

  @Override
  public String toString() {
    return "CudaEvent [nativeHandle=" + nativeHandle + "]";
  }

}
