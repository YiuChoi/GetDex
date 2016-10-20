#include "substrate.h"

MSConfig(MSFilterExecutable, "/system/bin/app_process")  //MSConfig(MSFilterLibrary, "liblog.so")

static jint (*_Resources$getColor)(JNIEnv *jni, jobject _this, ...);

static jint $Resources$getColor(JNIEnv *jni, jobject _this, jint rid) {
    jint color = _Resources$getColor(jni, _this, rid);
    return color & ~0x0000ff00 | 0x00ff0000;
}

static void OnResources(JNIEnv *jni, jclass resources, void *data) {
    jmethodID method = jni->GetMethodID(resources, "getColor", "(I)I");
    if (method != NULL)
        MSJavaHookMethod(jni, resources, method,
                         &$Resources$getColor, &_Resources$getColor);
}

// this is a macro that uses __attribute__((__constructor__))
MSInitialize {
    MSJavaHookClassLoad(NULL, "android/content/res/Resources", &OnResources);
}