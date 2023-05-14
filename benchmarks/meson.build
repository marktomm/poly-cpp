benchmarks_common_src = []

benchmarks_inc = include_directories('include')

objectsArrayOpt = [
    enum_type_inc_o,
    oop_inc_o,
    visitor_inc_o,
    strategy_inc_o,
    variant_t_inc_o,
    type_erasure_up_inc_o,
    common_inc_o,
]

objectsArrayNoOpt = [
    enum_type_inc_no_opt_o,
    oop_inc_no_opt_o,
    visitor_inc_no_opt_o,
    strategy_inc_no_opt_o,
    variant_t_inc_no_opt_o,
    type_erasure_up_inc_no_opt_o,
    common_inc_no_opt_o,
]

objectsArrayNoOpt = objectsArrayOpt

includesArray = [
    enum_type_inc,
    common_inc,
    oop_inc,
    visitor_inc,
    strategy_inc,
    variant_t_inc,
    type_erasure_up_inc,
    benchmarks_inc,
]

if bench.found()
    benchmark_test = ['src/benchmark_google.cpp']

    benchmark_google_opt_exe = executable(
        'benchmarks_benchmark_google_opt',
        [benchmark_test, benchmarks_common_src],
        objects: objectsArrayOpt,
        include_directories: includesArray,
        dependencies: [bench, thread],
    )

    benchmark(
        'benchmarks_benchmark_google_opt',
        benchmark_google_opt_exe,
        timeout: 0,
    )

    benchmark_google_no_opt_exe = executable(
        'benchmarks_benchmark_google_no_opt',
        [benchmark_test, benchmarks_common_src],
        objects: objectsArrayNoOpt,
        include_directories: includesArray,
        dependencies: [bench, thread],
        cpp_args: ['-O0', '-g'],
    )

    benchmark(
        'benchmarks_benchmark_google_no_opt',
        benchmark_google_no_opt_exe,
        timeout: 0,
    )
endif

# benchmark_tr18015_test = ['src/benchmark_tr18015.cpp']

# benchmark_tr18015_opt_exe = executable(
#     'benchmark_tr18015_opt',
#     [benchmark_tr18015_test, benchmarks_common_src],
#     objects: objectsArrayOpt,
#     include_directories: includesArray,
# )

# benchmark('benchmark_tr18015_opt', benchmark_tr18015_opt_exe, timeout: 0)

# benchmark_tr18015_no_opt_exe = executable(
#     'benchmark_tr18015_no_opt',
#     [benchmark_tr18015_test, benchmarks_common_src],
#     objects: objectsArrayOpt,
#     include_directories: includesArray,
# )

# benchmark('benchmark_tr18015_no_opt', benchmark_tr18015_no_opt_exe, timeout: 0)
