
rootdir = '..'
currentdir = '.'
rootinc = join_paths(rootdir, 'include/')
currentinc = join_paths(currentdir, 'include/')
visitor_inc = include_directories(currentinc)
visitor_main = ['src/main.cpp']
# visitor_simple = ['src/user_simple.cpp']
visitor_src = [
    'src/lib.cpp',
]

visitor_exe = executable(
    'visitor_opt',
    [visitor_main, visitor_src],
    include_directories: [visitor_inc, common_inc],
    dependencies: [bench, thread],
    install: true,
    objects: [common_inc_opt_o],
)

visitor_exe_no_opt = executable(
    'visitor_no_opt',
    [visitor_main, visitor_src],
    include_directories: [visitor_inc, common_inc],
    dependencies: [bench, thread],
    install: true,
    cpp_args: ['-O0', '-g'],
    objects: [common_inc_no_opt_o],
)

visitor_inc_opt_o = visitor_exe.extract_objects(
    visitor_src,
)

visitor_main_opt_o = visitor_exe.extract_objects(
    visitor_main,
)

visitor_inc_o = visitor_inc_opt_o

visitor_inc_no_opt_o = visitor_exe_no_opt.extract_objects(
    visitor_src,
)

visitor_main_no_opt_o = visitor_exe_no_opt.extract_objects(
    visitor_main,
)

asandep = cpp.find_library('asan', dirs: '/usr/lib/x86_64-linux-gnu')

visitor_exe_sanitize = executable(
    'visitor_opt_sanitize',
    include_directories: [visitor_inc, common_inc],
    install: true,
    cpp_args: ['-O3', '-fsanitize=address'],
    dependencies: [asandep, bench, thread],
    link_args: ['-Wl,--start-group', '-lasan', '-Wl,--end-group'],
    objects: [
        visitor_main_opt_o, 
        visitor_inc_opt_o, 
        common_inc_opt_o
    ],
)

visitor_exe_no_opt_sanitize = executable(
    'visitor_no_opt_sanitize',
    include_directories: [visitor_inc, common_inc],
    install: true,
    cpp_args: ['-O0', '-g', '-fsanitize=address'],
    dependencies: [asandep, bench, thread],
    link_args: ['-Wl,--start-group', '-lasan', '-Wl,--end-group'],
    objects: [
        visitor_main_no_opt_o, 
        visitor_inc_no_opt_o, 
        common_inc_no_opt_o
    ],
)

if bench.found()
    visitor_benchmark_test = ['bench.cpp']

    visitor_benchmark_google_opt_exe = executable(
        'visitor_benchmark_google_opt',
        [visitor_benchmark_test],
        objects: [visitor_inc_opt_o, common_inc_opt_o],
        include_directories: [visitor_inc, common_inc],
        dependencies: [bench, thread],
    )

    benchmark(
        'visitor_benchmark_google_opt',
        visitor_benchmark_google_opt_exe,
        suite: 'visitor',
        timeout: 0,
    )

    visitor_benchmark_google_no_opt_exe = executable(
        'visitor_benchmark_google_no_opt',
        [visitor_benchmark_test],
        objects: [visitor_inc_no_opt_o, common_inc_no_opt_o],
        include_directories: [visitor_inc, common_inc],
        dependencies: [bench, thread],
        cpp_args: ['-O0', '-g'],
    )

    benchmark(
        'visitor_benchmark_google_no_opt',
        visitor_benchmark_google_no_opt_exe,
        suite: 'visitor',
        timeout: 0,
    )

    custom_target(
        'bench_visitor',
        command: [
            'sh',
            '-c', 'meson test --benchmark -C @BUILD_ROOT@ --suite visitor && cat @BUILD_ROOT@/meson-logs/testlog.txt',
        ],
        depends: [
            visitor_benchmark_google_no_opt_exe,
            visitor_benchmark_google_opt_exe,
        ],
        output: 'dummy_output.txt',
    )
endif

gen_asm = custom_target(
    'gen_asm_no_opt',
    input: visitor_main,
    output: 'visitor_main_no_opt.s',
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
    input: visitor_main,
    output: 'visitor_main_opt.s',
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
    input: visitor_src,
    output: 'visitor_lib_no_opt.s',
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
    input: visitor_src,
    output: 'visitor_lib_opt.s',
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
