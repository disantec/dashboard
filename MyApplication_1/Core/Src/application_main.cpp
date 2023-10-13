#include "data_store.h"

#ifdef __cplusplus
extern "C" {
#endif

void application_main(void *arg)
{
    data_store::instance()->set_rpm(69420);
}

#ifdef __cplusplus
}
#endif