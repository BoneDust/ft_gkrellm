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
#include "RamModule.hpp"
#include "NetworkModule.hpp"
#include "NcursesDisplay.hpp"
int main()
{
    TimeModule timeM;
    HostModule host;
    OSModule os;
    CPUModule cpu;
    RamModule ram;
    NetworkModule net;
    NcursesDisplay ncurses;
    //cpu.retrieveData();
    ncurses.renderData(timeM, host, os, cpu, ram, net);
    return (0);
}