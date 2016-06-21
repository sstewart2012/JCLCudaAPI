package ca.uwaterloo.JCLCudaAPI;

import java.util.List;

public final class CudaDevice implements Device {

  static {
    System.loadLibrary("JCLCudaAPI");
  }
  
  /** A handle (memory address) to the C++ object. */
  private long nativeHandle;
  
  public CudaDevice(final CudaPlatform platform, final int deviceId) {
    init(platform, deviceId);
  }
  
  private native void init(final CudaPlatform platform, final int deviceId);
  
  @Override
  public native String version();

  @Override
  public native String vendor();

  @Override
  public native String name();

  @Override
  public native String type();

  @Override
  public native long maxWorkGroupSize();

  @Override
  public native long maxWorkItemDimensions();

  @Override
  public native List<Integer> maxWorkItemSizes();

  @Override
  public native long localMemSize();

  @Override
  public native String capabilities();

  @Override
  public native long coreClock();

  @Override
  public native long computeUnits();

  @Override
  public native long memorySize();

  @Override
  public native long maxAllocSize();

  @Override
  public native long memoryClock();

  @Override
  public native long memoryBusWidth();

  @Override
  public native boolean isLocalMemoryValid(final long localMemUsage);

  @Override
  public native boolean isThreadConfigValid(final List<Long> local);

  @Override
  public String toString() {
    return "CudaDevice [nativeHandle=" + nativeHandle + "]";
  }

}
