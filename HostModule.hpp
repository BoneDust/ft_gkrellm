/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HostModule.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtshekel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 15:07:57 by gtshekel          #+#    #+#             */
/*   Updated: 2018/06/15 15:08:09 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOST_MODULE_H
#define HOST_MODULE_H
#include "IMonitorModule.hpp"

class HostModule : public IMonitorModule
{
    public:
        HostModule();
        HostModule(std::string name);
        ~HostModule();
        HostModule(const HostModule &src);
        HostModule &operator=(const HostModule &src);
        void retrieveData(void);
        std::vector<std::string> getData(void) const;
        std::string getName() const;             
    private:
        std::string _name;
        std::vector<std::string> _data;
};

#endif