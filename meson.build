project('c++ oop', 'cpp', default_options: ['strip=true'])

common_inc = include_directories('common/')
common_src = ['common/bench.cpp']

bench = dependency('benchmark', required: false)
thread = dependency('threads')

subdir('enum')
subdir('oop')
subdir('visitor')
subdir('variant_t')
subdir('strategy')
subdir('type_erasure_up')

enum_inc_o = enum_exe.extract_objects(
    'dev_impl.cpp',
    'dev_algo.cpp',
    'dev_ctx.cpp',
    'dev_factory.cpp',
)
oop_inc_o = oop_exe.extract_objects(
    'dev_impl.cpp',
    'dev_ctx.cpp',
    'dev_factory.cpp',
)
visitor_inc_o = visitor_exe.extract_objects(
    'dev_impl.cpp',
    'dev_algo.cpp',
    'dev_ctx.cpp',
    'dev_factory.cpp',
)

if bench.found()
    benchmark_test = ['benchmark.cpp']

    benchmark_test_O3_exe = executable(
        'benchmark_test_O3',
        [benchmark_test],
        objects: [enum_inc_o, oop_inc_o, visitor_inc_o],
        include_directories: [enum_inc, common_inc, oop_inc, visitor_inc],
        dependencies: [bench, thread],
        cpp_args: ['-std=c++17', '-O3'],
    )

    test('enum benchmark O3', benchmark_test_O3_exe, is_parallel: false)

    benchmark_test_O0_exe = executable(
        'benchmark_test_O0',
        [benchmark_test],
        objects: [enum_inc_o, oop_inc_o, visitor_inc_o],
        include_directories: [enum_inc, common_inc, oop_inc, visitor_inc],
        dependencies: [bench, thread],
        cpp_args: ['-std=c++17', '-O0', '-g'],
    )

    test('enum benchmark O0', benchmark_test_O0_exe, is_parallel: false)
endif

benchmark_custom_test = ['benchmark_custom.cpp']

benchmark_custom_test_03_exe = executable(
    'benchmark_custom_test_O3',
    [benchmark_custom_test, common_src],
    objects: [enum_inc_o, oop_inc_o, visitor_inc_o],
    include_directories: [enum_inc, common_inc, oop_inc, visitor_inc],
    cpp_args: ['-std=c++17', '-O3', '-g'],
)

test(
    'enum benchmark custom O3',
    benchmark_custom_test_03_exe,
    is_parallel: false,
)

benchmark_custom_enum_test = ['benchmark_custom_enum.cpp']

benchmark_custom_enum_test_03_exe = executable(
    'benchmark_custom_enum_test_O3',
    [benchmark_custom_test, common_src],
    objects: [enum_inc_o, oop_inc_o, visitor_inc_o],
    include_directories: [enum_inc, common_inc, oop_inc, visitor_inc],
    cpp_args: ['-std=c++17', '-O3', '-g'],
)

test(
    'enum benchmark custom O3 enum',
    benchmark_custom_enum_test_03_exe,
    is_parallel: false,
)

benchmark_custom_oop_test = ['benchmark_custom_oop.cpp']

benchmark_custom_oop_test_03_exe = executable(
    'benchmark_custom_oop_test_O3',
    [benchmark_custom_oop_test, common_src],
    objects: [enum_inc_o, oop_inc_o, visitor_inc_o],
    include_directories: [enum_inc, common_inc, oop_inc, visitor_inc],
    cpp_args: ['-std=c++17', '-O3', '-g'],
)

test(
    'enum benchmark custom O3 oop',
    benchmark_custom_oop_test_03_exe,
    is_parallel: false,
)

benchmark_custom_visit_test = ['benchmark_custom_visit.cpp']

benchmark_custom_visit_test_03_exe = executable(
    'benchmark_custom_visit_test_O3',
    [benchmark_custom_visit_test, common_src],
    objects: [enum_inc_o, oop_inc_o, visitor_inc_o],
    include_directories: [enum_inc, common_inc, oop_inc, visitor_inc],
    cpp_args: ['-std=c++17', '-O3', '-g'],
)

test(
    'enum benchmark custom O3 visit',
    benchmark_custom_visit_test_03_exe,
    is_parallel: false,
)
