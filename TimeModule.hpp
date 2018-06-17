/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TimeModule.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtshekel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 11:27:29 by gtshekel          #+#    #+#             */
/*   Updated: 2018/06/15 11:27:36 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIME_MODULE_H
#define TIME_MODULE_H
#include "IMonitorModule.hpp"

class TimeModule : public IMonitorModule
{
    public:
        TimeModule();
        TimeModule(int h, int w);
        ~TimeModule();
        TimeModule(const TimeModule &src);
        TimeModule &operator=(const TimeModule &src);
        void retrieveData(void); 
        std::time_t getTime() const;             
    private:
        std::time_t _time;       
};
#endif