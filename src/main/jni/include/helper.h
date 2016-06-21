#ifndef HELPER_H_
#define HELPER_H_

#include <jni.h>
#include <vector>
#include <stdexcept>

using namespace std;

typedef std::vector<size_t> IntRange;
typedef std::vector<std::string> StringRange;

typedef vector<string> StringVec;
typedef vector<int> IntVec;
typedef vector<size_t> SizetVec;

inline std::string jstringToString(JNIEnv *env, const jstring &input) {
  const char *c_input = env->GetStringUTFChars(input, 0);
  const std::string output(c_input);
  env->ReleaseStringUTFChars(input, c_input);
  return output;
}

inline IntRange toIntRange(JNIEnv *env, jintArray array) {
  IntRange range;
  jsize length = env->GetArrayLength(array);
  int *tmp = env->GetIntArrayElements(array, nullptr);
  for (int i = 0; i < length; ++i) {
    range.push_back((size_t) tmp[i]);
  }
  return range;
}

inline StringRange toStringRange(JNIEnv *env, jobjectArray array) {
  StringRange range;
  jsize length = env->GetArrayLength(array);
  for (int i = 0; i < length; ++i) {
    jobject tmp = env->GetObjectArrayElement(array, (jsize)i);
    range.push_back(jstringToString(env, (jstring)tmp));
  }
  return range;
}

inline StringVec listToStringVector(JNIEnv *env, jobject jlist) {
  // retrieve the size and the get method for List
  jclass cList = env->FindClass("java/util/List");
  jmethodID mSize = env->GetMethodID(cList, "size", "()I");
  jmethodID mGet = env->GetMethodID(cList, "get", "(I)Ljava/lang/Object;");
  if (mSize == NULL || mGet == NULL) {
    throw new std::runtime_error("JNI: Failed to obtain method ID.");
  }

  // walk through and fill the vector
  jint size = env->CallIntMethod(jlist, mSize);
  StringVec vec;
  for (jint i = 0; i < size; ++i) {
    jstring strObj = (jstring) env->CallObjectMethod(jlist, mGet, i);
    const char *chr = env->GetStringUTFChars(strObj, JNI_FALSE);
    vec.push_back(chr);
    env->ReleaseStringUTFChars(strObj, chr);
  }

  return vec;
}

inline IntVec listToIntVector(JNIEnv *env, jobject jlist) {
  // retrieve the size and the get method for List
  jclass cList = env->FindClass("java/util/List");
  jmethodID mSize = env->GetMethodID(cList, "size", "()I");
  jmethodID mGet = env->GetMethodID(cList, "get", "(I)Ljava/lang/Object;");
  if (mSize == NULL || mGet == NULL) {
    throw new std::runtime_error("JNI: Failed to obtain method ID.");
  }

  // retrieve the intValue method
  jclass cInteger = env->FindClass("java/lang/Integer");
  jmethodID mIntValue = env->GetMethodID(cInteger, "intValue", "()I");

  // walk through and fill the vector
  jint size = env->CallIntMethod(jlist, mSize);
  IntVec vec;
  for (jint i = 0; i < size; ++i) {
    jobject obj = env->CallObjectMethod(jlist, mGet, i);
    jint jelem = env->CallIntMethod(obj, mIntValue);
    vec.push_back((int) jelem);
  }

  return vec;
}

inline SizetVec listToSizetVector(JNIEnv *env, jobject jlist) {
  // retrieve the size and the get method for List
  jclass cList = env->FindClass("java/util/List");
  jmethodID mSize = env->GetMethodID(cList, "size", "()I");
  jmethodID mGet = env->GetMethodID(cList, "get", "(I)Ljava/lang/Object;");
  if (mSize == NULL || mGet == NULL) {
    throw new std::runtime_error("JNI: Failed to obtain method ID.");
  }

  // retrieve the intValue method
  jclass cInteger = env->FindClass("java/lang/Integer");
  jmethodID mIntValue = env->GetMethodID(cInteger, "intValue", "()I");

  // walk through and fill the vector
  jint size = env->CallIntMethod(jlist, mSize);
  SizetVec vec;
  for (jint i = 0; i < size; ++i) {
    jobject obj = env->CallObjectMethod(jlist, mGet, i);
    jint jelem = env->CallIntMethod(obj, mIntValue);
    vec.push_back((size_t) jelem);
  }

  return vec;
}

#endif /* HELPER_H_ */
