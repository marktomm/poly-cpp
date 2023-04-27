#include "dev_ctx.h"
#include "dev_factory.h"

int main() {
    using namespace Enum;
    std::unique_ptr<Port> port(createTcpPort("localhost", 2404));
    readPort(port);
    return 0;
}