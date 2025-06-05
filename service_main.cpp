// Minimal example of a service exposing the JokeHal via Binder (pseudo-code, for illustration)
#include "joke_hal.h"
#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>
#include <binder/ProcessState.h>
#include <binder/BinderService.h>
#include <utils/Log.h>
#include <android-base/logging.h>

using namespace android;

class JokeHalService : public BinderService<JokeHalService> {
public:
    static const char* getServiceName() { return "jokehal"; }
    JokeHalService() : mHal() {}

    // Implement the AIDL interface method
    String16 getRandomJoke() {
        return String16(mHal.getRandomJoke().c_str());
    }
private:
    JokeHal mHal;
};

int main(int argc, char** argv) {
    sp<ProcessState> proc(ProcessState::self());
    sp<IServiceManager> sm = defaultServiceManager();
    JokeHalService::publishAndJoinThreadPool();
    return 0;
}
