#ifndef _OOP_DEV_BASE_H_
#define _OOP_DEV_BASE_H_

#include "types.h"

#include <string>

namespace oop {

class Port {
public:
    Port() = default;
    virtual ~Port() = default;

    virtual void Read(BufferData&) const noexcept = 0;
    virtual void Write(BufferData const&) noexcept = 0;
};

} // namespace oop

#endif