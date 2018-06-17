/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Network.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtshekel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 14:58:22 by gtshekel          #+#    #+#             */
/*   Updated: 2018/06/16 15:05:39 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Network_MODULE_H
#define Network_MODULE_H
#include "IMonitorModule.hpp"

class NetworkModule : public IMonitorModule
{
    public:
        NetworkModule();
        NetworkModule(int h, int w);
        ~NetworkModule();
        NetworkModule(const NetworkModule &src);
        NetworkModule &operator=(const NetworkModule &src);
        void retrieveData(void);           
};

#endif
