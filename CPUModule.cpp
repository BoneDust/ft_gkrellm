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

CPUModule::CPUModule() : IMonitorModule(), _name("CPUModule")
{
   this-> _data.resize(3); 
}

CPUModule::CPUModule(std::string name) : IMonitorModule(name), _name(name)
{
    this->_data.resize(3);
}

CPUModule::CPUModule(const CPUModule &src)
{
    *this = src;
}

CPUModule::~CPUModule(){}

CPUModule& CPUModule::operator=(const CPUModule &src)
{
    this->_name = src.getName();
    this->_data = src.getData();
    return (*this);
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
                    this->_data[i] = "CPU info: " + line.substr(line.find(":"), (int)line.length());
                else if (i == 1)
                    this->_data[i] = "CPU cores: " + line;
                else
                    this->_data[i] = line;
                i++;
            } 
            data.close();
        }
        remove("cpuinfo.txt");
    }
}

std::string CPUModule::getName() const
{
    return (this->_name);
}

std::vector<std::string> CPUModule::getData() const
{
    return (this->_data);
}