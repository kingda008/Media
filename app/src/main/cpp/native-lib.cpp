#include <jni.h>
#include <string>

extern "C" JNIEXPORT jstring JNICALL
Java_com_baoge_media_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
extern "C"
JNIEXPORT jstring JNICALL
Java_com_baoge_media_MainActivity_func1(JNIEnv *env, jobject thiz) {
    /**
     * 获取java方法所在类，在这里就是MainActivity
     */
    jclass activity = env->GetObjectClass(thiz);
    /**
     * 获取java类中的属性
     */
    jfieldID txtContentID = env->GetFieldID(activity, "txtContent", "Ljava/lang/String;");
    /**
     * 修改
     */
    jstring value = env->NewStringUTF("你被native改变了");
    env->SetObjectField(thiz, txtContentID, value);

    /**
     * 获取java类中的方法
     */
    jmethodID callBackID = env->GetMethodID(activity, "callBack", "(I)V");
    /**
     * 调用java类中的方法
     * CallVoidMethod 不同的返回值要调用不同的方法，static float object等
     */
    env->CallVoidMethod(thiz, callBackID, 2);

    //仅仅是个返回值
    std::string result = "func1";

    return env->NewStringUTF(result.c_str());


}
extern "C"
JNIEXPORT jstring JNICALL
Java_com_baoge_media_MainActivity_func2(JNIEnv *env, jclass clazz) {
    // TODO: implement func2()
}