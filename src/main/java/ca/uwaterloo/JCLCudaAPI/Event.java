package ca.uwaterloo.JCLCudaAPI;

public class Event {

  static {
    String type = System.getProperty("deviceType");
    if (type == null || type.equals("opencl"))
      System.loadLibrary("JCLCudaAPI_opencl");
    else
      System.loadLibrary("JCLCudaAPI_cuda");
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
