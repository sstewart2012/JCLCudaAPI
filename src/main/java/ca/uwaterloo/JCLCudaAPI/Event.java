package ca.uwaterloo.JCLCudaAPI;

public interface Event {

  void waitForCompletion();
  
  float getElapsedTime();
  
}
