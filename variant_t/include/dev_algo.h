#ifndef _VARIANT_DEV_ALGO_H_
#define _VARIANT_DEV_ALGO_H_

#include "dev_impl.h"

class Stat
{
public:
    void operator()(TcpPort const&) const;
    void operator()(SerialPort const&) const;
};

#endif