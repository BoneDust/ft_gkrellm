/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPUModule.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtshekel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 11:18:00 by gtshekel          #+#    #+#             */
/*   Updated: 2018/06/16 11:19:19 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPU_MODULE_H
#define CPU_MODULE_H
#include "IMonitorModule.hpp"

class CPUModule : public IMonitorModule
{
    public:
        CPUModule();
        CPUModule(std::string name);
        ~CPUModule();
        CPUModule(const CPUModule &src);
        CPUModule &operator=(const CPUModule &src);
        void retrieveData(void);
        std::vector<std::string> getData(void) const;
        std::string getName() const;             
    private:
        std::string _name;
        std::vector<std::string> _data;
};

#endif
