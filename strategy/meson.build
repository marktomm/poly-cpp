strategy_inc = include_directories('include')
strategy_main = 'src/user.cpp'
strategy_src = [
    'src/dev_impl.cpp',
    'src/dev_ctx.cpp',
    'src/dev_algo.cpp',
    'src/dev_factory.cpp',
]

strategy_exe = executable(
    'strategy',
    [strategy_src, strategy_main],
    include_directories: [strategy_inc, common_inc],
    cpp_args: ['-std=c++17', '-O3', '-fno-rtti'],
    install: true,
)

strategy_inc_o = strategy_exe.extract_objects(strategy_src)

executable(
    'strategy_rtti',
    [strategy_src, strategy_main],
    include_directories: [strategy_inc, common_inc],
    cpp_args: ['-std=c++17', '-O3'],
    install: true,
)
