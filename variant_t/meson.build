variant_t_inc = include_directories('include')
variant_t_main = 'src/user.cpp'
variant_t_src = [
    'src/dev_impl.cpp',
    'src/dev_ctx.cpp',
    'src/dev_algo.cpp',
    'src/dev_factory.cpp',
]

variant_t_exe = executable(
    'variant_t',
    [variant_t_src, variant_t_main],
    include_directories: [variant_t_inc, common_inc],
    install: true,
)


variant_t_o = variant_t_exe.extract_objects(variant_t_src)
