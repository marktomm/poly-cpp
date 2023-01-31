visitor_inc = include_directories('include')
visitor_main = 'src/user.cpp'
visitor_src = ['src/dev_impl.cpp', 'src/dev_ctx.cpp', 'src/dev_algo.cpp', 'src/dev_factory.cpp']

visitor_exe = executable(
    'visitor',
    [visitor_main, visitor_src],
    include_directories: [visitor_inc, common_inc],
    cpp_args: ['-std=c++17', '-O3', '-fno-rtti'],
    install: true,
)

visitor_inc_o = visitor_exe.extract_objects(
    visitor_src
)

executable(
    'visitor_rtti',
    [visitor_main, visitor_src],
    include_directories: [visitor_inc, common_inc],
    cpp_args: ['-std=c++17', '-O3'],
    install: true,
)
