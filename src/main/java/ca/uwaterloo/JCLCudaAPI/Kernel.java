package ca.uwaterloo.JCLCudaAPI;

import java.util.List;

public interface Kernel {

  void setArgument();
  
  long localMemUsage(Device d);
  
  void launch(Queue queue, long[] global, long[] local, Event e);
  
  void launch(Queue queue, long[] global, long[] local, Event e, List<Event> waitForEvents);
  
  Function getFunction();
}
