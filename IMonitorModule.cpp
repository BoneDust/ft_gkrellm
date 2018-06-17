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

IMonitorModule::IMonitorModule(const IMonitorModule &src)
{
    *this = src;
}
IMonitorModule &IMonitorModule::operator=(const IMonitorModule &src)
{
    this->_data = src.getData();
    return (*this);
}

std::vector<std::string> IMonitorModule::getData(void) const
{
    return (this->_data);
}