#include "lib.h"

#include <algorithm>
#include <random>

static void escape(void* p) { asm volatile("" : : "g"(p) : "memory"); }

using namespace std;

namespace common {
const int randomRange12 = 2; // Give me a number between 0 and 2.
const int errorInt = 0;      // Stop every time the number is 0.
int getRandom12() { return static_cast<int>(random()) % randomRange12; }
const int randomRange13 = 2; // Give me a number between 0 and 2.
int getRandom13() { return static_cast<int>(random()) % randomRange13; }

vu32 GetGlobalRandIntVec() {
    static bool setupDone = false;
    static vector<uint32_t> v(common::VCOUNT);
    if (setupDone) {
        return v;
    }
    random_device rd;
    mt19937 generator(rd());
    generate(v.begin(), v.end(), [n = 0]() mutable { return n++; });
    shuffle(v.begin(), v.end(), generator);
    setupDone = true;
    return v;
}

vb GetGlobalRandBoolVec() {
    static bool randomDone = false;
    static std::vector<bool> bools(common::VCOUNT);

    if (randomDone) {
        return bools;
    }
    auto v = GetGlobalRandIntVec();

    for (uint32_t i = 0; i < common::VCOUNTHALF; ++i) {
        bools[v[i]] = true;
    }
    for (uint32_t i = common::VCOUNTHALF; i < common::VCOUNT; ++i) {
        bools[v[i]] = false;
    }

    randomDone = true;
    return bools;
}

std::size_t GetNextGlobalIndex() {
    static std::size_t it = 0;
    return (++it == common::VCOUNT ? it = 1 : it);
}

void emptyFn(){};

void emptyFnInt() {
    int x = 1;
    escape(&x);
};

} // namespace common
