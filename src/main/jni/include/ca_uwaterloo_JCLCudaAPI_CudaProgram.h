/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class ca_uwaterloo_JCLCudaAPI_CudaProgram */

#ifndef _Included_ca_uwaterloo_JCLCudaAPI_CudaProgram
#define _Included_ca_uwaterloo_JCLCudaAPI_CudaProgram
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     ca_uwaterloo_JCLCudaAPI_CudaProgram
 * Method:    init
 * Signature: (Lca/uwaterloo/JCLCudaAPI/CudaContext;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_ca_uwaterloo_JCLCudaAPI_CudaProgram_init
  (JNIEnv *, jobject, jobject, jstring);

/*
 * Class:     ca_uwaterloo_JCLCudaAPI_CudaProgram
 * Method:    build
 * Signature: (Lca/uwaterloo/JCLCudaAPI/Device;Ljava/util/List;)Lca/uwaterloo/JCLCudaAPI/Program/BuildStatus;
 */
JNIEXPORT jobject JNICALL Java_ca_uwaterloo_JCLCudaAPI_CudaProgram_build
  (JNIEnv *, jobject, jobject, jobject);

/*
 * Class:     ca_uwaterloo_JCLCudaAPI_CudaProgram
 * Method:    getBuildInfo
 * Signature: (Lca/uwaterloo/JCLCudaAPI/Device;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_ca_uwaterloo_JCLCudaAPI_CudaProgram_getBuildInfo
  (JNIEnv *, jobject, jobject);

/*
 * Class:     ca_uwaterloo_JCLCudaAPI_CudaProgram
 * Method:    getIR
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_ca_uwaterloo_JCLCudaAPI_CudaProgram_getIR
  (JNIEnv *, jobject);

#ifdef __cplusplus
}
#endif
#endif
