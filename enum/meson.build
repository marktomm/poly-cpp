enum_inc = include_directories('./')
enum_main = ['user.cpp']
enum_simple = ['user_simple.cpp']
enum_src = ['dev_impl.cpp', 'dev_ctx.cpp', 'dev_algo.cpp', 'dev_factory.cpp']

enum_exe = executable(
    'enum',
    [enum_main, enum_src],
    include_directories: [enum_inc, common_inc],
    cpp_args: ['-std=c++17', '-O3', '-fno-rtti'],
    install: true,
)

executable(
    'enum_rtti',
    [enum_main, enum_src],
    include_directories: [enum_inc, common_inc],
    cpp_args: ['-std=c++17', '-O3'],
    install: true,
)

executable(
    'enum_simple',
    [enum_simple, enum_src],
    include_directories: [enum_inc, common_inc],
    cpp_args: ['-std=c++17', '-O3', '-fno-rtti'],
    install: true,
)

executable(
    'enum_simple_rtti',
    [enum_simple, enum_src],
    include_directories: [enum_inc, common_inc],
    cpp_args: ['-std=c++17', '-O3'],
    install: true,
)
