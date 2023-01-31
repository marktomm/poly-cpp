

oop_inc = include_directories('include')
oop_src = ['src/dev_impl.cpp', 'src/dev_ctx.cpp', 'src/dev_factory.cpp']
oop_main = 'src/user.cpp'

oop_exe = executable(
    'oop',
    [oop_src, oop_main],
    include_directories: [oop_inc, common_inc],
    cpp_args: ['-std=c++17', '-O3', '-fno-rtti'],
    install: true,
)

oop_inc_o = oop_exe.extract_objects(oop_src)

executable(
    'oop_rtti',
    [oop_src, oop_main],
    include_directories: [oop_inc, common_inc],
    cpp_args: ['-std=c++17', '-O3'],
    install: true,
)
