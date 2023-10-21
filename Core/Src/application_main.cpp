#include "data_store.h"
#include "cmsis_os.h"


#ifdef __cplusplus
extern "C" {
#endif

void application_main(void *arg)
{
    int rpm=1, rpmstore;
    

while (true) {
    while (rpmstore<10) {
        rpmstore=++rpm;

        osDelay(500);

        data_store::instance()->set_rpm(rpmstore);
    }
    
    rpm = 1;
    rpmstore = 1;
    
    data_store::instance()->set_rpm(rpmstore);
}
}

#ifdef __cplusplus
}
#endif