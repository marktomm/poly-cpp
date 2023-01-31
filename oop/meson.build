

oop_inc = include_directories('./')
oop_src = ['dev_impl.cpp', 'dev_ctx.cpp', 'dev_factory.cpp']
oop_main = 'user.cpp'

oop_exe = executable(
    'oop',
    [oop_src, oop_main],
    include_directories: [oop_inc, common_inc],
    cpp_args: ['-std=c++17', '-O3', '-fno-rtti'],
    install: true,
)

executable(
    'oop_rtti',
    [oop_src, oop_main],
    include_directories: [oop_inc, common_inc],
    cpp_args: ['-std=c++17', '-O3'],
    install: true,
)
