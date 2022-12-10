#ifndef _OOP_DEV_FACTORY_H_
#define _OOP_DEV_FACTORY_H_

#include "dev_base.h"

#include <memory>
#include <string>

#include <cstdint>

statable CreateTcpPort(std::string ip, uint16_t port);

statable CreateSerialPort(std::string dev);

#endif