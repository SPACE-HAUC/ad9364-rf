#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <signal.h>
#include <stdio.h>

#ifdef __APPLE__
#include <iio/iio.h>
#else
#include <iio.h>
#endif

#include <iostream>
using namespace std ;
int main(void)
{
    static struct iio_context * ctx = NULL ;
    ctx = iio_create_default_context() ;
    unsigned int numdev = iio_context_get_devices_count(ctx) ;
    cout << "Number of devices: " << numdev << endl ;
    for (int i = 0 ; i < numdev ; i++){
        static struct iio_device * dev = iio_context_get_device(ctx, i) ;
        cout << "Device " << i << ": " << iio_device_get_name(dev) << endl ;
    }
    return 0 ;
}