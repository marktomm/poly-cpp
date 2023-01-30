type_erasure_up_inc = include_directories( './' )
type_erasure_up_src = ['user.cpp', 'dev_impl.cpp', 'dev_ctx.cpp', 'dev_algo.cpp', 'dev_factory.cpp']

executable('type_erasure_up', 
type_erasure_up_src, 
include_directories: type_erasure_up_inc,
cpp_args: ['-std=c++17', '-O3', '-fno-rtti'],
install : true)

executable('type_erasure_up_rtti', 
type_erasure_up_src, 
include_directories: type_erasure_up_inc,
cpp_args: ['-std=c++17', '-O3'],
install : true)
