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

int main()
{
    TimeModule timeM;
    timeM.retrieveData();
    HostModule host;
    std::cout<<"Date: "<< timeM.getData()[0] <<std::endl;
    std::cout<<"Current time : "<< timeM.getData()[1]<<std::endl<<std::endl<<std::endl;
    host.retrieveData();
    std::cout<<"host name: "<<host.getData()[0]<<std::endl;
    OSModule os;
    os.retrieveData();
    std::cout<<"Type: "<< os.getData()[0] <<std::endl;
    std::cout<<"release : "<< os.getData()[1]<<std::endl<<std::endl<<std::endl;
}