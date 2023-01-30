visitor_inc = include_directories( './' )
visitor_main = 'user.cpp'
visitor_src = ['dev_impl.cpp', 'dev_ctx.cpp', 'dev_algo.cpp', 'dev_factory.cpp']

executable('visitor', 
[visitor_main, visitor_src], 
include_directories: visitor_inc,
cpp_args: ['-std=c++17', '-O3', '-fno-rtti'],
install : true)

executable('visitor_rtti', 
[visitor_main, visitor_src], 
include_directories: visitor_inc,
cpp_args: ['-std=c++17', '-O3'],
install : true)
