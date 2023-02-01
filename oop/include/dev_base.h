#ifndef _OOP_DEV_BASE_H_
#define _OOP_DEV_BASE_H_

#include "types.h"

#include <string>

namespace Oop {

class Port
{
public:
    Port() = default;
    virtual ~Port() = default;

    virtual void Read(std::string&) noexcept = 0;
    virtual void Write(BufferData const&) noexcept = 0;
    virtual void Stat() const noexcept = 0;
};

} // namespace Oop

#endif