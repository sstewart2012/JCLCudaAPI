package ca.uwaterloo.JCLCudaAPI;

import java.util.List;

public class Kernel {

  static {
    if (System.getProperty("deviceType").equals("cuda"))
      System.loadLibrary("JCLCudaAPI_cuda");
    else
      System.loadLibrary("JCLCudaAPI_opencl");
  }

  /** A handle (memory address) to the C++ object. */
  private long nativeHandle;
  
  public Kernel(final Program program, final String name) {
    init(program, name);
  }
  
  private native void init(Program program, String name);

  public native void setArgument(final long index, final Buffer buffer);

  public native void setArgument(long index, int val);

  public native void setArgument(long index, float val);
  
  public native void setArgument(long index, double val);
  
  public native long localMemUsage(Device d);

  public native void launch(Queue queue, long[] global, long[] local, Event e);

  public native void launch(Queue queue, long[] global, long[] local, Event e, List<Event> waitForEvents);

  @Override
  public String toString() {
    return "CudaKernel [nativeHandle=" + nativeHandle + "]";
  }

}
