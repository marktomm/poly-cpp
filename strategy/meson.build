strategy_inc = include_directories('include')
strategy_main = 'src/user.cpp'
strategy_src = [
    'src/dev_impl.cpp',
    'src/dev_ctx.cpp',
    'src/dev_algo.cpp',
    'src/dev_factory.cpp',
]

executable(
    'strategy',
    [strategy_src, strategy_main],
    include_directories: strategy_inc,
    cpp_args: ['-std=c++17', '-O3', '-fno-rtti'],
    install: true,
)

executable(
    'strategy_rtti',
    [strategy_src, strategy_main],
    include_directories: strategy_inc,
    cpp_args: ['-std=c++17', '-O3'],
    install: true,
)
