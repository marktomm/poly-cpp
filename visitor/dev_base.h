#ifndef _VISITOR_DEV_BASE_H_
#define _VISITOR_DEV_BASE_H_

#include <string>

class TcpPort;
class SerialPort;

class Visitor
{
public:
    virtual ~Visitor() = default;

    virtual void visit(TcpPort const&) const = 0;
    virtual void visit(SerialPort const&) const = 0;
};

class Port
{
public:
    Port() = default;
    virtual ~Port() = default;

    virtual void accept(Visitor const&) = 0;
};

#endif