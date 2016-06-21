nvcc -m64 -std=c++11 -I /usr/lib/jvm/java-8-oracle/include/ -I /usr/lib/jvm/java-8-oracle/include/linux -I ../include/ -Xcompiler '-fPIC' -dlink -dc -o JCLCudaAPI.o -c JCLCudaAPI.cpp
nvcc -shared -m64 -Xcompiler '-fPIC' -L/usr/local/cuda/lib64 -o libJCLCudaAPI_cuda.so JCLCudaAPI.o -lcuda -ldl -lnvrtc
g++ -std=c++11 -I /usr/lib/jvm/java-8-oracle/include/ -I /usr/lib/jvm/java-8-oracle/include/linux -I ../include/ -I /usr/local/cuda/include/ JCLCudaAPI.cpp -DUSE_OPENCL -lOpenCL -fPIC -shared -o libJCLCudaAPI_opencl.so
mv *.so ../../../../lib/linux/
rm *.o