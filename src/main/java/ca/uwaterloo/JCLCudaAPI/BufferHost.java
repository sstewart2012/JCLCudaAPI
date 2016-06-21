package ca.uwaterloo.JCLCudaAPI;

public interface BufferHost {

  long getSize();
  
  long size();
  
  byte[] data();
  
  long getNativePointerAddress();
  
}
