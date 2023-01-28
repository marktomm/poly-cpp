#ifndef _DEV_BASE_H_
#define _DEV_BASE_H_

enum PortType { tcp, serial, end_ = 0xFFFFFFFF };

using MutableBuffer = int;
using BufferData = int;

class Port
{
public:
    explicit Port(PortType pt) : type_{pt} {}
    virtual ~Port() = default;

    PortType GetType() const noexcept { return type_; }

private:
    PortType const type_;
};

#endif