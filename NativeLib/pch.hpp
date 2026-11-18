#include <jni.h>
#include <errno.h>

#include <string>
#include <unistd.h>
#include <sys/resource.h>

#include <android/log.h>

// maybe add a debug if to enable or disable these?
#define TAG "MobileBlox"

#define LOGD(...) ((void)__android_log_print(ANDROID_LOG_DEBUG, TAG, __VA_ARGS__))
#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, TAG, __VA_ARGS__))
#define LOGE(...) ((void)__android_log_print(ANDROID_LOG_ERROR, TAG, __VA_ARGS__))
#define LOGW(...) ((void)__android_log_print(ANDROID_LOG_WARN, TAG, __VA_ARGS__))

// easier access
namespace app_config
{
    const std::string app_name = "MobileBlox";
    const std::string chunk_name = "@MB";
    const std::string app_version = "2.0.0";
    const std::string roblox_version = "2.603.563"; // lets try to be consistent here
}