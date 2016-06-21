package ca.uwaterloo.JCLCudaAPI;

import java.nio.ByteBuffer;
import java.nio.ByteOrder;

public class BufferHost {

  private ByteBuffer bb;
  
  static {
    if (System.getProperty("deviceType").equals("cuda"))
      System.loadLibrary("JCLCudaAPI_cuda");
    else
      System.loadLibrary("JCLCudaAPI_opencl");
  }

  /** A handle (memory address) to the C++ object. */
  private long nativeHandle;

  public BufferHost(final Context context, final long size) {
    init(context, size);
    bb = getByteBuffer();
    bb.order(ByteOrder.nativeOrder());
    System.out.println(bb.asFloatBuffer().get(0));
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
