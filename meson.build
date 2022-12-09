project('c++ oop', 'cpp', default_options: ['strip=true'])

enum_inc = include_directories( 'enum/' )
enum_src = ['enum/user.cpp', 'enum/dev_impl.cpp', 'enum/dev_ctx.cpp', 'enum/dev_algo.cpp']

# bench = dependency('benchmark')
# thread = dependency('threads')

executable('enum', 
enum_src, 
include_directories: enum_inc,
# dependencies: [bench, thread], 
cpp_args: ['-std=c++17', '-O3', '-fno-rtti'],
install : true)

oop_inc = include_directories( 'oop/' )
oop_src = ['oop/user.cpp', 'oop/dev_impl.cpp', 'oop/dev_ctx.cpp']

executable('oop', 
oop_src, 
include_directories: oop_inc,
# dependencies: [bench, thread], 
cpp_args: ['-std=c++17', '-O3', '-fno-rtti'],
install : true)

visitor_inc = include_directories( 'visitor/' )
visitor_src = ['visitor/user.cpp', 'visitor/dev_impl.cpp', 'visitor/dev_ctx.cpp', 'visitor/dev_algo.cpp']

executable('visitor', 
visitor_src, 
include_directories: visitor_inc,
# dependencies: [bench, thread], 
cpp_args: ['-std=c++17', '-O3', '-fno-rtti'],
install : true)

variant_t_inc = include_directories( 'variant_t/' )
variant_t_src = ['variant_t/user.cpp', 'variant_t/dev_impl.cpp', 'variant_t/dev_ctx.cpp', 'variant_t/dev_algo.cpp']

executable('variant_t', 
variant_t_src, 
include_directories: variant_t_inc,
# dependencies: [bench, thread], 
cpp_args: ['-std=c++17', '-O3', '-fno-rtti'],
install : true)

strategy_inc = include_directories( 'strategy/' )
strategy_src = ['strategy/user.cpp', 'strategy/dev_impl.cpp', 'strategy/dev_ctx.cpp', 'strategy/dev_algo.cpp']

executable('strategy', 
strategy_src, 
include_directories: strategy_inc,
# dependencies: [bench, thread], 
cpp_args: ['-std=c++17', '-O3', '-fno-rtti'],
install : true)

type_erasure_up_inc = include_directories( 'type_erasure_up/' )
type_erasure_up_src = ['type_erasure_up/user.cpp', 'type_erasure_up/dev_impl.cpp', 'type_erasure_up/dev_ctx.cpp', 'type_erasure_up/dev_algo.cpp']

executable('type_erasure_up', 
type_erasure_up_src, 
include_directories: type_erasure_up_inc,
# dependencies: [bench, thread], 
cpp_args: ['-std=c++17', '-O3', '-fno-rtti'],
install : true)