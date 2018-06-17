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
# define EXIT 27
# include "IMonitorDisplay.hpp"

class NcursesDisplay : public IMonitorDisplay
{
    public:
        NcursesDisplay();
        NcursesDisplay(std::string name);
        NcursesDisplay(const NcursesDisplay &src);
        NcursesDisplay &operator=(const NcursesDisplay &src);
        ~NcursesDisplay();
        void renderData(TimeModule, HostModule, OSModule, CPUModule, RamModule, NetworkModule);       
    private:
        void renderTime(TimeModule, WINDOW*);
        void renderHost(HostModule, WINDOW*);
        void renderOS(OSModule, WINDOW*);
        void renderCPU(CPUModule, WINDOW*);
        void renderRam(RamModule, WINDOW*);
        void renderNetwork(NetworkModule, WINDOW*);
 
};

#endif