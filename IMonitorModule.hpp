#ifndef IMONITORMODULE_H
# define IMONITORMODULE_H
#include <sys/types.h>
#include <sys/sysctl.h>
#include <sys/utsname.h>
#include <net/route.h>
#include <net/if.h>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <mach/mach_host.h>
#include <iostream>
#include <vector>
class IMonitorModule
{
    public:
        IMonitorModule();
        virtual ~IMonitorModule();
        virtual void retrieveData() = 0;
    private:
        IMonitorModule(const IMonitorModule &src);
        IMonitorModule &operator=(const IMonitorModule &src);
};
#endif
