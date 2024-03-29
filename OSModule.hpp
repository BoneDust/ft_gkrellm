/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OSModule.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtshekel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 15:40:06 by gtshekel          #+#    #+#             */
/*   Updated: 2018/06/15 17:46:35 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OS_MODULE_H
#define OS_MODULE_H
#include "IMonitorModule.hpp"

class OSModule : public IMonitorModule
{
    public:
        OSModule();
        ~OSModule();
        OSModule(const OSModule &src);
        OSModule &operator=(const OSModule &src);
        void retrieveData(void);           
};

#endif