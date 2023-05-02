#include "lib.h"
using namespace std;
using namespace type_erasure_up;
// type_erasure_up/src/user.cpp

int main() {
    using namespace type_erasure_up;
    using Ports = std::vector<Readable>;

    Ports ports;
    ports.emplace_back(createTcpPort("localhost", 2404));
    ports.emplace_back(createSerialPort("/dev/ttyUSB0"));
    BufferData data;
    readPorts(ports, data);

    return 0;
}
// type_erasure_up/src/user.cpp end
