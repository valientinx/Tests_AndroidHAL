// Minimal example of a client using the AIDL interface (pseudo-code, for illustration)
#include <binder/IServiceManager.h>
#include <binder/IBinder.h>
#include <binder/Parcel.h>
#include <utils/String16.h>
#include <iostream>

using namespace android;

int main() {
    sp<IServiceManager> sm = defaultServiceManager();
    sp<IBinder> binder = sm->getService(String16("jokehal"));
    if (binder == nullptr) {
        std::cerr << "JokeHal service not found!" << std::endl;
        return 1;
    }
    Parcel data, reply;
    binder->transact(IBinder::FIRST_CALL_TRANSACTION, data, &reply);
    String16 joke = reply.readString16();
    std::wcout << L"Joke: " << reinterpret_cast<const wchar_t*>(joke.string()) << std::endl;
    return 0;
}
