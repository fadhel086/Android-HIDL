# Android-HIDL

Objective:
          Implement an "echo HIDL" layer and a test application.


Pre-requisite:

* Official Android Pie sources
* source build/envsetup.sh
* lunch aosp_x86_64-eng
* run emulator and see it's working.
* make hidl-gen to build hidl-gen tool


1) Create the Interface and interface files.

   * mkdir -p hardware/interfaces/echo/1.0
   * create the interface file IEcho.hal
   * with hal file created, hidl-gen tool can automatically create the .h and ,cpp file for us
     	  LOC=hardware/interfaces/echo/1.0/default
	  PACKAGE=android.hardware.echo@1.0
   	  hidl-gen -o $LOC -Lc++-impl -randroid.hardware:hardware/interfaces -randroid.hidl:system/libhidl/transport $PACKAGE
   * Above will create echo/1.0/default/(Echo.h, Echo.cpp)
   * Inside Echo.h, uncomment the line IEcho* HIDL_FETCH_IEcho(const char* name);
   * Inside the Echo.cpp file, uncomment the function IEcho* HIDL_FETCH_IEcho()
// comment:
     It's better to use HIDL_FETCH_*(), now. This implementation will be removed in future Android releases.

   * hidl-gen -o $LOC -Landroidbp-impl -randroid.hardware:hardware/interfaces -randroid.hidl:system/libhidl/transport $PACKAGE
   * Above will create Android.bp files inside echo/1.0/default
   * run the script, ./hardware/interfaces/update-makefiles.sh
   * Above script will create an Android.bp files in echo/1.0/
   * Create android.hardware.echo@1.0-service.rc and service.cpp file
   * Update the echo/1.0/default/Android.bp file to build binaries for the hal service.
   * mmm hardware/interfaces/echo/1.0/
   * This will build the echo module alone.

view the output inside;
out/target/product/generic_x86_64/system/lib64/android.hardware.echo@1.0.so

out/target/product/generic_x86_64/vendor/lib64/hw/android.hardware.echo@1.0-impl.so

out/target/product/generic_x86_64/vendor/etc/init/android.hardware.echo@1.0-service.rc


2)

   * Update the manifest file, to indicate passthrough or hwbinder mode. here we are implementing hwbinder method.
   * update init.te, otherwise init won't be allowed to start the echo service.
	  (ps -A won't list the service)

3)
    * Create a test application (echoTest.cpp and Android.bp file)
    * ./hardware/interfaces/update-makefiles.sh
    * mmm hardware/interfaces/echo/1.0
    * Above will load the application to out/target/product/generic_x86_64/vendor/bin/hw/echo_client

4) Build the entire sources and run the emulator

   * m
   * emulator

5) Test the application

   * lshal | grep echo; will list the echo service
   * ps -A | grep echo; will show the service is up and running
   * ./vendor/bin/hw/echo_client "MESSAGE TO BE ECHOED"
   * ECHO_HAL:MESSAGE TO BE ECHOED
     
References:

* https://www.youtube.com/watch?v=UFaWqdxBW4E
* https://www.youtube.com/watch?v=2XJAdK9XKcQ
* Android online documentation
* https://devarea.com/android-hidl-and-project-treble/#.XS6kYvzhU5k
* http://www.programmersought.com/article/1032161542/
