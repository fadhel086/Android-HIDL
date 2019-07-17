#ifndef ANDROID_HARDWARE_ECHO_V1_0_ECHO_H
#define ANDROID_HARDWARE_ECHO_V1_0_ECHO_H

#include <android/hardware/echo/1.0/IEcho.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>

namespace android {
namespace hardware {
namespace echo {
namespace V1_0 {
namespace implementation {

using ::android::hardware::hidl_array;
using ::android::hardware::hidl_memory;
using ::android::hardware::hidl_string;
using ::android::hardware::hidl_vec;
using ::android::hardware::Return;
using ::android::hardware::Void;
using ::android::sp;

struct Echo : public IEcho {
    // Methods from ::android::hardware::echo::V1_0::IEcho follow.
    Return<void> echo(const hidl_string& word, echo_cb _hidl_cb) override;

    // Methods from ::android::hidl::base::V1_0::IBase follow.

};

// FIXME: most likely delete, this is only for passthrough implementations
extern "C" IEcho* HIDL_FETCH_IEcho(const char* name);

}  // namespace implementation
}  // namespace V1_0
}  // namespace echo
}  // namespace hardware
}  // namespace android

#endif  // ANDROID_HARDWARE_ECHO_V1_0_ECHO_H
