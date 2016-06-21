package ca.uwaterloo.JCLCudaAPI;

public class Buffer {

  static {
    if (System.getProperty("deviceType").equals("cuda"))
      System.loadLibrary("JCLCudaAPI_cuda");
    else
      System.loadLibrary("JCLCudaAPI_opencl");
  }

  /** A handle (memory address) to the C++ object. */
  private long nativeHandle;

  public Buffer(final Context context, final long size) {
    init(context, size);
  }

  private native void init(final Context context, final long size);

  public native void readAsync(Queue queue, long size, BufferHost host, long offset);

  public native void read(Queue queue, long size, BufferHost host, long offset);

  public native void writeAsync(Queue queue, long size, BufferHost host, long offset);

  public native void write(Queue queue, long size, BufferHost host, long offset);

  public native void copyToAsync(Queue queue, long size, Buffer dst);

  public native void copyTo(Queue queue, long size, Buffer dst);

  public native long getSize();

  @Override
  public String toString() {
    return "Buffer [nativeHandle=" + nativeHandle + "]";
  }

}
