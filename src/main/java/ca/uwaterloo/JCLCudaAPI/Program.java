package ca.uwaterloo.JCLCudaAPI;

import java.util.List;

public final class Program {

  public enum BuildStatus {
    Success, Error, Invalid 
  }
  
  static {
    String type = System.getProperty("deviceType");
    if (type == null || type.equals("opencl"))
      System.loadLibrary("JCLCudaAPI_opencl");
    else
      System.loadLibrary("JCLCudaAPI_cuda");
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
