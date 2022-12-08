
#include "dev_algo.h"

#include <iostream>

void read(TcpPort&, std::string&) {}
void write(TcpPort&, std::string const&) {}
void stat(TcpPort const&)
{
    using namespace std;
    cout << "tcp port stats\n";
}

void read(SerialPort&, std::string&) {}
void write(SerialPort&, std::string const&) {}
void stat(SerialPort const&)
{
    using namespace std;
    cout << "serial port stats\n";
}