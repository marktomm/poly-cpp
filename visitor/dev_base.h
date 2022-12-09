#ifndef _VISITOR_DEV_BASE_H_
#define _VISITOR_DEV_BASE_H_

#include <string>

class Port
{
public:
    Port() = default;
    virtual ~Port() = default;

    class Visitor;
    virtual void accept(Visitor const&) = 0;
};

#endif