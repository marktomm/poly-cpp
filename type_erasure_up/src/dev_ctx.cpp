#include "dev_ctx.h"

void stat(std::vector<statable> const& doc)
{
    for (auto const& it : doc) {
        stat(it);
    }
}

void statPorts(std::vector<statable> const& ports) { stat(ports); }