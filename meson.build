project('c++ oop', 'cpp', default_options: ['strip=true'])

common_inc = include_directories('common/')

enum_inc = include_directories( 'enum/' )
enum_main = ['enum/user.cpp']
enum_simple = ['enum/user_simple.cpp']
enum_src = ['enum/dev_impl.cpp', 'enum/dev_ctx.cpp', 'enum/dev_algo.cpp', 'enum/dev_factory.cpp']

bench = dependency('benchmark')
thread = dependency('threads')

executable('enum', 
[enum_main, enum_src], 
include_directories: [enum_inc, common_inc],
# dependencies: [bench, thread], 
cpp_args: ['-std=c++17', '-O3', '-fno-rtti'],
install : true)

executable('enum_rtti', 
[enum_main, enum_src], 
include_directories: [enum_inc, common_inc],
# dependencies: [bench, thread], 
cpp_args: ['-std=c++17', '-O3'],
install : true)

executable('enum_simple', 
[enum_simple, enum_src], 
include_directories: [enum_inc, common_inc],
# dependencies: [bench, thread], 
cpp_args: ['-std=c++17', '-O3', '-fno-rtti'],
install : true)

executable('enum_simple_rtti', 
[enum_simple, enum_src], 
include_directories: [enum_inc, common_inc],
# dependencies: [bench, thread], 
cpp_args: ['-std=c++17', '-O3'],
install : true)

oop_inc = include_directories( 'oop/' )
oop_src = ['oop/dev_impl.cpp', 'oop/dev_ctx.cpp', 'oop/dev_factory.cpp']
oop_main = 'oop/user.cpp'

executable('oop', 
[oop_src, oop_main], 
include_directories: oop_inc,
# dependencies: [bench, thread], 
cpp_args: ['-std=c++17', '-O3', '-fno-rtti'],
install : true)

executable('oop_rtti', 
[oop_src, oop_main], 
include_directories: oop_inc,
# dependencies: [bench, thread], 
cpp_args: ['-std=c++17', '-O3'],
install : true)

visitor_inc = include_directories( 'visitor/' )
visitor_main = 'visitor/user.cpp'
visitor_src = ['visitor/dev_impl.cpp', 'visitor/dev_ctx.cpp', 'visitor/dev_algo.cpp', 'visitor/dev_factory.cpp']

executable('visitor', 
[visitor_main, visitor_src], 
include_directories: visitor_inc,
# dependencies: [bench, thread], 
cpp_args: ['-std=c++17', '-O3', '-fno-rtti'],
install : true)

executable('visitor_rtti', 
[visitor_main, visitor_src], 
include_directories: visitor_inc,
# dependencies: [bench, thread], 
cpp_args: ['-std=c++17', '-O3'],
install : true)

variant_t_inc = include_directories( 'variant_t/' )
variant_t_src = ['variant_t/user.cpp', 'variant_t/dev_impl.cpp', 'variant_t/dev_ctx.cpp', 'variant_t/dev_algo.cpp']

executable('variant_t', 
variant_t_src, 
include_directories: variant_t_inc,
# dependencies: [bench, thread], 
cpp_args: ['-std=c++17', '-O3', '-fno-rtti'],
install : true)

executable('variant_t_rtti', 
variant_t_src, 
include_directories: variant_t_inc,
# dependencies: [bench, thread], 
cpp_args: ['-std=c++17', '-O3'],
install : true)

strategy_inc = include_directories( 'strategy/' )
strategy_src = ['strategy/user.cpp', 'strategy/dev_impl.cpp', 'strategy/dev_ctx.cpp', 'strategy/dev_algo.cpp', 'strategy/dev_factory.cpp']

executable('strategy', 
strategy_src, 
include_directories: strategy_inc,
# dependencies: [bench, thread], 
cpp_args: ['-std=c++17', '-O3', '-fno-rtti'],
install : true)

executable('strategy_rtti', 
strategy_src, 
include_directories: strategy_inc,
# dependencies: [bench, thread], 
cpp_args: ['-std=c++17', '-O3'],
install : true)

type_erasure_up_inc = include_directories( 'type_erasure_up/' )
type_erasure_up_src = ['type_erasure_up/user.cpp', 'type_erasure_up/dev_impl.cpp', 'type_erasure_up/dev_ctx.cpp', 'type_erasure_up/dev_algo.cpp', 'type_erasure_up/dev_factory.cpp']

executable('type_erasure_up', 
type_erasure_up_src, 
include_directories: type_erasure_up_inc,
# dependencies: [bench, thread], 
cpp_args: ['-std=c++17', '-O3', '-fno-rtti'],
install : true)

executable('type_erasure_up_rtti', 
type_erasure_up_src, 
include_directories: type_erasure_up_inc,
# dependencies: [bench, thread], 
cpp_args: ['-std=c++17', '-O3'],
install : true)

benchmark_test = ['benchmark.cpp']

benchmark_test_O3_exe = executable('benchmark_test_O3', 
[benchmark_test, enum_src, oop_src, visitor_src], 
include_directories: [enum_inc, common_inc, oop_inc, visitor_inc],
dependencies: [bench, thread], 
cpp_args: ['-std=c++17', '-O3'])

test('enum benchmark O3', benchmark_test_O3_exe, is_parallel : false)

benchmark_test_O0_exe = executable('benchmark_test_O0', 
[benchmark_test, enum_src, oop_src, visitor_src], 
include_directories: [enum_inc, common_inc, oop_inc, visitor_inc],
dependencies: [bench, thread], 
cpp_args: ['-std=c++17', '-O0', '-g'])

test('enum benchmark O0', benchmark_test_O0_exe, is_parallel : false)