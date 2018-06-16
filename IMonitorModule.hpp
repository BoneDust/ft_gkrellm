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
class IMonitorModule
{
    public:
        IMonitorModule();
        IMonitorModule(std::string name);
        virtual ~IMonitorModule();
        virtual void retrieveData() = 0;
    protected:
        std::string _name;
    private:
        IMonitorModule(const IMonitorModule &src);
        IMonitorModule &operator=(const IMonitorModule &src);
};
#endif
