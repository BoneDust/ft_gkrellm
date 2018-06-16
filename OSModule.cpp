/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OSModule.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtshekel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 17:18:24 by gtshekel          #+#    #+#             */
/*   Updated: 2018/06/15 18:33:28 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "OSModule.hpp"

OSModule::OSModule() : _name("OSModule")
{
   this-> _data.resize(3); 
}

OSModule::OSModule(std::string name) : _name(name)
{
    this->_data.resize(3);
}

OSModule::OSModule(const OSModule &src)
{
    *this = src;
}

OSModule::~OSModule(){}

OSModule& OSModule::operator=(const OSModule &src)
{
    this->_name = src.getName();
    this->_data = src.getData();
    return (*this);
}


void OSModule::retrieveData()
{

    std::string line;
    if(system(NULL))
    {
        system("sw_vers > osinfo.txt");
        std::ifstream data ("osinfo.txt");
        if(data.is_open())
        {
            int i = 0;
            while(getline(data,line))
            {
                this->_data[i] = line;
                i++;
            } 
            data.close();
        }
       remove("osinfo.txt");
    }
}

std::string OSModule::getName() const
{
    return (this->_name);
}

std::vector<std::string> OSModule::getData() const
{
    return (this->_data);
}
