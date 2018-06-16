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
int main()
{
    TimeModule timeM;
    timeM.retrieveData();
    std::cout<<"\nDate: "<< timeM.getData()[0] <<std::endl;
    std::cout<<"Current time : "<< timeM.getData()[1]<<std::endl<<std::endl;
    
    HostModule host;
    host.retrieveData();
    std::cout<<"host name: "<<host.getData()[0]<<std::endl<<std::endl;
    
    OSModule os;
    os.retrieveData();
    std::cout<< os.getData()[0] <<std::endl;
    std::cout<< os.getData()[1]<<std::endl;
    std::cout<< os.getData()[2]<<std::endl;

    CPUModule cpu;
    cpu.retrieveData();
    std::cout<< cpu.getData()[0] <<std::endl;
    std::cout<< cpu.getData()[1]<<std::endl;
    std::cout<< cpu.getData()[2]<<std::endl;
}