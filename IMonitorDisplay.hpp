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

class IMonitorDisplay
{
    public:
        IMonitorDisplay();
        IMonitorDisplay(std::string name);
        virtual ~IMonitorDisplay();
        virtual void renderData() = 0;
    private:
        IMonitorDisplay(const IMonitorDisplay &src);
        IMonitorDisplay &operator=(const IMonitorDisplay &src);
};

#endif
