#include <thread>
#include <inttypes.h>

#include "renderer/renderer.hpp"
#include "roblox/hooks.hpp"
#include "roblox/update.hpp"
#include "utils/utils.hpp"

void sig_handler( int sig ) {
    LOGE( " [sig_handler] Caught a crash, signal: {%d}", sig );
    utils::backtrace::logcat( 30 );
    
    exit( EXIT_FAILURE );
}

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved)
{
    LOGI(" [JNI_OnLoad] JVM: %p", vm );
    
    if (vm->GetEnv(reinterpret_cast<void**>(&utils::JNI::env), JNI_VERSION_1_6) != JNI_OK) {
        LOGE(" [JNI_OnLoad] Failed to get JNIEnv.");
        return -1;
    }
    
    LOGI(" [JNI_OnLoad] JNIEnv: %p", utils::JNI::env);
    
    // ==================================== //
    
    signal( SIGSEGV, sig_handler );
    
    LOGI(" [JNI_OnLoad] Waiting for libroblox.so... ");
    
    utils::memory::wait_for_lib("libroblox.so");
    LOGI(" [JNI_OnLoad] libroblox.so Base Address -> 0x%" PRIXPTR " | Initializing runtime. ", utils::memory::find_lib("libroblox.so") );
    
    roblox::functions::init( );
    roblox::hooks::init( );
    renderer::init( );
    
    LOGI(" [JNI_OnLoad] Runtime initialized.");

    return JNI_VERSION_1_6;
}