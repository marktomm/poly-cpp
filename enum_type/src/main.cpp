// enum_type/src/user.cpp
#include "lib.h"
#include <vector>

int main() {
    using namespace Enum;
    using Ports = std::vector<std::unique_ptr<Port> >;

    Ports ports;
    ports.push_back(createTcpPort("localhost", 2404));
    ports.push_back(createSerialPort("/dev/ttyUSB0"));
    BufferData data;
    readPorts(ports, data);

    return 0;
}
// enum_type/src/user.cpp end
