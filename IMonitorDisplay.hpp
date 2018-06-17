/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplay.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtshekel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 16:02:20 by gtshekel          #+#    #+#             */
/*   Updated: 2018/06/16 16:11:25 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORDISPLAY_H
# define IMONITORDISPLAY_H
#include <iostream>
#include <ncurses.h>
#include "TimeModule.hpp"
#include "HostModule.hpp"
#include "OSModule.hpp"
#include "CPUModule.hpp"
#include "RamModule.hpp"
#include "NetworkModule.hpp"
#include <unistd.h>

class IMonitorDisplay
{
    public:
        IMonitorDisplay();
        virtual ~IMonitorDisplay();
        virtual void renderData(TimeModule, HostModule, OSModule, CPUModule, RamModule, NetworkModule) = 0;
    private:
        IMonitorDisplay(const IMonitorDisplay &src);
        IMonitorDisplay &operator=(const IMonitorDisplay &src);
};

#endif
