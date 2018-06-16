/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtshekel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 14:11:08 by gtshekel          #+#    #+#             */
/*   Updated: 2018/06/15 14:11:11 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "TimeModule.hpp"
#include "HostModule.hpp"
#include "OSModule.hpp"
#include "CPUModule.hpp"
#include "RamModule.hpp"
#include "NetworkModule.hpp"
int main()
{
    TimeModule timeM;
    HostModule host;
    OSModule os;
    CPUModule cpu;
    RamModule ram;
    NetworkModule net;
    while (true)
    {
        timeM.retrieveData();
        std::vector<std::string> timeInfo = timeM.getData();
        for(std::vector<std::string>::iterator item = timeInfo.begin(); item != timeInfo.end();++item)
        std::cout<< *item <<std::endl;

        host.retrieveData();
        std::cout<<"host name: "<<host.getData()[0]<<std::endl<<std::endl<<std::endl;

        os.retrieveData();
        std::vector<std::string> osInfo = os.getData();
        for(std::vector<std::string>::iterator item = osInfo.begin(); item != osInfo.end();++item)
        std::cout<< *item <<std::endl;

        cpu.retrieveData();
        std::vector<std::string> cpuInfo = cpu.getData();
        for(std::vector<std::string>::iterator item = cpuInfo.begin(); item != cpuInfo.end();++item)
        std::cout<< *item <<std::endl;

        ram.retrieveData();
        std::vector<std::string> ramInfo = ram.getData();
        for(std::vector<std::string>::iterator item = ramInfo.begin(); item != ramInfo.end();++item)
        std::cout<< *item <<std::endl;
    
        net.retrieveData();
        std::vector<std::string> netInfo = net.getData();
        for(std::vector<std::string>::iterator item = netInfo.begin(); item != netInfo.end();++item)
        std::cout<< *item <<std::endl;
    }
}