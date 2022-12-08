#include "dev_algo.h"

#include <iostream>

void Stat::visit(TcpPort const& p) const
{
    using namespace std;
    cout << "tcp port stats\n";
}

void Stat::visit(SerialPort const& p) const
{
    using namespace std;
    cout << "serial port stats " << p.GetDev() << "\n";
}
