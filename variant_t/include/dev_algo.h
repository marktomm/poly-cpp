#ifndef _VARIANT_DEV_ALGO_H_
#define _VARIANT_DEV_ALGO_H_

#include "dev_impl.h"
#include "types.h"

namespace VariantT {

class Stat
{
public:
    void operator()(TcpPort const&) const;
    void operator()(SerialPort const&) const;
};

class Write
{
public:
    void operator()(TcpPort&, BufferData const&) const;
    void operator()(SerialPort&, BufferData const&) const;
};

} // namespace VariantT

#endif