#include <iostream>
#include <string>
#include <vector>
#include "handle.h"
#include "helper.h"

#ifdef USE_OPENCL
  #include "clpp11.h"
#else
  #include "cupp11.h"
#endif

#include "ca_uwaterloo_JCLCudaAPI_Event.h"
#include "ca_uwaterloo_JCLCudaAPI_Platform.h"
#include "ca_uwaterloo_JCLCudaAPI_Device.h"
#include "ca_uwaterloo_JCLCudaAPI_Context.h"
#include "ca_uwaterloo_JCLCudaAPI_Program.h"
#include "ca_uwaterloo_JCLCudaAPI_Queue.h"
#include "ca_uwaterloo_JCLCudaAPI_BufferHost.h"
#include "ca_uwaterloo_JCLCudaAPI_Buffer.h"
#include "ca_uwaterloo_JCLCudaAPI_Kernel.h"

using namespace std;
using namespace CLCudaAPI;

/********************************************************************************/
// CudaEvent
/********************************************************************************/
JNIEXPORT void JNICALL Java_ca_uwaterloo_JCLCudaAPI_Event_init
  (JNIEnv *env, jobject obj)
{
	Event *e = new Event();
	setHandle(env, obj, e);
}

JNIEXPORT jfloat JNICALL Java_ca_uwaterloo_JCLCudaAPI_Event_getElapsedTime
  (JNIEnv *env, jobject obj)
{
	Event *e = getHandle<Event>(env, obj);
	float time = e->GetElapsedTime();
	return (jfloat) time;
}

JNIEXPORT void JNICALL Java_ca_uwaterloo_JCLCudaAPI_Event_waitForCompletion
  (JNIEnv *env, jobject obj)
{
	Event *e = getHandle<Event>(env, obj);
	e->WaitForCompletion();
}

/********************************************************************************/
// Platform
/********************************************************************************/
JNIEXPORT void JNICALL Java_ca_uwaterloo_JCLCudaAPI_Platform_init
  (JNIEnv *env, jobject obj, jint platform_id)
{
	Platform *p = new Platform((size_t)platform_id);
	setHandle(env, obj, p);
}

JNIEXPORT jint JNICALL Java_ca_uwaterloo_JCLCudaAPI_Platform_numDevices
  (JNIEnv *env, jobject obj)
{
	Platform *p = getHandle<Platform>(env, obj);
    return (jint)p->NumDevices();
}

/********************************************************************************/
// Device
/********************************************************************************/
JNIEXPORT void JNICALL Java_ca_uwaterloo_JCLCudaAPI_Device_init
  (JNIEnv *env, jobject obj, jobject platform, jint device_id)
{
	Platform *p = getHandle<Platform>(env, platform);
	Device *d = new Device(*p, (size_t)device_id);
	setHandle(env, obj, d);
}

JNIEXPORT jstring JNICALL Java_ca_uwaterloo_JCLCudaAPI_Device_version
  (JNIEnv *env, jobject obj)
{
	Device *d = getHandle<Device>(env, obj);
	std::string str = d->Version();
	jstring jstr = env->NewStringUTF(str.c_str());
	return jstr;
}

JNIEXPORT jstring JNICALL Java_ca_uwaterloo_JCLCudaAPI_Device_vendor
  (JNIEnv *env, jobject obj)
{
	Device *d = getHandle<Device>(env, obj);
	std::string str = d->Vendor();
	jstring jstr = env->NewStringUTF(str.c_str());
	return jstr;
}

JNIEXPORT jstring JNICALL Java_ca_uwaterloo_JCLCudaAPI_Device_name
  (JNIEnv *env, jobject obj)
{
	Device *d = getHandle<Device>(env, obj);
	std::string str = d->Name();
	jstring jstr = env->NewStringUTF(str.c_str());
	return jstr;
}

JNIEXPORT jstring JNICALL Java_ca_uwaterloo_JCLCudaAPI_Device_type
  (JNIEnv *env, jobject obj)
{
 	Device *d = getHandle<Device>(env, obj);
	std::string str = d->Type();
	jstring jstr = env->NewStringUTF(str.c_str());
	return jstr;
}

JNIEXPORT jlong JNICALL Java_ca_uwaterloo_JCLCudaAPI_Device_maxWorkGroupSize
  (JNIEnv *env, jobject obj)
{
 	Device *d = getHandle<Device>(env, obj);
 	size_t val = d->MaxWorkGroupSize();
 	return (jlong) val;
}

JNIEXPORT jlong JNICALL Java_ca_uwaterloo_JCLCudaAPI_Device_maxWorkItemDimensions
  (JNIEnv *env, jobject obj)
{
 	Device *d = getHandle<Device>(env, obj);
 	size_t val = d->MaxWorkItemDimensions();
 	return (jlong) val;
}

JNIEXPORT jobject JNICALL Java_ca_uwaterloo_JCLCudaAPI_Device_maxWorkItemSizes
  (JNIEnv *env, jobject obj)
{
	Device *d = getHandle<Device>(env, obj);
	vector<size_t> v1 = d->MaxWorkItemSizes();
	vector<long> v2;
	for (int i = 0; i < v1.size(); ++i)
		v2.push_back((long)v1[i]);
 	jlongArray arr = env->NewLongArray(v2.size());
 	env->SetLongArrayRegion(arr, 0, v2.size(), &v2[0]);
 	return arr;
}

JNIEXPORT jlong JNICALL Java_ca_uwaterloo_JCLCudaAPI_Device_localMemSize
  (JNIEnv *env, jobject obj)
{
 	Device *d = getHandle<Device>(env, obj);
 	size_t val = d->LocalMemSize();
 	return (jlong) val;
}

JNIEXPORT jstring JNICALL Java_ca_uwaterloo_JCLCudaAPI_Device_capabilities
  (JNIEnv *env, jobject obj)
{
 	Device *d = getHandle<Device>(env, obj);
	string str = d->Capabilities();
	jstring jstr = env->NewStringUTF(str.c_str());
	return jstr;
}

JNIEXPORT jlong JNICALL Java_ca_uwaterloo_JCLCudaAPI_Device_coreClock
  (JNIEnv *env, jobject obj)
{
 	Device *d = getHandle<Device>(env, obj);
 	size_t val = d->CoreClock();
 	return (jlong) val;
}

JNIEXPORT jlong JNICALL Java_ca_uwaterloo_JCLCudaAPI_Device_computeUnits
  (JNIEnv *env, jobject obj)
{
 	Device *d = getHandle<Device>(env, obj);
 	size_t val = d->ComputeUnits();
 	return (jlong) val;
}

JNIEXPORT jlong JNICALL Java_ca_uwaterloo_JCLCudaAPI_Device_memorySize
  (JNIEnv *env, jobject obj)
{
 	Device *d = getHandle<Device>(env, obj);
 	size_t val = d->MemorySize();
 	return (jlong) val;
}

JNIEXPORT jlong JNICALL Java_ca_uwaterloo_JCLCudaAPI_Device_maxAllocSize
  (JNIEnv *env, jobject obj)
{
 	Device *d = getHandle<Device>(env, obj);
 	size_t val = d->MaxAllocSize();
 	return (jlong) val;
}

JNIEXPORT jlong JNICALL Java_ca_uwaterloo_JCLCudaAPI_Device_memoryClock
  (JNIEnv *env, jobject obj)
{
 	Device *d = getHandle<Device>(env, obj);
 	size_t val = d->MemoryClock();
 	return (jlong) val;
}

JNIEXPORT jlong JNICALL Java_ca_uwaterloo_JCLCudaAPI_Device_memoryBusWidth
  (JNIEnv *env, jobject obj)
{
 	Device *d = getHandle<Device>(env, obj);
 	size_t val = d->MemoryBusWidth();
 	return (jlong) val;
}

JNIEXPORT jboolean JNICALL Java_ca_uwaterloo_JCLCudaAPI_Device_isLocalMemoryValid
  (JNIEnv *env, jobject obj, jlong localMemUsage)
{
 	Device *d = getHandle<Device>(env, obj);
 	bool val = d->IsLocalMemoryValid((size_t)localMemUsage);
 	return (jboolean) val;
}

JNIEXPORT jboolean JNICALL Java_ca_uwaterloo_JCLCudaAPI_Device_isThreadConfigValid
  (JNIEnv *env, jobject obj, jobject local)
{
 	vector<size_t> elems = listToSizetVector(env, local);
 	Device *d = getHandle<Device>(env, obj);
 	bool val = d->IsThreadConfigValid(elems);
 	return (jboolean) val;
}

/********************************************************************************/
// CudaContext
/********************************************************************************/
JNIEXPORT void JNICALL Java_ca_uwaterloo_JCLCudaAPI_Context_init
  (JNIEnv *env, jobject obj, jobject device)
{
	Device *d = getHandle<Device>(env, device);
	Context *c = new Context(*d);
	setHandle(env, obj, c);
}
/********************************************************************************/
// CudaProgram
/********************************************************************************/
JNIEXPORT void JNICALL Java_ca_uwaterloo_JCLCudaAPI_Program_init
  (JNIEnv *env, jobject obj, jobject context, jstring source)
{
	string str = jstringToString(env, source);
	Context *c = getHandle<Context>(env, context);
	Program *p = new Program(*c, str);
	setHandle(env, obj, p);
}

JNIEXPORT jint JNICALL Java_ca_uwaterloo_JCLCudaAPI_Program_build_1native
  (JNIEnv *env, jobject obj, jobject device, jobject list_options)
{
	Device *d = getHandle<Device>(env, device);
	Program *p = getHandle<Program>(env, obj);
	vector<string> elems = listToStringVector(env, list_options);
	BuildStatus status = p->Build(*d, elems);

	if (status == BuildStatus::kSuccess)
		return (jint)0;
	else if (status == BuildStatus::kError)
		return (jint)1;
	else
		return (jint)2;
}

JNIEXPORT jstring JNICALL Java_ca_uwaterloo_JCLCudaAPI_Program_getBuildInfo
  (JNIEnv *env, jobject obj, jobject device)
{
	Device *d = getHandle<Device>(env, device);
	Program *p = getHandle<Program>(env, obj);
	string str = p->GetBuildInfo(*d);
	jstring jstr = env->NewStringUTF(str.c_str());
	return jstr;
}

JNIEXPORT jstring JNICALL Java_ca_uwaterloo_JCLCudaAPI_Program_getIR
  (JNIEnv *env, jobject obj)
{
	Program *p = getHandle<Program>(env, obj);
	string str = p->GetIR();
	jstring jstr = env->NewStringUTF(str.c_str());
	return jstr;
}

/********************************************************************************/
// CudaQueue
/********************************************************************************/
JNIEXPORT void JNICALL Java_ca_uwaterloo_JCLCudaAPI_Queue_init
  (JNIEnv *env, jobject obj, jobject context, jobject device)
{
	Context *c = getHandle<Context>(env, context);
	Device *d = getHandle<Device>(env, device);
	Queue *q = new Queue(*c, *d);
	setHandle(env, obj, q);
}

JNIEXPORT void JNICALL Java_ca_uwaterloo_JCLCudaAPI_Queue_finish__Lca_uwaterloo_JCLCudaAPI_Event_2
  (JNIEnv *env, jobject obj, jobject event)
{
	Queue *q = getHandle<Queue>(env, obj);
	Event *e = getHandle<Event>(env, event);
	q->Finish(*e);
}

JNIEXPORT void JNICALL Java_ca_uwaterloo_JCLCudaAPI_Queue_finish__
  (JNIEnv *env, jobject obj)
{
	Queue *q = getHandle<Queue>(env, obj);
	q->Finish();
}

JNIEXPORT jobject JNICALL Java_ca_uwaterloo_JCLCudaAPI_Queue_getContext
  (JNIEnv *env, jobject obj)
{
	Queue *q = getHandle<Queue>(env, obj);
	// TODO
	throw new runtime_error("Unsupported function call.");
}

JNIEXPORT jobject JNICALL Java_ca_uwaterloo_JCLCudaAPI_Queue_getDevice
  (JNIEnv *env, jobject obj)
{
	Queue *q = getHandle<Queue>(env, obj);
	// TODO
	throw new runtime_error("Unsupported function call.");
}

/********************************************************************************/
// CudaBufferHost
/********************************************************************************/
JNIEXPORT void JNICALL Java_ca_uwaterloo_JCLCudaAPI_BufferHost_init
  (JNIEnv *env, jobject obj, jobject context, jlong size)
{
	Context *c = getHandle<Context>(env, context);
	BufferHost<unsigned char> *buf = new BufferHost<unsigned char>(*c, (size_t)size);
	setHandle(env, obj, buf);
}

JNIEXPORT jlong JNICALL Java_ca_uwaterloo_JCLCudaAPI_BufferHost_getSize
  (JNIEnv *env, jobject obj)
{
	BufferHost<unsigned char> *buf = getHandle<BufferHost<unsigned char>>(env, obj);
	size_t size = buf->GetSize();
	return (jlong)size;
}

JNIEXPORT jlong JNICALL Java_ca_uwaterloo_JCLCudaAPI_BufferHost_size
  (JNIEnv *env, jobject obj)
{
	BufferHost<unsigned char> *buf = getHandle<BufferHost<unsigned char>>(env, obj);
	size_t size = buf->size();
	return (jlong)size;
}

JNIEXPORT jobject JNICALL Java_ca_uwaterloo_JCLCudaAPI_BufferHost_getByteBuffer
  (JNIEnv *env, jobject obj)
{
	BufferHost<unsigned char> *buf = getHandle<BufferHost<unsigned char>>(env, obj);
	void *ptr = (void*)buf->data();
	float *d = (float*) buf->data();
	jobject byte_buffer = env->NewDirectByteBuffer(ptr, buf->size());
	return byte_buffer;
}

JNIEXPORT jlong JNICALL Java_ca_uwaterloo_JCLCudaAPI_BufferHost_getNativePointerAddress
  (JNIEnv *env, jobject obj)
{
	BufferHost<unsigned char> *buf = getHandle<BufferHost<unsigned char>>(env, obj);
	void *ptr = (void*)buf->data();
	return (jlong)ptr;
}

/********************************************************************************/
// CudaBuffer
/********************************************************************************/
JNIEXPORT void JNICALL Java_ca_uwaterloo_JCLCudaAPI_Buffer_init
  (JNIEnv *env, jobject obj, jobject context, jlong size)
{
	Context *c = getHandle<Context>(env, context);
	Buffer<unsigned char> *buf = new Buffer<unsigned char>(*c, (size_t)size);
	setHandle(env, obj, buf);
}

JNIEXPORT void JNICALL Java_ca_uwaterloo_JCLCudaAPI_Buffer_readAsync
  (JNIEnv *env, jobject obj, jobject queue, jlong size, jobject host, jlong offset)
{
	Queue *q = getHandle<Queue>(env, queue);
	BufferHost<unsigned char> *h_buf = getHandle<BufferHost<unsigned char>>(env, host);
	Buffer<unsigned char> *b = getHandle<Buffer<unsigned char>>(env, obj);
	b->ReadAsync(*q, (size_t)size, *h_buf, (size_t)offset);
}

JNIEXPORT void JNICALL Java_ca_uwaterloo_JCLCudaAPI_Buffer_read
  (JNIEnv *env, jobject obj, jobject queue, jlong size, jobject host, jlong offset)
{
	Queue *q = getHandle<Queue>(env, queue);
	BufferHost<unsigned char> *h_buf = getHandle<BufferHost<unsigned char>>(env, host);
	Buffer<unsigned char> *b = getHandle<Buffer<unsigned char>>(env, obj);
	b->Read(*q, (size_t)size, *h_buf, (size_t)offset);
}

JNIEXPORT void JNICALL Java_ca_uwaterloo_JCLCudaAPI_Buffer_writeAsync
  (JNIEnv *env, jobject obj, jobject queue, jlong size, jobject host, jlong offset)
{
	Queue *q = getHandle<Queue>(env, queue);
	BufferHost<unsigned char> *h_buf = getHandle<BufferHost<unsigned char>>(env, host);
	Buffer<unsigned char> *b = getHandle<Buffer<unsigned char>>(env, obj);
	b->WriteAsync(*q, (size_t)size, *h_buf, (size_t)offset);
}

JNIEXPORT void JNICALL Java_ca_uwaterloo_JCLCudaAPI_Buffer_write
  (JNIEnv *env, jobject obj, jobject queue, jlong size, jobject host, jlong offset)
{
	Queue *q = getHandle<Queue>(env, queue);
	BufferHost<unsigned char> *h_buf = getHandle<BufferHost<unsigned char>>(env, host);
	Buffer<unsigned char> *b = getHandle<Buffer<unsigned char>>(env, obj);
	b->Write(*q, (size_t)size, h_buf->data(), (size_t)offset);
}

JNIEXPORT void JNICALL Java_ca_uwaterloo_JCLCudaAPI_Buffer_copyToAsync
  (JNIEnv *env, jobject obj, jobject queue, jlong size, jobject dst)
{
	Queue *q = getHandle<Queue>(env, queue);
	Buffer<unsigned char> *h_buf = getHandle<Buffer<unsigned char>>(env, dst);
	Buffer<unsigned char> *b = getHandle<Buffer<unsigned char>>(env, obj);
	b->CopyToAsync(*q, (size_t)size, *h_buf);
}

JNIEXPORT void JNICALL Java_ca_uwaterloo_JCLCudaAPI_Buffer_copyTo
  (JNIEnv *env, jobject obj, jobject queue, jlong size, jobject dst)
{
	Queue *q = getHandle<Queue>(env, queue);
	Buffer<unsigned char> *h_buf = getHandle<Buffer<unsigned char>>(env, dst);
	Buffer<unsigned char> *b = getHandle<Buffer<unsigned char>>(env, obj);
	b->CopyTo(*q, (size_t)size, *h_buf);
}

JNIEXPORT jlong JNICALL Java_ca_uwaterloo_JCLCudaAPI_Buffer_getSize
  (JNIEnv *env, jobject obj)
{
	Buffer<unsigned char> *b = getHandle<Buffer<unsigned char>>(env, obj);
	return (jlong)b->GetSize();
}

/********************************************************************************/
// CudaKernel
/********************************************************************************/
JNIEXPORT void JNICALL Java_ca_uwaterloo_JCLCudaAPI_Kernel_init
  (JNIEnv *env, jobject obj, jobject program, jstring name)
{
	Program *p = getHandle<Program>(env, program);
	string str = jstringToString(env, name);
	Kernel *k = new Kernel(*p, str);
	setHandle(env, obj, k);
}

JNIEXPORT void JNICALL Java_ca_uwaterloo_JCLCudaAPI_Kernel_setArgument__JLca_uwaterloo_JCLCudaAPI_Buffer_2
  (JNIEnv *env, jobject obj, jlong index, jobject buffer)
{
	Buffer<unsigned char> *b = getHandle<Buffer<unsigned char>>(env, buffer);
	Kernel *k = getHandle<Kernel>(env, obj);
	k->SetArgument((size_t)index, *b);
}

JNIEXPORT void JNICALL Java_ca_uwaterloo_JCLCudaAPI_Kernel_setArgument__JI
  (JNIEnv *env, jobject obj, jlong index, jint val)
{
	Kernel *k = getHandle<Kernel>(env, obj);
	k->SetArgument((size_t)index, (int)val);
}

JNIEXPORT void JNICALL Java_ca_uwaterloo_JCLCudaAPI_Kernel_setArgument__JF
  (JNIEnv *env, jobject obj, jlong index, jfloat val)
{
	Kernel *k = getHandle<Kernel>(env, obj);
	k->SetArgument((size_t)index, (float)val);
}

JNIEXPORT void JNICALL Java_ca_uwaterloo_JCLCudaAPI_Kernel_setArgument__JD
  (JNIEnv *env, jobject obj, jlong index, jdouble val)
{
	Kernel *k = getHandle<Kernel>(env, obj);
	k->SetArgument((size_t)index, (double)val);
}

JNIEXPORT jlong JNICALL Java_ca_uwaterloo_JCLCudaAPI_Kernel_localMemUsage
  (JNIEnv *env, jobject obj, jobject device)
{
	Device *d = getHandle<Device>(env, device);
	Kernel *k = getHandle<Kernel>(env, obj);
	return (jlong)k->LocalMemUsage(*d);
}

JNIEXPORT void JNICALL Java_ca_uwaterloo_JCLCudaAPI_Kernel_launch__Lca_uwaterloo_JCLCudaAPI_Queue_2_3J_3JLca_uwaterloo_JCLCudaAPI_Event_2
  (JNIEnv *env, jobject obj, jobject queue, jlongArray global, jlongArray local, jobject event)
{
	Queue *q = getHandle<Queue>(env, queue);
	Event *e = getHandle<Event>(env, event);
	vector<size_t> vGlobal = toSizetRange(env, global);
	vector<size_t> vLocal = toSizetRange(env, local);
	Kernel *k = getHandle<Kernel>(env, obj);
	k->Launch(*q, vGlobal, vLocal, *e);
}

JNIEXPORT void JNICALL Java_ca_uwaterloo_JCLCudaAPI_Kernel_launch__Lca_uwaterloo_JCLCudaAPI_Queue_2_3J_3JLca_uwaterloo_JCLCudaAPI_Event_2Ljava_util_List_2
  (JNIEnv *env, jobject obj, jobject queue, jlongArray global, jlongArray local, jobject event, jobject list_wait_for_events)
{
	// TODO
}
