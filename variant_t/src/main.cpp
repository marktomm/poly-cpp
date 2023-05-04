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

    variant_t::Network networkInstance =
        variant_t::TcpPort("192.168.1.1", 8080);
    variant_t::GetStatus getStatus;
    std::string status = std::visit(getStatus, networkInstance);

    return 0;
}
// variant_t/src/user.cpp end
