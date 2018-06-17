/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RamModule.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtshekel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 12:47:05 by gtshekel          #+#    #+#             */
/*   Updated: 2018/06/16 12:48:27 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RamModule.hpp"

RamModule::RamModule() :  IMonitorModule()
{
   this-> _data.resize(3); 
}

RamModule::RamModule(const RamModule &src)
{
    *this = src;
}

RamModule::~RamModule(){}

RamModule &RamModule::operator=(const RamModule &src)
{
    this->_data = src.getData();
    return (*this);
}


void RamModule::retrieveData()
{

    std::string line;
    if(system(NULL))
    {
        system("top -n0 -l1 | grep 'PhysMem' > ramInfo.txt");
        std::ifstream data("ramInfo.txt");
        if(data.is_open())
        {
            if(getline(data,line))
            {
                std::string total;
                std::string used;
                std::string unused;
                std::string temp = line.substr(line.find(":") + 1, line.length());
                unused = temp.substr(temp.find(",") + 2, 5);
                used = temp.substr(1, 5);
                int ram = std::stoi(used) + std::stoi(unused);
                total = "Total ram : " + std::to_string(ram) + "M";
                this->_data[0] = total;
                this->_data[1] = "Used : " + used;
                this->_data[2] = "Unused : " + unused; 
            } 
            data.close();
        }
        remove("ramInfo.txt");
    }
}
