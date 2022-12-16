#ifndef _DEV_EXT_H_
#define _DEV_EXT_H_

#include "dev_base.h"

#include <memory>
#include <vector>

void statPorts(std::vector<std::unique_ptr<Port> > const& shapes);

void statPort(std::unique_ptr<Port> const& port);

#endif