project('c++ oop', 'cpp', default_options: ['strip=true'])

common_inc = include_directories('common/', './')

bench = dependency('benchmark', required: false)
thread = dependency('threads')

subdir('enum')
subdir('oop')
subdir('visitor')
subdir('variant_t')
subdir('strategy')
subdir('type_erasure_up')
subdir('benchmarks')
