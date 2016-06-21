package ca.uwaterloo.JCLCudaAPI;

public interface Buffer {

  enum BufferAccess {
    readOnly, writeOnly, readWrite, notOwned
  }
  
  void readAsync();
  
  void read();
  
  void writeAsync();
  
  void write();
  
  void copyToAsync();
  
  void copyTo();
  
  long getSize();
 
  long getNativePointerAddress();
  
}
