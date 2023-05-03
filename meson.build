project(
    'poly-cpp',
    'cpp',
    default_options: [
        'strip=true',
        'c_std=c11',
        'cpp_std=c++17',
        'optimization=3',
        'warning_level=3',
        'werror=true',
        'cpp_args=-Wshadow -Wconversion -Wpedantic',
        'debug=false',
    ],
)

cpp = meson.get_compiler('cpp')
cpp_prog = find_program(cpp.get_id())

bench = dependency('benchmark', required: false)
thread = dependency('threads')

common_inc = include_directories('common/', './')
common_src = []

subdir('oop')
subdir('visitor')
subdir('variant_t')
subdir('strategy')
subdir('type_erasure_up')

subdir('enum_type')

# subdir('benchmarks')
subdir('common')
