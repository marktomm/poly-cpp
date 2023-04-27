common_src = ['src/common.cpp']

benchmarks_inc = include_directories('include')

objectsArray = [
    enum_inc_o,
    oop_inc_o,
    visitor_inc_o,
    strategy_inc_o,
    variant_t_o,
    type_erasure_up_o,
]
includesArray = [
    enum_inc,
    common_inc,
    oop_inc,
    visitor_inc,
    benchmarks_inc,
]

if bench.found()
    benchmark_test = ['src/benchmark_google.cpp']

    benchmark_google_opt_exe = executable(
        'benchmark_google_opt',
        [benchmark_test, common_src],
        objects: objectsArray,
        include_directories: includesArray,
        dependencies: [bench, thread],
    )

    test('benchmark_google_opt', benchmark_google_opt_exe, is_parallel: false)

    benchmark_google_no_opt_exe = executable(
        'benchmark_google_no_opt',
        [benchmark_test, common_src],
        objects: objectsArray,
        include_directories: includesArray,
        dependencies: [bench, thread],
        cpp_args: ['-O0', '-g'],
    )

    test(
        'benchmark_google_no_opt',
        benchmark_google_no_opt_exe,
        is_parallel: false,
    )
endif

benchmark_tr18015_test = ['src/benchmark_tr18015.cpp']

benchmark_tr18015_opt_exe = executable(
    'benchmark_tr18015_opt',
    [benchmark_tr18015_test, common_src],
    objects: objectsArray,
    include_directories: includesArray,
)

test(
    'benchmark_tr18015_opt',
    benchmark_tr18015_opt_exe,
    is_parallel: false,
)
