package ca.uwaterloo.JCLCudaAPI;

import java.util.List;

public interface Device {

  String version();

  String vendor();

  String name();

  String type();

  long maxWorkGroupSize();

  long maxWorkItemDimensions();

  List<Integer> maxWorkItemSizes();

  long localMemSize();

  String capabilities();

  long coreClock();

  long computeUnits();

  long memorySize();

  long maxAllocSize();

  long memoryClock();

  long memoryBusWidth();

  boolean isLocalMemoryValid(long localMemUsage);

  boolean isThreadConfigValid(List<Long> local);

}
