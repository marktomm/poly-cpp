#include "lib.h"
using namespace std;
using namespace strategy;
// strategy/src/user.cpp

int main() {
    using namespace strategy;
    using Ports = std::vector<std::unique_ptr<Port> >;

    Ports ports;
    ports.push_back(createTcpPort("localhost", 2404, SyslogReadStrategy{},
                                  SyncWriteStrategy{}));
    ports.push_back(createSerialPort("/dev/ttyUSB0", SyslogReadStrategy{},
                                     SyncWriteStrategy{}));
    BufferData data;
    readPorts(ports, data);

    SerialPort p1("/dev/ttyUSB1", SyslogReadStrategy{}, SyncWriteStrategy{});

    p1.SetWriteStrat(UnbufferedWriteStrategy{});

    return 0;
}
// strategy/src/user.cpp end
