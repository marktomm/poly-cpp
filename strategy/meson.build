strategy_inc = include_directories('./')
strategy_src = [
    'user.cpp',
    'dev_impl.cpp',
    'dev_ctx.cpp',
    'dev_algo.cpp',
    'dev_factory.cpp',
]

executable(
    'strategy',
    strategy_src,
    include_directories: strategy_inc,
    cpp_args: ['-std=c++17', '-O3', '-fno-rtti'],
    install: true,
)

executable(
    'strategy_rtti',
    strategy_src,
    include_directories: strategy_inc,
    cpp_args: ['-std=c++17', '-O3'],
    install: true,
)
