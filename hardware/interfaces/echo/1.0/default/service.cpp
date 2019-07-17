#define LOG_TAG "android.hardware.echo@1.0-service"
#include <android/hardware/echo/1.0/IEcho.h>
#include <hidl/LegacySupport.h>

using android::hardware::echo::V1_0::IEcho;
using android::hardware::defaultPassthroughServiceImplementation;

int main() {
  return defaultPassthroughServiceImplementation<IEcho>();
}
