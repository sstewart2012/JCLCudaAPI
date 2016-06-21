/**
 * Functions for managing a C++ object.
 *
 * Handy references:
 *  http://thebreakfastpost.com/2012/01/21/wrapping-a-c-library-with-jni-introduction/
 */
#ifndef handle_h
#define handle_h

// The name of the member variable of the Java class that holds a reference to the C++ object's memory address.
#define NATIVE_HANDLE "nativeHandle"

#include <jni.h>

/** Returns the jfieldID for the native handle (the Java class's reference to the C++ object). */
jfieldID getHandleField(JNIEnv *env, jobject obj) {
  jclass c = env->GetObjectClass(obj);
  return env->GetFieldID(c, NATIVE_HANDLE, "J");
}

/** Returns a pointer to the C++ object. */
template<typename T>
T *getHandle(JNIEnv *env, jobject obj) {
  jlong handle = env->GetLongField(obj, getHandleField(env, obj));
  return reinterpret_cast<T *>(handle);
}

/** Sets a pointer to the C++ object. */
template<typename T>
void setHandle(JNIEnv *env, jobject obj, T *t) {
  jlong handle = reinterpret_cast<jlong>(t);
  env->SetLongField(obj, getHandleField(env, obj), handle);
}

#endif // handle_h
