package ca.uwaterloo.JCLCudaAPI;

import java.util.List;

public final class Program {

  enum BuildStatus {
    Success, Error, Invalid 
  }
  
  static {
    if (System.getProperty("deviceType").equals("cuda"))
      System.loadLibrary("JCLCudaAPI_cuda");
    else
      System.loadLibrary("JCLCudaAPI_opencl");
  }
  
  /** A handle (memory address) to the C++ object. */
  private long nativeHandle;

  public Program(final Context context, final String source) {
    init(context, source);
  }
  
  private native void init(final Context context, final String source);

  public BuildStatus build(final Device d, final List<String> options) {
    int result = build_native(d, options);
    if (result == 0)
      return BuildStatus.Success;
    else if (result == 1)
      return BuildStatus.Error;
    else
      return BuildStatus.Invalid;
  }

  private native int build_native(final Device d, final List<String> options);
  
  public native String getBuildInfo(final Device d);

  public native String getIR();

  @Override
  public String toString() {
    return "CudaProgram [nativeHandle=" + nativeHandle + "]";
  }

}
