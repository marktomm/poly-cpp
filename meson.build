project('c++ oop', 'cpp')

enum_inc = include_directories( 'enum/' )
enum_src = ['enum/user.cpp', 'enum/dev_impl.cpp', 'enum/dev_ctx.cpp', 'enum/dev_algo.cpp']

# bench = dependency('benchmark')
# thread = dependency('threads')

executable('enum', 
enum_src, 
include_directories: enum_inc,
# dependencies: [bench, thread], 
cpp_args: ['-std=c++17', '-O3'])

oop_inc = include_directories( 'oop/' )
oop_src = ['oop/user.cpp', 'oop/dev_impl.cpp', 'oop/dev_ctx.cpp']

executable('oop', 
oop_src, 
include_directories: oop_inc,
# dependencies: [bench, thread], 
cpp_args: ['-std=c++17', '-O3'])

visitor_inc = include_directories( 'visitor/' )
visitor_src = ['visitor/user.cpp', 'visitor/dev_impl.cpp', 'visitor/dev_ctx.cpp']

executable('visitor', 
visitor_src, 
include_directories: visitor_inc,
# dependencies: [bench, thread], 
cpp_args: ['-std=c++17', '-O3'])

visitor_2_inc = include_directories( 'visitor_2/' )
visitor_2_src = ['visitor_2/user.cpp', 'visitor_2/dev_impl.cpp', 'visitor_2/dev_ctx.cpp', 'visitor_2/dev_algo.cpp']

executable('visitor_2', 
visitor_2_src, 
include_directories: visitor_2_inc,
# dependencies: [bench, thread], 
cpp_args: ['-std=c++17', '-O3'])