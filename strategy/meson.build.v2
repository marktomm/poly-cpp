
rootdir = '..'
currentdir = '.'
rootinc = join_paths(rootdir, 'include/')
currentinc = join_paths(currentdir, 'include/')
strategy_inc = include_directories(currentinc)
strategy_main = ['src/main.cpp']
# strategy_simple = ['src/user_simple.cpp']
strategy_src = [
    'src/lib.cpp',
]

strategy_exe = executable(
    'strategy_opt',
    [strategy_main, strategy_src],
    include_directories: [strategy_inc, common_inc],
    dependencies: [bench, thread],
    install: true,
    objects: [common_inc_opt_o],
)

strategy_exe_no_opt = executable(
    'strategy_no_opt',
    [strategy_main, strategy_src],
    include_directories: [strategy_inc, common_inc],
    dependencies: [bench, thread],
    install: true,
    cpp_args: ['-O0', '-g'],
    objects: [common_inc_opt_o],
)

strategy_inc_opt_o = strategy_exe.extract_objects(
    strategy_src,
)

strategy_main_opt_o = strategy_exe.extract_objects(
    strategy_main,
)

strategy_inc_o = strategy_inc_opt_o

strategy_inc_no_opt_o = strategy_exe_no_opt.extract_objects(
    strategy_src,
)

strategy_main_no_opt_o = strategy_exe_no_opt.extract_objects(
    strategy_main,
)

asandep = cpp.find_library('asan', dirs: '/usr/lib/x86_64-linux-gnu')

strategy_exe_sanitize = executable(
    'strategy_opt_sanitize',
    include_directories: [strategy_inc, common_inc],
    install: true,
    cpp_args: ['-O3', '-fsanitize=address'],
    dependencies: [asandep, bench, thread],
    link_args: ['-Wl,--start-group', '-lasan', '-Wl,--end-group'],
    objects: [strategy_main_opt_o, strategy_inc_opt_o, common_inc_opt_o],
)

strategy_exe_no_opt_sanitize = executable(
    'strategy_no_opt_sanitize',
    include_directories: [strategy_inc, common_inc],
    install: true,
    cpp_args: ['-O0', '-g', '-fsanitize=address'],
    dependencies: [asandep, bench, thread],
    link_args: ['-Wl,--start-group', '-lasan', '-Wl,--end-group'],
    objects: [strategy_main_no_opt_o, strategy_inc_no_opt_o, common_inc_opt_o],
)

if bench.found()
    strategy_benchmark_test = ['bench.cpp']

    strategy_benchmark_google_opt_exe = executable(
        'strategy_benchmark_google_opt',
        [strategy_benchmark_test],
        objects: [strategy_inc_opt_o, common_inc_opt_o],
        include_directories: [strategy_inc, common_inc],
        dependencies: [bench, thread],
    )

    benchmark(
        'strategy_benchmark_google_opt',
        strategy_benchmark_google_opt_exe,
        suite: 'strategy',
        timeout: 0,
    )

    strategy_benchmark_google_no_opt_exe = executable(
        'strategy_benchmark_google_no_opt',
        [strategy_benchmark_test],
        objects: [strategy_inc_no_opt_o, common_inc_opt_o],
        include_directories: [strategy_inc, common_inc],
        dependencies: [bench, thread],
        cpp_args: ['-O0', '-g'],
    )

    benchmark(
        'strategy_benchmark_google_no_opt',
        strategy_benchmark_google_no_opt_exe,
        suite: 'strategy',
        timeout: 0,
    )

    custom_target(
        'bench_strategy',
        command: [
            'sh',
            '-c', 'meson test --benchmark -C @BUILD_ROOT@ --suite strategy && cat @BUILD_ROOT@/meson-logs/testlog.txt',
        ],
        depends: [
            strategy_benchmark_google_no_opt_exe,
            strategy_benchmark_google_opt_exe,
        ],
        output: 'dummy_output.txt',
    )
endif

gen_asm = custom_target(
    'gen_asm_no_opt',
    input: strategy_main,
    output: 'strategy_main_no_opt.s',
    command: [
        cpp_prog,
        '-I' + meson.current_source_dir() + '/include/',
        '-I' + meson.current_source_dir() + '/../',
        '-S',
        '-masm=intel',
        '-o', '@OUTPUT@',
        '@INPUT@',
    ],
    build_by_default: true,
)

gen_asm_opt = custom_target(
    'gen_asm_opt',
    input: strategy_main,
    output: 'strategy_main_opt.s',
    command: [
        cpp_prog,
        '-O3', '-I' + meson.current_source_dir() + '/include/',
        '-I' + meson.current_source_dir() + '/../',
        '-S',
        '-masm=intel',
        '-o', '@OUTPUT@',
        '@INPUT@',
    ],
    build_by_default: true,
)

gen_asm_lib = custom_target(
    'gen_asm_lib_no_opt',
    input: strategy_src,
    output: 'strategy_lib_no_opt.s',
    command: [
        cpp_prog,
        '-I' + meson.current_source_dir() + '/include/',
        '-I' + meson.current_source_dir() + '/../',
        '-S',
        '-masm=intel',
        '-o', '@OUTPUT@',
        '@INPUT@',
    ],
    build_by_default: true,
)

gen_asm_lib_opt = custom_target(
    'gen_asm_lib_opt',
    input: strategy_src,
    output: 'strategy_lib_opt.s',
    command: [
        cpp_prog,
        '-O3', '-I' + meson.current_source_dir() + '/include/',
        '-I' + meson.current_source_dir() + '/../',
        '-S',
        '-masm=intel',
        '-o', '@OUTPUT@',
        '@INPUT@',
    ],
    build_by_default: true,
)
