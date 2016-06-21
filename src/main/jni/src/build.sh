nvcc -m64 -std=c++11 -I /usr/lib/jvm/java-8-oracle/include/ -I /usr/lib/jvm/java-8-oracle/include/linux -I ../include/ -Xcompiler '-fPIC' -dlink -dc -o cuda.o -c cuda.cpp
nvcc -shared -m64 -Xcompiler '-fPIC' -L/usr/local/cuda/lib64 -o libJCLCudaAPI.so cuda.o -lcuda -ldl -lnvrtc
mv libJCLCudaAPI.so ../../../../lib/linux/
rm *.o
