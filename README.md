# JCLCudaAPI

JCLCudaAPI is a Java wrapper for [CLCudaAPI](https://github.com/CNugteren/CLCudaAPI), which is authored by Cedric Nugteren. A detailed description of CLCudaAPI is provided [here](https://github.com/CNugteren/CLCudaAPI). In short, JCLCudaAPI allows you to write a single host application in Java that can launch  either CUDA or OpenCL kernels. The wrapper is implemented via JNI, and accesses pre-compiled static libraries of CLCudaAPI for both Linux and Apple users.

A similar project called [shediac](https://bitbucket.org/sstewart2015/shediac) is under development that is similar to JCLCudaAPI, but that instead leverages the [JCuda](https://github.com/jcuda) and [JOCL](https://github.com/gpu/JOCL) libraries for host-device interactions. In shediac, a KernelMgr class faciliates the creation and launching of either CUDA or OpenCL kernels from a Java application.

## Work-in-progress

This wrapper is presently a work-in-progress, and it may be the case that not all of the available functionality of [CLCudaAPI](https://github.com/CNugteren/CLCudaAPI) has been implemented.

## Building

The Java project can be built either in Eclipse or by using the Scala Build Tool (sbt). To use sbt, follow these instructions:

1. Switch to the project root directory that contains `build.sbt`
2. Enter `sbt clean compile` at the command line

Note that sbt will build any Java files that it finds under `src/main/java/`.

The JCLCudaAPI calls native methods, and so it is also necessary to build the C++ code that uses the JNI. These are located in `src/main/jni/`. At present, there are shell scripts that call the NVIDIA compiler (nvcc) and g++ to compile the respective CUDA and OpenCL implementations, which is clearly inadequate and not portable; makefiles will soon be added to resolve this short-coming.

## Running

1. Enter `sbt run "-Djava.library.path=lib"` at the command line
2. Select an available main method to run

Any main methods found under `src/main/java` will be listed. For example:

<pre>
Multiple main classes detected, select one to run:

 [1] samples.DeviceInfo
 [2] samples.Simple
 [3] samples.Smallest
</pre>

### Selecting the device type

JCLCudaAPI gives you the option of using CUDA or OpenCL. You can explictly select either CUDA or OpenCL by defining the `deviceType` property in your run configuration. If you are using sbt, you can enter the following for either CUDA or OpenCL:

<pre>$ sbt run "-Djava.library.path=lib -DdeviceType=cuda"</pre>
<pre>$ sbt run "-Djava.library.path=lib -DdeviceType=opencl"</pre>

Note that the default device type is OpenCL, which actually does not need to be explicitly specified.

### Setting up the CUDA environment variables

When selecting CUDA, it may be necessary to explicitly set the runtime environment variables as part of the run configuration. The following links from NVIDIA's website explain how to do this at the command line for either Linux or Mac OS X:

* [NVIDIA CUDA Getting Started Guide for Linux] (http://docs.nvidia.com/cuda/cuda-getting-started-guide-for-linux/#environment-setup)
* [NVIDIA CUDA Getting Started Guide for Mac OS X](http://docs.nvidia.com/cuda/cuda-getting-started-guide-for-mac-os-x/#install)

### Sample runs for OpenCL and CUDA

The following is sample output when specifically running the DeviceInfo sample for OpenCL. Note the use of `run-main` for selecting a specific main method:

<pre>
$ sbt "run-main samples.DeviceInfo" -Djava.library.path=lib
[info] Loading global plugins from /Users/sts/.sbt/0.13/staging/7d805c9e726f3e7c816e/plugins
[info] Set current project to JCLCudaAPI (in build file:/Users/stevenstewart/watform/eclipse/JCLCudaAPI/)
[info] Running samples.DeviceInfo 

## Printing device information...
 > Platform ID                  0
 > Device ID                    0
 > Framework version            OpenCL 1.2 
 > Vendor                       Intel
 > Device name                  Intel(R) Core(TM) i7-4870HQ CPU @ 2.50GHz
 > Device type                  CPU
 > Max work-group size          1024
 > Max thread dimensions        3
 > Max work-group sizes:
   - in the 0-dimension         1024
   - in the 1-dimension         1
   - in the 2-dimension         1
 > Local memory per work-group  32768 bytes
 > Device capabilities          cl_APPLE_SetMemObjectDestructor cl_APPLE_ContextLoggingFunctions cl_APPLE_clut cl_APPLE_query_kernel_names cl_APPLE_gl_sharing cl_khr_gl_event cl_khr_fp64 cl_khr_global_int32_base_atomics cl_khr_global_int32_extended_atomics cl_khr_local_int32_base_atomics cl_khr_local_int32_extended_atomics cl_khr_byte_addressable_store cl_khr_int64_base_atomics cl_khr_int64_extended_atomics cl_khr_3d_image_writes cl_khr_image2d_from_buffer cl_APPLE_fp64_basic_ops cl_APPLE_fixed_alpha_channel_orders cl_APPLE_biased_fixed_point_image_formats cl_APPLE_command_queue_priority
 > Core clock rate              2500 MHz
 > Number of compute units      8
 > Total memory size            0 bytes
 > Maximum allocatable memory   0 bytes
 > Memory clock rate            0 MHz
 > Memory bus width             0 bits
[success] Total time: 0 s, completed Jul 26, 2016 12:48:01 PM
</pre>

The following is sample output when specifically running the DeviceInfo sample for CUDA. Note the use of `deviceType=cuda`:

<pre>
$ sbt "run-main samples.DeviceInfo" -Djava.library.path=lib -DdeviceType=cuda
[info] Loading global plugins from /Users/sts/.sbt/0.13/staging/7d805c9e726f3e7c816e/plugins
[info] Set current project to JCLCudaAPI (in build file:/Users/stevenstewart/watform/eclipse/JCLCudaAPI/)
[info] Running samples.DeviceInfo 

## Printing device information...
 > Platform ID                  0
 > Device ID                    0
 > Framework version            CUDA driver 7050
 > Vendor                       NVIDIA Corporation
 > Device name                  GeForce GT 750M
 > Device type                  GPU
 > Max work-group size          1024
 > Max thread dimensions        3
 > Max work-group sizes:
   - in the 0-dimension         1024
   - in the 1-dimension         1024
   - in the 2-dimension         64
 > Local memory per work-group  49152 bytes
 > Device capabilities          SM 3.0
 > Core clock rate              925 MHz
 > Number of compute units      2
 > Total memory size            2147024896 bytes
 > Maximum allocatable memory   2147024896 bytes
 > Memory clock rate            2508 MHz
 > Memory bus width             128 bits
[success] Total time: 1 s, completed Jul 26, 2016 12:49:07 PM
</pre>

## Samples

Sample Java programs that demonstrate using JCLCudaAPI are provided in the samples package. These [samples](https://github.com/sstewart2012/JCLCudaAPI/tree/master/src/main/java/samples) mimic some of the samples provided in the [CLCudaAPI](https://github.com/CNugteren/CLCudaAPI) repository.

## License

The usage of [CLCudaAPI](https://github.com/CNugteren/CLCudaAPI) is subject to an Apache license, described here: [license](https://raw.githubusercontent.com/CNugteren/CLCudaAPI/master/LICENSE).
