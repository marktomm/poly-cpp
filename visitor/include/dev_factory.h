#ifndef _VISITOR_DEV_FACTORY_H_
#define _VISITOR_DEV_FACTORY_H_

#include "dev_base.h"

#include <memory>
#include <string>

#include <cstdint>

namespace Visit {

std::unique_ptr<Port> createTcpPort(std::string ip, uint16_t port);

std::unique_ptr<Port> createSerialPort(std::string dev);

} // namespace Visit

#endif