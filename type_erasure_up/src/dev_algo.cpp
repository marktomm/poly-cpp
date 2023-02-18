#include "dev_algo.h"

#include <iostream>

namespace TypeErasureUp {

void read(TcpPort&, std::string&) noexcept {}
void write(TcpPort& p, BufferData const& data) noexcept { p.Write(data); }
void stat(TcpPort const& port) noexcept {
    using namespace std;
    cout << "tcp port stats " << port.GetIp() << ":" << port.GetPort() << "\n";
}

void read(SerialPort&, std::string&) noexcept {}
void write(SerialPort& p, BufferData const& data) noexcept { p.Write(data); }
void stat(SerialPort const& port) noexcept {
    using namespace std;
    cout << "serial port stats " << port.GetDev() << "\n";
}

} // namespace TypeErasureUp