/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class ca_uwaterloo_JCLCudaAPI_Buffer */

#ifndef _Included_ca_uwaterloo_JCLCudaAPI_Buffer
#define _Included_ca_uwaterloo_JCLCudaAPI_Buffer
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     ca_uwaterloo_JCLCudaAPI_Buffer
 * Method:    init
 * Signature: (Lca/uwaterloo/JCLCudaAPI/Context;J)V
 */
JNIEXPORT void JNICALL Java_ca_uwaterloo_JCLCudaAPI_Buffer_init
  (JNIEnv *, jobject, jobject, jlong);

/*
 * Class:     ca_uwaterloo_JCLCudaAPI_Buffer
 * Method:    readAsync
 * Signature: (Lca/uwaterloo/JCLCudaAPI/Queue;JLca/uwaterloo/JCLCudaAPI/BufferHost;J)V
 */
JNIEXPORT void JNICALL Java_ca_uwaterloo_JCLCudaAPI_Buffer_readAsync
  (JNIEnv *, jobject, jobject, jlong, jobject, jlong);

/*
 * Class:     ca_uwaterloo_JCLCudaAPI_Buffer
 * Method:    read
 * Signature: (Lca/uwaterloo/JCLCudaAPI/Queue;JLca/uwaterloo/JCLCudaAPI/BufferHost;J)V
 */
JNIEXPORT void JNICALL Java_ca_uwaterloo_JCLCudaAPI_Buffer_read
  (JNIEnv *, jobject, jobject, jlong, jobject, jlong);

/*
 * Class:     ca_uwaterloo_JCLCudaAPI_Buffer
 * Method:    writeAsync
 * Signature: (Lca/uwaterloo/JCLCudaAPI/Queue;JLca/uwaterloo/JCLCudaAPI/BufferHost;J)V
 */
JNIEXPORT void JNICALL Java_ca_uwaterloo_JCLCudaAPI_Buffer_writeAsync
  (JNIEnv *, jobject, jobject, jlong, jobject, jlong);

/*
 * Class:     ca_uwaterloo_JCLCudaAPI_Buffer
 * Method:    write
 * Signature: (Lca/uwaterloo/JCLCudaAPI/Queue;JLca/uwaterloo/JCLCudaAPI/BufferHost;J)V
 */
JNIEXPORT void JNICALL Java_ca_uwaterloo_JCLCudaAPI_Buffer_write
  (JNIEnv *, jobject, jobject, jlong, jobject, jlong);

/*
 * Class:     ca_uwaterloo_JCLCudaAPI_Buffer
 * Method:    copyToAsync
 * Signature: (Lca/uwaterloo/JCLCudaAPI/Queue;JLca/uwaterloo/JCLCudaAPI/Buffer;)V
 */
JNIEXPORT void JNICALL Java_ca_uwaterloo_JCLCudaAPI_Buffer_copyToAsync
  (JNIEnv *, jobject, jobject, jlong, jobject);

/*
 * Class:     ca_uwaterloo_JCLCudaAPI_Buffer
 * Method:    copyTo
 * Signature: (Lca/uwaterloo/JCLCudaAPI/Queue;JLca/uwaterloo/JCLCudaAPI/Buffer;)V
 */
JNIEXPORT void JNICALL Java_ca_uwaterloo_JCLCudaAPI_Buffer_copyTo
  (JNIEnv *, jobject, jobject, jlong, jobject);

/*
 * Class:     ca_uwaterloo_JCLCudaAPI_Buffer
 * Method:    getSize
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_ca_uwaterloo_JCLCudaAPI_Buffer_getSize
  (JNIEnv *, jobject);

#ifdef __cplusplus
}
#endif
#endif
