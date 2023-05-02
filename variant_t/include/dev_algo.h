#ifndef _VARIANT_DEV_ALGO_H_
#define _VARIANT_DEV_ALGO_H_

#include "dev_impl.h"
#include "types.h"

namespace variant_t {

class Read {
public:
    void operator()(TcpPort const&, BufferData& output) const noexcept;
    void operator()(SerialPort const&, BufferData& output) const noexcept;
};

class Write {
public:
    void operator()(TcpPort&, BufferData const&) const noexcept;
    void operator()(SerialPort&, BufferData const&) const noexcept;
};

} // namespace variant_t

#endif