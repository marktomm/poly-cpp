variant_t_inc = include_directories( './' )
variant_t_src = ['user.cpp', 'dev_impl.cpp', 'dev_ctx.cpp', 'dev_algo.cpp']

executable('variant_t', 
variant_t_src, 
include_directories: variant_t_inc,
cpp_args: ['-std=c++17', '-O3', '-fno-rtti'],
install : true)

executable('variant_t_rtti', 
variant_t_src, 
include_directories: variant_t_inc,
cpp_args: ['-std=c++17', '-O3'],
install : true)
