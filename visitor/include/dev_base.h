#ifndef _VISITOR_DEV_BASE_H_
#define _VISITOR_DEV_BASE_H_

#include <string>

namespace Visit {

class Port
{
public:
    Port() = default;
    virtual ~Port() = default;

    class Visitor;
    virtual void accept(Visitor const&) const noexcept = 0;
    virtual void accept(Visitor const&) noexcept = 0;
};

} // namespace Visit

#endif
