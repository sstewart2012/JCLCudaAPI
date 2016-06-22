nvcc -m64 -std=c++11 -I /Library/Java/JavaVirtualMachines/jdk1.8.0_31.jdk/Contents/Home/include/ -I /Library/Java/JavaVirtualMachines/jdk1.8.0_31.jdk/Contents/Home/include/darwin -I ../include/ -Xcompiler '-fPIC' -dlink -dc -o JCLCudaAPI.o -c JCLCudaAPI.cpp
nvcc -Xlinker '-F/Library/Frameworks -framework CUDA' -shared -m64 -Xcompiler '-fPIC' -L/usr/local/cuda/lib -o libJCLCudaAPI_cuda.dylib JCLCudaAPI.o -lcuda -ldl -lnvrtc
g++ -std=c++11 -I /Library/Java/JavaVirtualMachines/jdk1.8.0_31.jdk/Contents/Home/include/ -I /Library/Java/JavaVirtualMachines/jdk1.8.0_31.jdk/Contents/Home/include/darwin -I ../include/ -I /usr/local/cuda/include/ JCLCudaAPI.cpp -DUSE_OPENCL -framework OpenCL -fPIC -shared -o libJCLCudaAPI_opencl.dylib
mv *.dylib ../../../../lib/
rm *.o