package ca.uwaterloo.JCLCudaAPI;

public class Queue {

  static {
    if (System.getProperty("deviceType").equals("cuda"))
      System.loadLibrary("JCLCudaAPI_cuda");
    else
      System.loadLibrary("JCLCudaAPI_opencl");
  }
  
  /** A handle (memory address) to the C++ object. */
  private long nativeHandle;

  public Queue(final Context context, final Device device) {
    init(context, device);
  }
  
  private native void init(final Context context, final Device device);
  
  public native void finish(Event e);

  public native void finish();

  public native Context getContext();

  public native Device getDevice();

  @Override
  public String toString() {
    return "CudaQueue [nativeHandle=" + nativeHandle + "]";
  }

}
