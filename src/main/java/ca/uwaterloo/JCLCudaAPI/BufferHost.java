package ca.uwaterloo.JCLCudaAPI;

import java.nio.ByteBuffer;
import java.nio.ByteOrder;

public class BufferHost {

  private ByteBuffer bb;
  
  static {
    String type = System.getProperty("deviceType");
    if (type == null || type.equals("opencl"))
      System.loadLibrary("JCLCudaAPI_opencl");
    else
      System.loadLibrary("JCLCudaAPI_cuda");
  }

  /** A handle (memory address) to the C++ object. */
  private long nativeHandle;

  public BufferHost(final Context context, final long size) {
    init(context, size);
    bb = getByteBuffer();
    bb.order(ByteOrder.nativeOrder());
  }
  
  private native void init(final Context context, final long size);

  private native ByteBuffer getByteBuffer();
  
  public native long getSize();

  public native long size();

  public ByteBuffer data() {
    return bb;
  }
  
  public native long getNativePointerAddress();

  @Override
  public String toString() {
    return "CudaBufferHost [nativeHandle=" + nativeHandle
        + ", getSize()=" + getSize() + ", size()=" + size() + ", getNativePointerAddress()="
        + getNativePointerAddress() + "]";
  }

}
