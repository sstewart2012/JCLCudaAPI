#include <iostream>
#include <string>
#include <vector>
#include "handle.h"
#include "helper.h"
#include "cupp11.h"
#include "ca_uwaterloo_JCLCudaAPI_CudaEvent.h"
#include "ca_uwaterloo_JCLCudaAPI_CudaPlatform.h"
#include "ca_uwaterloo_JCLCudaAPI_CudaDevice.h"
#include "ca_uwaterloo_JCLCudaAPI_CudaContext.h"
#include "ca_uwaterloo_JCLCudaAPI_CudaProgram.h"
#include "ca_uwaterloo_JCLCudaAPI_CudaQueue.h"

using namespace std;
using namespace CLCudaAPI;

/********************************************************************************/
// CudaEvent
/********************************************************************************/
JNIEXPORT void JNICALL Java_ca_uwaterloo_JCLCudaAPI_CudaEvent_init
  (JNIEnv *env, jobject obj)
{
	Event *e = new Event();
	setHandle(env, obj, e);
}

JNIEXPORT jfloat JNICALL Java_ca_uwaterloo_JCLCudaAPI_CudaEvent_getElapsedTime
  (JNIEnv *env, jobject obj)
{
	Event *e = getHandle<Event>(env, obj);
	float time = e->GetElapsedTime();
	return (jfloat) time;
}

JNIEXPORT void JNICALL Java_ca_uwaterloo_JCLCudaAPI_CudaEvent_waitForCompletion
  (JNIEnv *env, jobject obj)
{
	Event *e = getHandle<Event>(env, obj);
	e->WaitForCompletion();
}

/********************************************************************************/
// CudaPlatform
/********************************************************************************/
JNIEXPORT void JNICALL Java_ca_uwaterloo_JCLCudaAPI_CudaPlatform_init
  (JNIEnv *env, jobject obj, jlong platform_id)
{
	Platform *p = new Platform((size_t)platform_id);
	setHandle(env, obj, p);
}

JNIEXPORT jint JNICALL Java_ca_uwaterloo_JCLCudaAPI_CudaPlatform_numDevices
  (JNIEnv *env, jobject obj)
{
	Platform *p = getHandle<Platform>(env, obj);
}

/********************************************************************************/
// CudaDevice
/********************************************************************************/
JNIEXPORT void JNICALL Java_ca_uwaterloo_JCLCudaAPI_CudaDevice_init
  (JNIEnv *env, jobject obj, jobject platform, jint device_id)
{
	Platform *p = getHandle<Platform>(env, platform);
	Device *d = new Device(*p, (size_t)device_id);
	setHandle(env, obj, d);
}

JNIEXPORT jstring JNICALL Java_ca_uwaterloo_JCLCudaAPI_CudaDevice_version
  (JNIEnv *env, jobject obj)
{
	Device *d = getHandle<Device>(env, obj);
	std::string str = d->Version();
	jstring jstr = env->NewStringUTF(str.c_str());
	return jstr;
}

JNIEXPORT jstring JNICALL Java_ca_uwaterloo_JCLCudaAPI_CudaDevice_vendor
  (JNIEnv *env, jobject obj)
{
	Device *d = getHandle<Device>(env, obj);
	std::string str = d->Vendor();
	jstring jstr = env->NewStringUTF(str.c_str());
	return jstr;
}

JNIEXPORT jstring JNICALL Java_ca_uwaterloo_JCLCudaAPI_CudaDevice_name
  (JNIEnv *env, jobject obj)
{
	Device *d = getHandle<Device>(env, obj);
	std::string str = d->Name();
	jstring jstr = env->NewStringUTF(str.c_str());
	return jstr;
}

JNIEXPORT jstring JNICALL Java_ca_uwaterloo_JCLCudaAPI_CudaDevice_type
  (JNIEnv *env, jobject obj)
{
 	Device *d = getHandle<Device>(env, obj);
	std::string str = d->Type();
	jstring jstr = env->NewStringUTF(str.c_str());
	return jstr;
}

JNIEXPORT jlong JNICALL Java_ca_uwaterloo_JCLCudaAPI_CudaDevice_maxWorkGroupSize
  (JNIEnv *env, jobject obj)
{
 	Device *d = getHandle<Device>(env, obj);
 	size_t val = d->MaxWorkGroupSize();
 	return (jlong) val;
}

JNIEXPORT jlong JNICALL Java_ca_uwaterloo_JCLCudaAPI_CudaDevice_maxWorkItemDimensions
  (JNIEnv *env, jobject obj)
{
 	Device *d = getHandle<Device>(env, obj);
 	size_t val = d->MaxWorkItemDimensions();
 	return (jlong) val;
}

JNIEXPORT jobject JNICALL Java_ca_uwaterloo_JCLCudaAPI_CudaDevice_maxWorkItemSizes
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

JNIEXPORT jlong JNICALL Java_ca_uwaterloo_JCLCudaAPI_CudaDevice_localMemSize
  (JNIEnv *env, jobject obj)
{
 	Device *d = getHandle<Device>(env, obj);
 	size_t val = d->LocalMemSize();
 	return (jlong) val;
}

JNIEXPORT jstring JNICALL Java_ca_uwaterloo_JCLCudaAPI_CudaDevice_capabilities
  (JNIEnv *env, jobject obj)
{
 	Device *d = getHandle<Device>(env, obj);
	string str = d->Capabilities();
	jstring jstr = env->NewStringUTF(str.c_str());
	return jstr;
}

JNIEXPORT jlong JNICALL Java_ca_uwaterloo_JCLCudaAPI_CudaDevice_coreClock
  (JNIEnv *env, jobject obj)
{
 	Device *d = getHandle<Device>(env, obj);
 	size_t val = d->CoreClock();
 	return (jlong) val;
}

JNIEXPORT jlong JNICALL Java_ca_uwaterloo_JCLCudaAPI_CudaDevice_computeUnits
  (JNIEnv *env, jobject obj)
{
 	Device *d = getHandle<Device>(env, obj);
 	size_t val = d->ComputeUnits();
 	return (jlong) val;
}

JNIEXPORT jlong JNICALL Java_ca_uwaterloo_JCLCudaAPI_CudaDevice_memorySize
  (JNIEnv *env, jobject obj)
{
 	Device *d = getHandle<Device>(env, obj);
 	size_t val = d->MemorySize();
 	return (jlong) val;
}

JNIEXPORT jlong JNICALL Java_ca_uwaterloo_JCLCudaAPI_CudaDevice_maxAllocSize
  (JNIEnv *env, jobject obj)
{
 	Device *d = getHandle<Device>(env, obj);
 	size_t val = d->MaxAllocSize();
 	return (jlong) val;
}

JNIEXPORT jlong JNICALL Java_ca_uwaterloo_JCLCudaAPI_CudaDevice_memoryClock
  (JNIEnv *env, jobject obj)
{
 	Device *d = getHandle<Device>(env, obj);
 	size_t val = d->MemoryClock();
 	return (jlong) val;
}

JNIEXPORT jlong JNICALL Java_ca_uwaterloo_JCLCudaAPI_CudaDevice_memoryBusWidth
  (JNIEnv *env, jobject obj)
{
 	Device *d = getHandle<Device>(env, obj);
 	size_t val = d->MemoryBusWidth();
 	return (jlong) val;
}

JNIEXPORT jboolean JNICALL Java_ca_uwaterloo_JCLCudaAPI_CudaDevice_isLocalMemoryValid
  (JNIEnv *env, jobject obj, jlong localMemUsage)
{
 	Device *d = getHandle<Device>(env, obj);
 	bool val = d->IsLocalMemoryValid((size_t)localMemUsage);
 	return (jboolean) val;
}

JNIEXPORT jboolean JNICALL Java_ca_uwaterloo_JCLCudaAPI_CudaDevice_isThreadConfigValid
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
JNIEXPORT void JNICALL Java_ca_uwaterloo_JCLCudaAPI_CudaContext_init
  (JNIEnv *env, jobject obj, jobject device)
{
	Device *d = getHandle<Device>(env, device);
	Context *c = new Context(*d);
	setHandle(env, obj, c);
}
/********************************************************************************/
// CudaProgram
/********************************************************************************/
JNIEXPORT void JNICALL Java_ca_uwaterloo_JCLCudaAPI_CudaProgram_init
  (JNIEnv *env, jobject obj, jobject context, jstring source)
{
	string str = jstringToString(env, source);
	Context *c = getHandle<Context>(env, context);
	Program *p = new Program(*c, str);
	setHandle(env, obj, p);
}

JNIEXPORT jobject JNICALL Java_ca_uwaterloo_JCLCudaAPI_CudaProgram_build
  (JNIEnv *env, jobject obj, jobject device, jobject list_options)
{
	Device *d = getHandle<Device>(env, device);
	Program *p = getHandle<Program>(env, obj);
	vector<string> elems = listToStringVector(env, list_options);
	BuildStatus status = p->Build(*d, elems);
	// TODO return build status properly
	if (status == BuildStatus::kSuccess)
		printf("Build:  Success\n");
	else if (status == BuildStatus::kError)
		printf("Build:  Error\n");
	else
		printf("Build:  Invalid\n");
}

JNIEXPORT jstring JNICALL Java_ca_uwaterloo_JCLCudaAPI_CudaProgram_getBuildInfo
  (JNIEnv *env, jobject obj, jobject device)
{
	Device *d = getHandle<Device>(env, device);
	Program *p = getHandle<Program>(env, obj);
	string str = p->GetBuildInfo(*d);
	jstring jstr = env->NewStringUTF(str.c_str());
	return jstr;
}

JNIEXPORT jstring JNICALL Java_ca_uwaterloo_JCLCudaAPI_CudaProgram_getIR
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
JNIEXPORT void JNICALL Java_ca_uwaterloo_JCLCudaAPI_CudaQueue_init
  (JNIEnv *env, jobject obj, jobject context, jobject device)
{
	Context *c = getHandle<Context>(env, context);
	Device *d = getHandle<Device>(env, device);
	Queue *q = new Queue(*c, *d);
	setHandle(env, obj, q);
}

JNIEXPORT void JNICALL Java_ca_uwaterloo_JCLCudaAPI_CudaQueue_finish__Lca_uwaterloo_JCLCudaAPI_Event_2
  (JNIEnv *env, jobject obj, jobject event)
{
	Queue *q = getHandle<Queue>(env, obj);
	Event *e = getHandle<Event>(env, event);
	q->Finish(*e);
}

JNIEXPORT void JNICALL Java_ca_uwaterloo_JCLCudaAPI_CudaQueue_finish__
  (JNIEnv *env, jobject obj)
{
	Queue *q = getHandle<Queue>(env, obj);
	q->Finish();
}

JNIEXPORT jobject JNICALL Java_ca_uwaterloo_JCLCudaAPI_CudaQueue_getContext
  (JNIEnv *env, jobject obj)
{
	Queue *q = getHandle<Queue>(env, obj);
	// TODO
	throw new runtime_error("Unsupported function call.");
}

JNIEXPORT jobject JNICALL Java_ca_uwaterloo_JCLCudaAPI_CudaQueue_getDevice
  (JNIEnv *env, jobject obj)
{
	Queue *q = getHandle<Queue>(env, obj);
	// TODO
	throw new runtime_error("Unsupported function call.");
}