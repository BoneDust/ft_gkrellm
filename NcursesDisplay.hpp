/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NcursesDisplay.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtshekel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 16:01:36 by gtshekel          #+#    #+#             */
/*   Updated: 2018/06/16 16:01:40 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef NCURSESDISPLAY_H
# define NCURSESDISPLAY_H
# include "IMonitorDisplay.hpp"
#include "TimeModule.hpp"
#include "HostModule.hpp"
#include "OSModule.hpp"
#include "CPUModule.hpp"
#include "RamModule.hpp"
#include "NetworkModule.hpp"
class NcursesDisplay : public IMonitorDisplay
{
    public:
        NcursesDisplay();
        NcursesDisplay(std::string name);
        NcursesDisplay(const NcursesDisplay &src);
        NcursesDisplay &operator=(const NcursesDisplay &src);
        ~NcursesDisplay();
        void renderData() = 0;       
    private:
        WINDOW *win;
        void renderTime(TimeModule timeM);
        void renderHost(HostModule host);
        void renderOS(OSModule os);
        void renderCPU(CPUModule cpu);
        void renderRam(RamModule ram);
        void renderNetwork(NetworkModule network);
 
};

#endif