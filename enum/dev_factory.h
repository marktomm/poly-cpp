#ifndef _ENUM_DEV_FACTORY_H_
#define _ENUM_DEV_FACTORY_H_

#include "dev_base.h"

#include <memory>
#include <string>

#include <cstdint>

std::unique_ptr<Port> CreateTcpPort(std::string ip, uint16_t port);

std::unique_ptr<Port> CreateSerialPort(std::string dev);

#endif