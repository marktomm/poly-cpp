# poly-cpp

A hand full of popular approaches to achieving polymorphism in C++ with benchmarks

1. enum
1. oop
1. strategy - using std::function
1. visitor
1. variant_t - using std::variant
1. type_erasure_up - "Runtime concept" or "Type erasure" using uniqute_ptr to non-const type

# install

requirements: meson and a compiler

```bash
meson setup builddir && ninja test -C builddir

# list all executables (after prev command that cd'd into build)
find builddir -maxdepth 2 -executable -type f
```

# generate documentaion

requirements: doxygen and graphviz

```
# run with -r argument if any .h or .cpp files were changed
./generate_docs.sh

# replace enum for any other executable name created by meson
# substitue webbrowser for chromium or what you got
webbrowser enum/.docs/.temp/html/index.html
```

# enum

C like procedural solution - K. Iglberger

It is structure, but no behaviour - J. Lucas

K. Iglberger:

Addition of new types (structural OCP):

- 1/9
- base header requires changes: enum needs addition of new enum type
- polymorphic context/zone/region requires changes: all switch statements need addition of new case.

Adding operations:

- 7/9
- adding free functions

SRP:

- 5/9

Simplicity:

- 5/9
- client must use pointers
- base class inheritance
- base class ctor needs to be initialized with specific enum per new type

dev impl:

1. base has 1 necessary var `type_` (impl has optional `GetType`)
1. base non-default ctor
1. type must use inheritance

poly ctx:

1. ptr usage
1. static_cast
1. use `type_/GetType()`

user:

1. pointer semantics

# oop

J. Lucas

- base class using pure virtual functions
- (OCP - fnality) algorithms (methods) tightly coupled with type implementation classes
- (OCP - fnality) if add new pure virtual function everything breaks until every existing implementation class is adjusted.
- (OCP - structure) hierarchy remains open-ended even accross ABI boundaries, it is possible to add new types

K. Iglberger:

Addition of new types (structural OCP):

Adding operations:

SRP:
besides inheritance in type itself, the functionality aspect is tightly coupled with type

Simplicity:
same as enum approach

dev impl:

1. base class abstract
1. type must use inheritance

poly ctx:

1. ptr usage

user:

1. pointer semantics

# Visitor

There are other ways to implement double dispatch in C++. Item 31 of Scott Meyer's "More Effective C++" treats this subject in depth.

K. Iglberger: Allow to easily add new functionality.

types are closed set

types do not implement functionality

visitor is kind of an operation

visitor knows all the types (closed set)

type get an `accept(visitor v)` function

overhead: 2 virtual functions: 1 for accept and 2nd in the visitor

J. Lucas: Visitor groups concerns together

only 1 virtual function which is the visitor acceptor and all of the algorithms group their bits together, i.e. they type switch behaviour

separate team working on structural changes which will require updates to all the algorithms but at least the compiler can tell.

people working on the algorithms work in silos

hierarchy is sealed, no possibility to extend it accross ABI boundaries, but it is possible to add algorithms. I.e. it is possible to extend the behavior but not types.

Requires specific ordering:

1. visitor is forward declared
1. finals are declared
1. visitor acceptors are defined
1. algorithms are defined

# variant

https://www.cppstories.com/2018/09/visit-variants/

# type erasure

https://stlab.cc/legacy/runtime-concepts.html
https://www.stroustrup.com/oops08.pdf
https://dawnofgiants.com/blog/runtime-concept-idiom

# Benchmarks

K. Iglberger:

- 100 random shapes, 2.5M updates each
- Compilation flags: -std=c++17 -O3 -DNDEBUG

# Notes

```bash
diff -u <(readelf --symbols -C enum  | sed 's/^ *[0-9]*://')  <(readelf --symbols -C enum_rtti | sed 's/^ *[0-9]*://')
diff -u <(objdump -d enum) <(objdump -d enum_rtti)
```

# Users

initial developer implements the mechanism that enables type use in polymorphic context

"dependant developer"/"library extension developer" adds new types and functionality. Depending on the approach of "initial developer" extending types and/or functionality may require modifications/additions to initial source and recompile/relink. Ideally having read-only readers and shared library is sufficient.

end-user uses factory methods to populate own data structures and uses API that hides polymorphic use

# Benchmark notes

```cpp
#include <benchmark/benchmark.h>

// DoNotOptimize
static void escape(void* p) { asm volatile("" : : "g"(p) : "memory"); }

// ClobberMemory
static void clobber() { asm volatile("" : : : "memory"); }

void SomeFunction()
{
    int a = 1;
    int b = 2;
    int c = 0;

    // https://youtu.be/nXaxk27zwlk?t=2440
    // https://github.com/google/benchmark/blob/v1.7.1/docs/user_guide.md
    benchmark::DoNotOptimize(c = a + b);
    benchmark::ClobberMemory();
}
```

```shell
cd benchmark/tools
# ubuntu
sudo apt install -y python3-pip
pip3 install -r requirements.txt
./compare.py benchmarks  ../../build/benchmark_test_O3 ../../build/benchmark_test_O3
```

# objdump

`objdump -DSsgCw --visualize-jumps -M intel`

# gcc shared compilation

```bash
#!/bin/bash

g++ -g -ggdb -c shared.cpp -o shared.o
g++ -shared -fPIC -o libshared.so shared.o

g++ -g -ggdb -c main.cpp -o main.o
g++ -g -ggdb -o main main.o -L. -lshared
```
