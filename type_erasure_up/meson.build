type_erasure_up_inc = include_directories('include')
type_erasure_up_main = 'src/user.cpp'
type_erasure_up_src = [
    'src/dev_impl.cpp',
    'src/dev_ctx.cpp',
    'src/dev_algo.cpp',
    'src/dev_factory.cpp',
]

executable(
    'type_erasure_up',
    [type_erasure_up_src, type_erasure_up_main],
    include_directories: [type_erasure_up_inc, common_inc],
    cpp_args: ['-std=c++17', '-O3', '-fno-rtti'],
    install: true,
)

executable(
    'type_erasure_up_rtti',
    [type_erasure_up_src, type_erasure_up_main],
    include_directories: [type_erasure_up_inc, common_inc],
    cpp_args: ['-std=c++17', '-O3'],
    install: true,
)
