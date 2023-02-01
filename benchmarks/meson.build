common_src = ['src/common.cpp']

benchmarks_inc = include_directories('include')

if bench.found()
    benchmark_test = ['src/benchmark_google.cpp']

    benchmark_google_opt_exe = executable(
        'benchmark_google_opt',
        [benchmark_test],
        objects: [enum_inc_o, oop_inc_o, visitor_inc_o, strategy_inc_o, variant_t_o, type_erasure_up_o],
        include_directories: [
            enum_inc,
            common_inc,
            oop_inc,
            visitor_inc,
            benchmarks_inc,
        ],
        dependencies: [bench, thread],
        cpp_args: ['-std=c++17', '-O3'],
    )

    test('benchmark_google_opt', benchmark_google_opt_exe, is_parallel: false)

    benchmark_google_no_opt_exe = executable(
        'benchmark_google_no_opt',
        [benchmark_test],
        objects: [enum_inc_o, oop_inc_o, visitor_inc_o, strategy_inc_o, variant_t_o, type_erasure_up_o],
        include_directories: [
            enum_inc,
            common_inc,
            oop_inc,
            visitor_inc,
            benchmarks_inc,
        ],
        dependencies: [bench, thread],
        cpp_args: ['-std=c++17', '-O0', '-g'],
    )

    test('benchmark_google_no_opt', benchmark_google_no_opt_exe, is_parallel: false)
endif

benchmark_tr18015_test = ['src/benchmark_tr18015.cpp']

benchmark_tr18015_opt_exe = executable(
    'benchmark_tr18015_opt',
    [benchmark_tr18015_test, common_src],
    objects: [enum_inc_o, oop_inc_o, visitor_inc_o, strategy_inc_o, variant_t_o, type_erasure_up_o],
    include_directories: [
        enum_inc,
        common_inc,
        oop_inc,
        visitor_inc,
        benchmarks_inc,
    ],
    cpp_args: ['-std=c++17', '-O3', '-g'],
)

test(
    'benchmark_tr18015_opt',
    benchmark_tr18015_opt_exe,
    is_parallel: false,
)

benchmark_tr18015_enum = ['src/benchmark_tr18015_enum.cpp']

benchmark_tr18015_enum_opt_exe = executable(
    'benchmark_tr18015_enum_opt',
    [benchmark_tr18015_enum, common_src],
    objects: [enum_inc_o, oop_inc_o, visitor_inc_o, strategy_inc_o, variant_t_o, type_erasure_up_o],
    include_directories: [
        enum_inc,
        common_inc,
        oop_inc,
        visitor_inc,
        benchmarks_inc,
    ],
    cpp_args: ['-std=c++17', '-O3', '-g'],
)

test(
    'benchmark_tr18015_enum_opt',
    benchmark_tr18015_enum_opt_exe,
    is_parallel: false,
)

benchmark_tr18015_oop = ['src/benchmark_tr18015_oop.cpp']

benchmark_tr18015_oop_opt_exe = executable(
    'benchmark_tr18015_oop_opt',
    [benchmark_tr18015_oop, common_src],
    objects: [enum_inc_o, oop_inc_o, visitor_inc_o, strategy_inc_o, variant_t_o, type_erasure_up_o],
    include_directories: [
        enum_inc,
        common_inc,
        oop_inc,
        visitor_inc,
        benchmarks_inc,
    ],
    cpp_args: ['-std=c++17', '-O3', '-g'],
)

test(
    'benchmark_tr18015_oop_opt',
    benchmark_tr18015_oop_opt_exe,
    is_parallel: false,
)

benchmark_tr18015_visit = ['src/benchmark_tr18015_visit.cpp']

benchmark_tr18015_visit_opt_exe = executable(
    'benchmark_tr18015_visit_opt',
    [benchmark_tr18015_visit, common_src],
    objects: [enum_inc_o, oop_inc_o, visitor_inc_o, strategy_inc_o, variant_t_o, type_erasure_up_o],
    include_directories: [
        enum_inc,
        common_inc,
        oop_inc,
        visitor_inc,
        benchmarks_inc,
    ],
    cpp_args: ['-std=c++17', '-O3', '-g'],
)

test(
    'benchmark_tr18015_visit_opt',
    benchmark_tr18015_visit_opt_exe,
    is_parallel: false,
)
