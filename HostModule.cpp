/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HostModule.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtshekel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 15:20:42 by gtshekel          #+#    #+#             */
/*   Updated: 2018/06/15 15:25:14 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HostModule.hpp"

HostModule::HostModule() : IMonitorModule()
{
   this-> _data.resize(2); 
}

HostModule::HostModule(const HostModule &src)
{
    *this = src;
}

HostModule::~HostModule(){}

HostModule& HostModule::operator=(const HostModule &src)
{
    this->_data = src.getData();
    return (*this);
}


void HostModule::retrieveData()
{
    struct utsname data;
    uname(&data);
    this->_data[0] =  data.nodename;
    this->_data[0] = "Host PC : " + this->_data[0];
    if(system(NULL))
    {
        std::string line;
        system("whoami > user.txt");
        std::ifstream data ("user.txt");
        if(data.is_open())
        {
            if (getline(data,line))
                this->_data[1]  = "Current user : " + line;
            data.close();
        }
        remove("user.txt");
    }
}