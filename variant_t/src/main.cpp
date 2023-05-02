#include "lib.h"
using namespace std;
using namespace variant_t;
// variant_t/src/user.cpp

int main() {
    using namespace variant_t;
    using Ports = std::vector<Port>;

    Ports ports;
    ports.push_back(TcpPort{"localhost", 2404});
    ports.push_back(SerialPort{"/dev/ttyUSB0"});
    ReadData data;
    readPorts(ports, data);
    writePorts(ports, BufferData{10});

    return 0;
}
// variant_t/src/user.cpp end
