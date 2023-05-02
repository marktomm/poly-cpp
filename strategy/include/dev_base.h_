#ifndef _STRATEGY_DEV_BASE_H_
#define _STRATEGY_DEV_BASE_H_

#include "types.h"

#include <functional>
#include <string>

namespace strategy {

class TcpPort;
class SerialPort;

using ReadTcpPortStrategy = std::function<void(TcpPort const&, BufferData&)>;
using ReadSerialPortStrategy =
    std::function<void(SerialPort const&, BufferData&)>;

using WriteTcpPortStrategy = std::function<void(TcpPort&, BufferData const&)>;
using WriteSerialPortStrategy =
    std::function<void(SerialPort&, BufferData const&)>;

class Port {
public:
    Port() = default;
    virtual ~Port() = default;

    virtual void Read(BufferData&) const noexcept = 0;
    virtual void Write(BufferData const&) noexcept = 0;
};

} // namespace strategy

#endif