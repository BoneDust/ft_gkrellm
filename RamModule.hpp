/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RamModule.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtshekel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 12:44:44 by gtshekel          #+#    #+#             */
/*   Updated: 2018/06/16 12:46:29 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Ram_MODULE_H
#define Ram_MODULE_H
#include "IMonitorModule.hpp"

class RamModule : public IMonitorModule
{
    public:
        RamModule();
        RamModule(std::string name);
        ~RamModule();
        RamModule(const RamModule &src);
        RamModule &operator=(const RamModule &src);
        void retrieveData(void);
        std::vector<std::string> getData(void) const;
        std::string getName() const;             
    private:
        std::string _name;
        std::vector<std::string> _data;
};

#endif
