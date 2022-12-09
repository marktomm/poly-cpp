#ifndef _STRATEGY_DEV_BASE_H_
#define _STRATEGY_DEV_BASE_H_

#include <string>

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