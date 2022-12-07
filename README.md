# install

requirements: meson

```
meson build && cd build && ninja
```

# enum

dev impl:
1 necessary var `type_` (impl has options `GetType`)
type must use inheritance

poly ctx:
ptr usage
static_cast
use `type_/GetType()`

user:
pointer semantics