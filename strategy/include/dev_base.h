#ifndef _STRATEGY_DEV_BASE_H_
#define _STRATEGY_DEV_BASE_H_

#include <functional>
#include <string>

class TcpPort;
class SerialPort;

using StatTcpPortStrategy = std::function<void(TcpPort const&)>;
using StatSerialPortStrategy = std::function<void(SerialPort const&)>;

class Port
{
public:
    Port() = default;
    virtual ~Port() = default;

    virtual void read(std::string&) = 0;
    virtual void write(std::string const&) = 0;
    virtual void stat() const = 0;
};

#endif