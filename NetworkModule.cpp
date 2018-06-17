/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Network.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtshekel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 15:00:17 by gtshekel          #+#    #+#             */
/*   Updated: 2018/06/16 15:03:18 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NetworkModule.hpp"

NetworkModule::NetworkModule() :  IMonitorModule()
{
   this-> _data.resize(2); 
}

NetworkModule::NetworkModule(int h, int w) : IMonitorModule(h, w)
{
    this->_data.resize(2);
}

NetworkModule::NetworkModule(const NetworkModule &src)
{
    *this = src;
}

NetworkModule::~NetworkModule(){}

NetworkModule& NetworkModule::operator=(const NetworkModule &src)
{
    this->_height = src.getHeight();
    this->_width = src.getWidth();
    this->_data = src.getData();
    return (*this);
}


void NetworkModule::retrieveData()
{
    std::string line;
    if(system(NULL))
    {
        system("top -n0 -l1 | grep 'Network' > netInfo.txt");
        std::ifstream data("netInfo.txt");
        if(data.is_open())
        {
            if(getline(data,line))
            {
                std::string in;
                std::string out;
                std::string temp = line.substr(line.find(":") + 1, line.length());
                std::string temp2 = temp.substr(temp.find(":") + 1, temp.length());
                in = temp2.substr(1, temp2.find(","));
                out = temp2.substr(temp2.find(",") + 1, temp2.length());
                this->_data[0] = "Packets in : " + in;
                this->_data[1] = "Packets out : " + out; 
            } 
            data.close();
        }
        remove("netInfo.txt");
    }
}
