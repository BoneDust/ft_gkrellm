/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPUModule.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtshekel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 11:19:55 by gtshekel          #+#    #+#             */
/*   Updated: 2018/06/16 12:16:13 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "CPUModule.hpp"

CPUModule::CPUModule() : IMonitorModule()
{
   this-> _data.resize(5);
   this->_usage.resize(3); 
}

CPUModule::CPUModule(const CPUModule &src)
{
    *this = src;
}

CPUModule::~CPUModule(){}

CPUModule& CPUModule::operator=(const CPUModule &src)
{
    this->_data = src.getData();
    this->_usage = src.getUsage();
    return (*this);
}


std::vector<int> CPUModule::getUsage() const
{
    return (this->_usage);
}

void CPUModule::retrieveData()
{

    std::string line;
    if(system(NULL))
    {
        system("sysctl machdep.cpu.brand_string > cpuinfo.txt");
        system("sysctl -n hw.ncpu >> cpuinfo.txt");
        system("top -n0 -l1 | grep 'CPU' >> cpuinfo.txt");
        std::ifstream data ("cpuinfo.txt");
        if(data.is_open())
        {
            int i = 0;
            while(getline(data,line))
            {
                if (i == 0)
                    this->_data[i] = "CPU info: " + line.substr(line.find(":"), static_cast<int>(line.length()));
                else if (i == 1)
                    this->_data[i] = "CPU cores: " + line;
                else
                {
                    std::string tmp = line.substr(line.find_first_of(":") + 1, line.length());
                    std::string user = tmp.substr(1, tmp.find_first_of('%'));
                    std::string tmp1 = tmp.substr(user.length() + 8, tmp.length());
                    std::string sys = tmp1.substr(0, tmp1.find_first_of('%'));
                    std::string tmp2 = tmp1.substr(sys.length() + 7, tmp1.length());
                    std::string idle = tmp2.substr(0, tmp2.find_first_of('%'));
                    this->_usage[0] = static_cast<int>(roundf(std::stod(user)));
                    this->_usage[1] = static_cast<int>(roundf(std::stod(sys)));
                    this->_usage[2] = static_cast<int>(roundf(std::stod(idle)));
                    this->_data[i] = user;
                    this->_data[i + 1] = sys;
                    this->_data[i + 2] = idle;
                }
                i++;
            } 
            data.close();
        }
        remove("cpuinfo.txt");
    }
}