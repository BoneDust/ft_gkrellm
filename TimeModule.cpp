/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TimeModule.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtshekel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 11:27:14 by gtshekel          #+#    #+#             */
/*   Updated: 2018/06/15 11:27:18 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "TimeModule.hpp"

TimeModule::TimeModule() : IMonitorModule()
{
   this-> _data.resize(2); 
}

TimeModule::TimeModule(const TimeModule &src)
{
    *this = src;
}

TimeModule::~TimeModule(){}

TimeModule &TimeModule::operator=(const TimeModule &src)
{
    this->_data = src.getData();
    this->_time = src.getTime();
    return (*this);
}

void    TimeModule::retrieveData()
{
    this->_time = std::time(0);
    std::tm* now = std::localtime(&this->_time);
    std::stringstream  sd, st;
    std::string month, day;
    if (now->tm_wday == 0)
        day = "Sun";
    else if (now->tm_wday == 1)
        day = "Mon";
    else if (now->tm_wday == 2)
        day = "Tue";
    else if (now->tm_wday == 3)
        day = "Wed";
    if (now->tm_wday == 4)
        day = "Thu";
    if (now->tm_wday == 5)
        day = "Fri";
    else
        day = "Sat";
    
    
    if (now->tm_mon == 0)
        month = "Jan";
    else if (now->tm_mon == 1)
        month = "Feb";
    else if (now->tm_mon == 2)
        month = "Mar";
    else if (now->tm_mon == 3)
        month = "Apr";
    else if (now->tm_mon == 4)
        month = "May";
    else if (now->tm_mon == 5)
        month = "Jun";
    else if (now->tm_mon == 6)
        month = "Jul";
    else if (now->tm_mon == 7)
        month = "Aug";
    else if (now->tm_mon == 8)
        month = "Sep";
    else if (now->tm_mon == 9)
        month = "Oct";
    else if (now->tm_mon == 10)
        month = "Nov";
    else if (now->tm_mon == 11)
        month = "Dec";
    sd<< day<< " "<< now->tm_mday << " " << month<< " " <<(now->tm_year + 1900);
    st<< now->tm_hour << ":" << now->tm_min << ":" << now->tm_sec<< ((now->tm_hour >=12) ? " PM" : " AM");
    this->_data[0] = sd.str();
    this->_data[1] = st.str();
}

std::time_t TimeModule::getTime() const
{
    return (this->_time);
}