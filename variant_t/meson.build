variant_t_inc = include_directories('include')
variant_t_main = 'src/user.cpp'
variant_t_src = ['src/dev_impl.cpp', 'src/dev_ctx.cpp', 'src/dev_algo.cpp']

executable(
    'variant_t',
    [variant_t_src, variant_t_main],
    include_directories: [variant_t_inc, common_inc],
    cpp_args: ['-std=c++17', '-O3', '-fno-rtti'],
    install: true,
)

executable(
    'variant_t_rtti',
    [variant_t_src, variant_t_main],
    include_directories: [variant_t_inc, common_inc],
    cpp_args: ['-std=c++17', '-O3'],
    install: true,
)
