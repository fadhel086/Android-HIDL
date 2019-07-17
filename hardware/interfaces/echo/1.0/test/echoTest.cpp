#include <android/hardware/echo/1.0/IEcho.h>
#include <hidl/Status.h>
#include <hidl/LegacySupport.h>
#include <utils/misc.h>
#include <hidl/HidlSupport.h>
#include <iostream>
#include <cstdlib>
#include <string>

using ::android::sp;
using android::hardware::echo::V1_0::IEcho;
using android::hardware::hidl_string;

int main(int argc, char *argv[]) {

  std::string str;
  if (argc < 2) {
    // Exit the application from here
    std::cout << "USAGE ./echo_client <string to echo>\n";
      exit(0);  
  } else {
    //Get the Text from user to be echoed ...
    int i = 1;
    while(argv[i]) {
      str += argv[i];
      str += " ";
      ++i;
    }
  }

  android::sp<IEcho> ser = IEcho::getService();
  if (ser == nullptr) {
    std::cout << "Failed to get echo service\n";
    exit(-1);
  }

  ser->echo(str, [&](hidl_string result) {
      std::cout << "ECHO_HAL:" << result << std::endl;
    });
  

  return 0;

}
