package ca.uwaterloo.JCLCudaAPI;

import java.util.List;

public final class CudaProgram implements Program {

  static {
    System.loadLibrary("JCLCudaAPI");
  }
  
  /** A handle (memory address) to the C++ object. */
  private long nativeHandle;

  public CudaProgram(final CudaContext context, final String source) {
    init(context, source);
  }
  
  private native void init(final CudaContext context, final String source);

  @Override
  public native BuildStatus build(final Device d, final List<String> options);

  @Override
  public native String getBuildInfo(final Device d);

  @Override
  public native String getIR();

  @Override
  public String toString() {
    return "CudaProgram [nativeHandle=" + nativeHandle + "]";
  }

}
