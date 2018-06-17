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

NcursesDisplay::NcursesDisplay() : IMonitorDisplay(){return;}
NcursesDisplay::~NcursesDisplay(){}

void NcursesDisplay::renderData(TimeModule date, HostModule host, OSModule os, CPUModule cpu, RamModule ram, NetworkModule net)
{
    initscr();
    raw();
    curs_set(0);
    start_color();
    timeout(0);
    int a = static_cast<int>('|');
    int b = static_cast<int>('-');
    WINDOW		*hostWin = newwin(7, 135, 5, 5);
    WINDOW		*dateWin = newwin(6, 135, 12, 5);
	WINDOW		*osWin = newwin(8, 135, 18, 5);
	WINDOW		*cpuWin = newwin(11, 135, 26, 5);
	WINDOW		*ramWin = newwin(8, 135, 37, 5);
	WINDOW		*netWin = newwin(7, 135, 45, 5);
    int c = static_cast<int>('c');
    while (c != EXIT)
    {
        renderTime(date, dateWin);
        renderHost(host, hostWin);
        renderOS(os, osWin);
        renderCPU(cpu, cpuWin);
        renderRam(ram, ramWin);
        renderNetwork(net, netWin);
        box(dateWin, a, b);
        box(hostWin, a, b);
        box(osWin, a, b);
        box(cpuWin, a, b);
        box(ramWin, a, b);
        box(netWin, a, b);
        usleep(9990);
        c = getch();
    }
    endwin();
}
void NcursesDisplay::renderTime(TimeModule timeM, WINDOW *win)
{
    timeM.retrieveData();
    int len = timeM.getData()[0].length();
    wrefresh(win);
    mvwprintw(win, 2, 62,"DATE");
    mvwprintw(win, 4, 3, timeM.getData()[0].c_str());
    mvwprintw(win, 4, len + 6, timeM.getData()[1].c_str());
}
void NcursesDisplay::renderHost(HostModule host, WINDOW *win)
{
    host.retrieveData();
    wrefresh(win);
    mvwprintw(win, 2, 59,"HOST INFO");
    mvwprintw(win, 4, 3, host.getData()[0].c_str());
    mvwprintw(win, 5, 3, host.getData()[1].c_str());
}
void NcursesDisplay::renderOS(OSModule os, WINDOW *win)
{
    os.retrieveData();
    wrefresh(win);
    mvwprintw(win, 2, 61,"OS INFO");
    mvwprintw(win, 4, 3, os.getData()[0].c_str());
    mvwprintw(win, 5, 3, os.getData()[1].c_str());
    mvwprintw(win, 6, 3, os.getData()[2].c_str());
}
void NcursesDisplay::renderCPU(CPUModule cpu, WINDOW *win)
{
    start_color();
    init_pair(1, COLOR_BLUE, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    cpu.retrieveData();
    std::vector<std::string> items = cpu.getData();
    std::vector<int> use = cpu.getUsage();
    wrefresh(win);
    std::string user = "User usage :   |====================================================================================================|";
    user.append(items[2]).append("%");
    std::string sys = "Sys usage  :   |====================================================================================================| ";
    sys.append(items[3]).append("%");
    std::string idle = "Idle usage :   |====================================================================================================| ";
    idle.append(items[4]).append("%");
    mvwprintw(win, 2, 60, "CPU Info");
    mvwprintw(win, 4, 3, items[0].c_str());
    mvwprintw(win, 5, 3, items[1].c_str());
    mvwprintw(win, 6, 60, "CPU Usage");
    mvwprintw(win, 7, 3, user.c_str());
    if(use[0]>=1)
        mvwprintw(win, 7, 18 + use[0], "*");
    mvwprintw(win, 8, 3, sys.c_str());
    if(use[1]>=1)
        mvwprintw(win, 8, 18 + use[1], "*");
    mvwprintw(win, 9, 3, idle.c_str());
    if(use[2]>=1)
        mvwprintw(win, 9, 18 + use[2], "*");
}
void NcursesDisplay::renderRam(RamModule ram, WINDOW *win)
{
    ram.retrieveData();
    wrefresh(win);
    mvwprintw(win, 2, 61,"RAM INFO");
    mvwprintw(win, 4, 3, ram.getData()[0].c_str());
    mvwprintw(win, 5, 3, ram.getData()[1].c_str());
    mvwprintw(win, 6, 3, ram.getData()[2].c_str());
}
void NcursesDisplay::renderNetwork(NetworkModule network, WINDOW *win)
{
    network.retrieveData();
    wrefresh(win);
    mvwprintw(win, 2, 58,"NETWORK INFO");
    mvwprintw(win, 4, 3, network.getData()[0].c_str());
    mvwprintw(win, 5, 3, network.getData()[1].c_str());
}