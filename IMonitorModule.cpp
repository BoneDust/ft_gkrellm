/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModule.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtshekel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 14:34:18 by gtshekel          #+#    #+#             */
/*   Updated: 2018/06/15 14:34:23 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMonitorModule.hpp"

IMonitorModule::IMonitorModule(){};
IMonitorModule::~IMonitorModule(){};
IMonitorModule::IMonitorModule(int height, int width)
{
    this->_height = height;
    this->_width = width;
}

IMonitorModule::IMonitorModule(const IMonitorModule &src)
{
    *this = src;
}
IMonitorModule &IMonitorModule::operator=(const IMonitorModule &src)
{
    this->_height = src.getHeight();
    this->_width = src.getWidth();
    this->_data = src.getData();
    return (*this);
}

void IMonitorModule::setHeight(int height)
{
    this->_height = height;
}
void IMonitorModule::setWidth(int wid)
{
    this->_width = wid;
}
int  IMonitorModule::getHeight(void) const
{
    return (this->_height);
}
int  IMonitorModule::getWidth(void) const
{
    return (this->_width);
}
std::vector<std::string> IMonitorModule::getData(void) const
{
    return (this->_data);
}