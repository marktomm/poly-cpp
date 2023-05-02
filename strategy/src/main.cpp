#include "lib.h"
using namespace std;
using namespace strategy;
// strategy/src/user.cpp

int main() {
    using namespace strategy;
    using Ports = std::vector<std::unique_ptr<Port> >;

    Ports ports;
    ports.push_back(createTcpPort("localhost", 2404,
                                  SyslogReadTcpPortStrategy{},
                                  SyncWriteTcpPortStrategy{}));
    ports.push_back(createSerialPort("/dev/ttyUSB0",
                                     SyslogReadSerialPortStrategy{},
                                     SyncWriteSerialPortStrategy{}));
    BufferData data;
    readPorts(ports, data);

    return 0;
}
// strategy/src/user.cpp end
