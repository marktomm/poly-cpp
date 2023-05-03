#ifndef MACRO_common_LIB_H
#define MACRO_common_LIB_H

#include <cstdint>
#include <vector>

using MutableBuffer = uint32_t;
using BufferData = uint32_t;

namespace common {

using vb = std::vector<bool>;
using vu32 = std::vector<uint32_t>;

// GEN_PROTO_BEGIN
int getRandom12();
int getRandom13();
std::size_t GetNextGlobalIndex();
vb GetGlobalRandBoolVec();
void emptyFn();
void emptyFnInt();
vu32 GetGlobalRandIntVec();
// GEN_PROTO_END

}; // namespace common

#endif
