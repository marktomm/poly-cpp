#ifndef _VISITOR_DEV_ALGO_H_
#define _VISITOR_DEV_ALGO_H_

#include "common/types.h"
#include "dev_impl.h"

namespace Visit {

class Stat: public Port::Visitor
{
public:
    void visit(TcpPort const&) const override;
    void visit(SerialPort const&) const override;
};

class Write: public Port::Visitor
{
public:
    Write(BufferData const& data) : data_{data} {}
    void visit(TcpPort const&) const override;
    void visit(SerialPort const&) const override;

private:
    BufferData const& data_;
};

} // namespace Visit

#endif