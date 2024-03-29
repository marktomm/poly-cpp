#include "lib.h"
using namespace std;
using namespace visitor;
// visitor/src/user.cpp

int main() {
    using namespace visitor;
    using Ports = std::vector<std::unique_ptr<Port> >;

    Ports ports;
    ports.push_back(createTcpPort("localhost", 2404));
    ports.push_back(createSerialPort("/dev/ttyUSB0"));
    BufferData data;
    readPorts(ports, data);

    return 0;
}
// visitor/src/user.cpp end
