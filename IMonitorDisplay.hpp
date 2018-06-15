#ifndef IMONITORDISPLAY_H
# define IMONITORDISPLAY_H

class IMonitorDisplay
{
    public:
        IMonitorDisplay();
        virtual ~IMonitorDisplay();
        virtual void renderData() = 0;
    private:
        std::string _name;
        IMonitorDisplay(const IMonitorDisplay &src);
        IMonitorDisplay &operator=(const IMonitorDisplay &src);
};

#endif
