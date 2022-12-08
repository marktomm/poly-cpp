#ifndef _VISITOR_DEV_ALGO_H_
#define _VISITOR_DEV_ALGO_H_

#include "dev_impl.h"

class Stat: public Port::Visitor
{
public:
    void visit(TcpPort const&) const override;
    void visit(SerialPort const&) const override;
};

#endif