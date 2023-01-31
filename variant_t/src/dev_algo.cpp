#include "dev_algo.h"

#include <iostream>

void Stat::operator()(TcpPort const& p) const
{
    using namespace std;
    cout << "tcp port stats\n";
}

void Stat::operator()(SerialPort const& p) const
{
    using namespace std;
    cout << "serial port stats " << p.GetDev() << "\n";
}
