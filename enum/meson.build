enum_inc = include_directories('include')
enum_main = ['src/user.cpp']
enum_simple = ['src/user_simple.cpp']
enum_src = ['src/dev_impl.cpp', 'src/dev_ctx.cpp', 'src/dev_algo.cpp', 'src/dev_factory.cpp']

enum_exe = executable(
    'enum',
    [enum_main, enum_src],
    include_directories: [enum_inc, common_inc],
    cpp_args: ['-std=c++17', '-O3', '-fno-rtti'],
    install: true,
)

enum_inc_o = enum_exe.extract_objects(
    enum_src
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
