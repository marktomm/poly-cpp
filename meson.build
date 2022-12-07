project('c++ oop', 'cpp')

enum_inc = include_directories( 'enum/' )

enum_src = ['enum/user.cpp', 'enum/dev_impl.cpp', 'enum/dev_ext.cpp']

# bench = dependency('benchmark')
# thread = dependency('threads')

executable('enum', 
enum_src, 
include_directories: enum_inc,
# dependencies: [bench, thread], 
cpp_args: ['-std=c++17', '-O3'])