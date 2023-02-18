visitor_inc = include_directories('include')
visitor_main = 'src/user.cpp'
visitor_src = [
    'src/dev_impl.cpp',
    'src/dev_ctx.cpp',
    'src/dev_algo.cpp',
    'src/dev_factory.cpp',
]

visitor_exe = executable(
    'visitor',
    [visitor_main, visitor_src],
    include_directories: [visitor_inc, common_inc],
    install: true,
)

visitor_inc_o = visitor_exe.extract_objects(visitor_src)
