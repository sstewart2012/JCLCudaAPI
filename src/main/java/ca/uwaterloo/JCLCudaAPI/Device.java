package ca.uwaterloo.JCLCudaAPI;

import java.util.List;

public final class Device {

  static {
    if (System.getProperty("deviceType").equals("cuda"))
      System.loadLibrary("JCLCudaAPI_cuda");
    else
      System.loadLibrary("JCLCudaAPI_opencl");
  }
  
  /** A handle (memory address) to the C++ object. */
  private long nativeHandle;
  
  public Device(final Platform platform, final int deviceId) {
    init(platform, deviceId);
  }
  
  private native void init(final Platform platform, final int deviceId);
  
  public native String version();

  public native String vendor();

  public native String name();

  public native String type();

  public native long maxWorkGroupSize();

  public native long maxWorkItemDimensions();

  public native List<Integer> maxWorkItemSizes();

  public native long localMemSize();

  public native String capabilities();

  public native long coreClock();

  public native long computeUnits();

  public native long memorySize();

  public native long maxAllocSize();

  public native long memoryClock();

  public native long memoryBusWidth();

  public native boolean isLocalMemoryValid(final long localMemUsage);

  public native boolean isThreadConfigValid(final List<Long> local);

  @Override
  public String toString() {
    return "CudaDevice [nativeHandle=" + nativeHandle + "]";
  }

}
