package ca.uwaterloo.JCLCudaAPI;

public interface Queue {

  void finish(Event e);
  
  void finish();
  
  Context getContext();
  
  Device getDevice();
  
}
