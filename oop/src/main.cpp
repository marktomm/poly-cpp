// oop/src/user.cpp
#include "lib.h"
#include <vector>

using namespace std;
using namespace oop;

int main() {
    using namespace oop;
    using Ports = std::vector<std::unique_ptr<Port> >;

    Ports ports;
    ports.push_back(createTcpPort("localhost", 2404));
    ports.push_back(createSerialPort("/dev/ttyUSB0"));
    BufferData data;
    readPorts(ports, data);

    return 0;
}
// oop/src/user.cpp end
