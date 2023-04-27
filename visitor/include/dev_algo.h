#ifndef _VISITOR_DEV_ALGO_H_
#define _VISITOR_DEV_ALGO_H_

#include "dev_impl.h"
#include "types.h"

namespace Visit {

class Read final: public Port::Visitor {
public:
    Read(BufferData& output) : data_{output} {}
    void visit(TcpPort const&) const noexcept override;
    void visit(SerialPort const&) const noexcept override;
    void visit(TcpPort&) const noexcept override;
    void visit(SerialPort&) const noexcept override;

private:
    BufferData& data_;
};

class Write final: public Port::Visitor {
public:
    Write(BufferData const& data) : data_{data} {}
    void visit(TcpPort const&) const noexcept override;
    void visit(SerialPort const&) const noexcept override;
    void visit(TcpPort&) const noexcept override;
    void visit(SerialPort&) const noexcept override;

private:
    BufferData const& data_;
};

} // namespace Visit

#endif