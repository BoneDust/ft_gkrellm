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

HostModule::HostModule() : _name("HostModule")
{
   this-> _data.resize(1); 
}

HostModule::HostModule(std::string name) : _name(name)
{
    this->_data.resize(1);
}

HostModule::HostModule(const HostModule &src)
{
    *this = src;
}

HostModule::~HostModule(){}

HostModule& HostModule::operator=(const HostModule &src)
{
    this->_name = src.getName();
    this->_data = src.getData();
    return (*this);
}


void HostModule::retrieveData()
{
    struct utsname data;
    uname(&data);
    this->_data[0] = data.nodename;
}

std::string HostModule::getName() const
{
    return (this->_name);
}

std::vector<std::string> HostModule::getData() const
{
    return (this->_data);
}