/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class ca_uwaterloo_JCLCudaAPI_Device */

#ifndef _Included_ca_uwaterloo_JCLCudaAPI_Device
#define _Included_ca_uwaterloo_JCLCudaAPI_Device
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     ca_uwaterloo_JCLCudaAPI_Device
 * Method:    init
 * Signature: (Lca/uwaterloo/JCLCudaAPI/Platform;I)V
 */
JNIEXPORT void JNICALL Java_ca_uwaterloo_JCLCudaAPI_Device_init
  (JNIEnv *, jobject, jobject, jint);

/*
 * Class:     ca_uwaterloo_JCLCudaAPI_Device
 * Method:    version
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_ca_uwaterloo_JCLCudaAPI_Device_version
  (JNIEnv *, jobject);

/*
 * Class:     ca_uwaterloo_JCLCudaAPI_Device
 * Method:    vendor
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_ca_uwaterloo_JCLCudaAPI_Device_vendor
  (JNIEnv *, jobject);

/*
 * Class:     ca_uwaterloo_JCLCudaAPI_Device
 * Method:    name
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_ca_uwaterloo_JCLCudaAPI_Device_name
  (JNIEnv *, jobject);

/*
 * Class:     ca_uwaterloo_JCLCudaAPI_Device
 * Method:    type
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_ca_uwaterloo_JCLCudaAPI_Device_type
  (JNIEnv *, jobject);

/*
 * Class:     ca_uwaterloo_JCLCudaAPI_Device
 * Method:    maxWorkGroupSize
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_ca_uwaterloo_JCLCudaAPI_Device_maxWorkGroupSize
  (JNIEnv *, jobject);

/*
 * Class:     ca_uwaterloo_JCLCudaAPI_Device
 * Method:    maxWorkItemDimensions
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_ca_uwaterloo_JCLCudaAPI_Device_maxWorkItemDimensions
  (JNIEnv *, jobject);

/*
 * Class:     ca_uwaterloo_JCLCudaAPI_Device
 * Method:    maxWorkItemSizes
 * Signature: ()Ljava/util/List;
 */
JNIEXPORT jobject JNICALL Java_ca_uwaterloo_JCLCudaAPI_Device_maxWorkItemSizes
  (JNIEnv *, jobject);

/*
 * Class:     ca_uwaterloo_JCLCudaAPI_Device
 * Method:    localMemSize
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_ca_uwaterloo_JCLCudaAPI_Device_localMemSize
  (JNIEnv *, jobject);

/*
 * Class:     ca_uwaterloo_JCLCudaAPI_Device
 * Method:    capabilities
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_ca_uwaterloo_JCLCudaAPI_Device_capabilities
  (JNIEnv *, jobject);

/*
 * Class:     ca_uwaterloo_JCLCudaAPI_Device
 * Method:    coreClock
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_ca_uwaterloo_JCLCudaAPI_Device_coreClock
  (JNIEnv *, jobject);

/*
 * Class:     ca_uwaterloo_JCLCudaAPI_Device
 * Method:    computeUnits
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_ca_uwaterloo_JCLCudaAPI_Device_computeUnits
  (JNIEnv *, jobject);

/*
 * Class:     ca_uwaterloo_JCLCudaAPI_Device
 * Method:    memorySize
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_ca_uwaterloo_JCLCudaAPI_Device_memorySize
  (JNIEnv *, jobject);

/*
 * Class:     ca_uwaterloo_JCLCudaAPI_Device
 * Method:    maxAllocSize
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_ca_uwaterloo_JCLCudaAPI_Device_maxAllocSize
  (JNIEnv *, jobject);

/*
 * Class:     ca_uwaterloo_JCLCudaAPI_Device
 * Method:    memoryClock
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_ca_uwaterloo_JCLCudaAPI_Device_memoryClock
  (JNIEnv *, jobject);

/*
 * Class:     ca_uwaterloo_JCLCudaAPI_Device
 * Method:    memoryBusWidth
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_ca_uwaterloo_JCLCudaAPI_Device_memoryBusWidth
  (JNIEnv *, jobject);

/*
 * Class:     ca_uwaterloo_JCLCudaAPI_Device
 * Method:    isLocalMemoryValid
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_ca_uwaterloo_JCLCudaAPI_Device_isLocalMemoryValid
  (JNIEnv *, jobject, jlong);

/*
 * Class:     ca_uwaterloo_JCLCudaAPI_Device
 * Method:    isThreadConfigValid
 * Signature: (Ljava/util/List;)Z
 */
JNIEXPORT jboolean JNICALL Java_ca_uwaterloo_JCLCudaAPI_Device_isThreadConfigValid
  (JNIEnv *, jobject, jobject);

#ifdef __cplusplus
}
#endif
#endif
