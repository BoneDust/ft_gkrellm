#ifndef IMONITORMODULE_H
# define IMONITORMODULE_H
#include <sys/sysctl.h>
#include <sys/utsname.h>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
class IMonitorModule
{
    public:
        IMonitorModule();
        IMonitorModule(int h, int w);
        IMonitorModule(const IMonitorModule &src);
        IMonitorModule &operator=(const IMonitorModule &src);
        virtual ~IMonitorModule();
        virtual void retrieveData() = 0;
        std::vector<std::string> getData(void) const;
    protected:
        std::vector<std::string> _data;
};
#endif
