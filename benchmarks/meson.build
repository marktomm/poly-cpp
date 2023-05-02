benchmarks_common_src = ['src/common.cpp']

benchmarks_inc = include_directories('include')

objectsArrayOpt = [
    enum_type_inc_o,
    oop_inc_o,
    visitor_inc_o,
    strategy_inc_o,
    variant_t_inc_o,
    type_erasure_up_inc_o,
]

# objectsArrayNoOpt = [
#     enum_type_inc_no_opt_o,
#     oop_inc_inc_no_opt_o,
#     visitor_inc_no_opt_o,
#     strategy_inc_no_opt_o,
#     variant_t_inc_no_opt_o,
#     type_erasure_up_inc_no_opt_o,
# ]

objectsArrayNoOpt = objectsArrayOpt

includesArray = [
    enum_type_inc,
    common_inc,
    oop_inc,
    visitor_inc,
    benchmarks_inc,
]

if bench.found()
    benchmark_test = ['src/benchmark_google.cpp']

    benchmark_google_opt_exe = executable(
        'benchmark_google_opt',
        [benchmark_test, benchmarks_common_src],
        objects: objectsArrayOpt,
        include_directories: includesArray,
        dependencies: [bench, thread],
    )

    test('benchmark_google_opt', benchmark_google_opt_exe, is_parallel: false)

    benchmark_google_no_opt_exe = executable(
        'benchmark_google_no_opt',
        [benchmark_test, benchmarks_common_src],
        objects: objectsArrayOpt,
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
    [benchmark_tr18015_test, benchmarks_common_src],
    objects: objectsArrayOpt,
    include_directories: includesArray,
)

test(
    'benchmark_tr18015_opt',
    benchmark_tr18015_opt_exe,
    is_parallel: false,
)
