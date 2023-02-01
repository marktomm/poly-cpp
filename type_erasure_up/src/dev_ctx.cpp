#include "dev_ctx.h"
#include "types.h"

void stat(std::vector<statable> const& doc)
{
    for (auto const& it : doc) {
        stat(it);
    }
}

void write(std::vector<statable>& doc, BufferData const& data)
{
    for (auto& it : doc) {
        write(it, data);
    }
}

void statPorts(std::vector<statable> const& ports) { stat(ports); }

void writePorts(std::vector<statable>& ports, BufferData const& data)
{
    write(ports, data);
}