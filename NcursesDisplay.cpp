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

NcursesDisplay::NcursesDisplay() : IMonitorDisplay(){}
NcursesDisplay::~NcursesDisplay(){}

void NcursesDisplay::renderData(TimeModule date, HostModule host, OSModule os, CPUModule cpu, RamModule ram, NetworkModule net)
{
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    int c = static_cast<int>('*');
    int a = static_cast<int>('|');
    int b = static_cast<int>('-');
    WINDOW		*master = newwin(40, 135, 5, 3);
    WINDOW		*hostWin = newwin(4, 130, 10, 5);
    WINDOW		*dateWin = newwin(6 , 130, 14, 5);
	WINDOW		*osWin = newwin(7, 130, 20, 5);
	WINDOW		*cpuWin = newwin(7, 130, 27, 5);
	WINDOW		*ramWin = newwin(7, 130, 34, 5);
	WINDOW		*netWin = newwin(6, 130, 41, 5);
    box(master, c, b);
    int key = static_cast<int>('a');
    while (key != EXIT)
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
        box(master, c, b);
        key = getch();
        usleep(100000);
    }

    endwin();
}
void NcursesDisplay::renderTime(TimeModule timeM, WINDOW *win)
{
    timeM.retrieveData();
    wrefresh(win);
    mvwprintw(win, 1, 59,"HOST INFO");
    mvwprintw(win, 2, 3, timeM.getData[0]);
}
void NcursesDisplay::renderHost(HostModule host, WINDOW *win)
{
    host.retrieveData();
    wrefresh(win);
    mvwprintw();
    mvwprintw();
    mvwprintw();
}
void NcursesDisplay::renderOS(OSModule os, WINDOW *win)
{
    os.retrieveData();
    wrefresh(win);
    mvwprintw();
    mvwprintw();
    mvwprintw();
    mvwprintw(); 
}
void NcursesDisplay::renderCPU(CPUModule cpu, WINDOW *win)
{
    cpu.retrieveData();
    wrefresh(win);
    mvwprintw();
    mvwprintw();
    mvwprintw();
    mvwprintw(); 
}
void NcursesDisplay::renderRam(RamModule ram, WINDOW *win)
{
    ram.retrieveData();
    wrefresh(win);
    mvwprintw();
    mvwprintw();
    mvwprintw();
    mvwprintw();
}
void NcursesDisplay::renderNetwork(NetworkModule network, WINDOW *win)
{
    network.retrieveData();
    wrefresh(win);
    mvwprintw();
    mvwprintw();
    mvwprintw(); 
}