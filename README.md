# install

requirements: meson and a compiler

```
meson build && cd build && ninja

# list all executables (after prev command that cd'd into build)
find -maxdepth 1 -executable -type f
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
* 1/9
* base header requires changes: enum needs addition of new enum type
* polymorphic context/zone/region requires changes: all switch statements need addition of new case.

Adding operations:
* 7/9
* adding free functions

SRP:
* 5/9

Simplicity:
* 5/9
* client must use pointers
* base class inheritance
* base class ctor needs to be initialized with specific enum per new type

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

* base class using pure virtual functions
* (OCP - fnality) algorithms (methods) tightly coupled with type implementation classes
* (OCP - fnality) if add new pure virtual function everything breaks until every existing implementation class is adjusted.
* (OCP - structure) hierarchy remains open-ended even accross ABI boundaries, it is possible to add new types

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

# type erasure

https://stlab.cc/legacy/runtime-concepts.html
https://www.stroustrup.com/oops08.pdf
https://dawnofgiants.com/blog/runtime-concept-idiom

# Benchmarks

K. Iglberger:
* 100 random shapes, 2.5M updates each
* Compilation flags: -std=c++17 -O3 -DNDEBUG