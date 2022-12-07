#ifndef _DEV_IMPL_H_
#define _DEV_IMPL_H_

#include "dev_base.h"

#include <iostream>

class TcpPort: public Port
{
public:
    explicit TcpPort(std::string ip, uint16_t pn) : Port{tcp}, port_{pn}
    {
        // create connection
        // emit exception on error
    }
    ~TcpPort() = default;

    std::string GetIp();
    uint16_t GetPort();

private:
    std::string ip_;
    uint16_t port_;
};

void read(TcpPort&, std::string&);
void write(TcpPort&, std::string const&);
void stat(TcpPort const&);

class SerialPort: public Port
{
public:
    explicit SerialPort(std::string dev) : Port{serial}, dev_{dev} {}
    ~SerialPort() = default;

    std::string GetDev();

private:
    std::string dev_;
};

void read(SerialPort&, std::string&);
void write(SerialPort&, std::string const&);
void stat(SerialPort const&);

#endif