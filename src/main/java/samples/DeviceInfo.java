package samples;

import ca.uwaterloo.JCLCudaAPI.Device;
import ca.uwaterloo.JCLCudaAPI.Platform;

public class DeviceInfo {

  public static void main(String[] args) {
    final int platformId = 0;
    final int deviceId = 0;
    final Platform platform = new Platform(platformId);
    final Device device = new Device(platform, deviceId);

    System.out.printf("\n## Printing device information...\n");
    System.out.printf(" > Platform ID                  %d\n", platformId);
    System.out.printf(" > Device ID                    %d\n", deviceId);
    System.out.printf(" > Framework version            %s\n", device.version());
    System.out.printf(" > Vendor                       %s\n", device.vendor());
    System.out.printf(" > Device name                  %s\n", device.name());
    System.out.printf(" > Device type                  %s\n", device.type());
    System.out.printf(" > Max work-group size          %d\n", device.maxWorkGroupSize());
    System.out.printf(" > Max thread dimensions        %d\n", device.maxWorkItemDimensions());
    System.out.printf(" > Max work-group sizes:\n");
    for (int i = 0; i < device.maxWorkItemDimensions(); i++)
      System.out.printf("   - in the %d-dimension         %d\n", i, device.maxWorkItemSizes()[i]);
    System.out.printf(" > Local memory per work-group  %d bytes\n", device.localMemSize());
    System.out.printf(" > Device capabilities          %s\n", device.capabilities());
    System.out.printf(" > Core clock rate              %d MHz\n", device.coreClock());
    System.out.printf(" > Number of compute units      %d\n", device.computeUnits());
    System.out.printf(" > Total memory size            %d bytes\n", device.memorySize());
    System.out.printf(" > Maximum allocatable memory   %d bytes\n", device.maxAllocSize());
    System.out.printf(" > Memory clock rate            %d MHz\n", device.memoryClock());
    System.out.printf(" > Memory bus width             %d bits\n", device.memoryBusWidth());
  }

}
