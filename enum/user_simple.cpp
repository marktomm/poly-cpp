#include "dev_ctx.h"
#include "dev_factory.h"

int main()
{
    std::unique_ptr<Port> port(CreateTcpPort("localhost", 2404));
    statPort(port);
    return 0;
}