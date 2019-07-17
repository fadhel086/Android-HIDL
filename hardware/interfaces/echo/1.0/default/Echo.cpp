#include "Echo.h"

namespace android {
namespace hardware {
namespace echo {
namespace V1_0 {
namespace implementation {

// Methods from ::android::hardware::echo::V1_0::IEcho follow.
Return<void> Echo::echo(const hidl_string& word, echo_cb _hidl_cb) {

  // Reply back what u get.. 
     _hidl_cb(word);
  
    return Void();
}


// Methods from ::android::hidl::base::V1_0::IBase follow.

IEcho* HIDL_FETCH_IEcho(const char* /* name */) {
    return new Echo();
}
//
}  // namespace implementation
}  // namespace V1_0
}  // namespace echo
}  // namespace hardware
}  // namespace android
