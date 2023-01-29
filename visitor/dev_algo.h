#ifndef _VISITOR_DEV_ALGO_H_
#define _VISITOR_DEV_ALGO_H_

#include "common/types.h"
#include "dev_impl.h"

namespace Visit {

class Stat final: public Port::Visitor
{
public:
    void visit(TcpPort const&) const noexcept override;
    void visit(SerialPort const&) const noexcept override;
};

class Write final: public Port::Visitor
{
public:
    Write(BufferData const& data) : data_{data} {}
    void visit(TcpPort const&) const noexcept override;
    void visit(SerialPort const&) const noexcept override;

private:
    BufferData const& data_;
};

} // namespace Visit

#endif