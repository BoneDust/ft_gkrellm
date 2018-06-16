/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NcursesDisplay.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtshekel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 16:01:51 by gtshekel          #+#    #+#             */
/*   Updated: 2018/06/16 16:01:53 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NcursesDisplay.hpp"

void NcursesDisplay::renderData();
void NcursesDisplay::renderTime(TimeModule timeM);
void NcursesDisplay::renderHost(HostModule host);
void NcursesDisplay::renderOS(OSModule os);
void NcursesDisplay::renderCPU(CPUModule cpu);
void NcursesDisplay::renderRam(RamModule ram);
void NcursesDisplay::renderNetwork(NetworkModule network);