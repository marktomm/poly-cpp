#!/bin/bash

set -e

trimFwdSlashes() {
  a1="${1#/}"       # Remove leading /
  a1="${a1%/}"     # Remove preceding /
  echo "${a1}"
}

test -z $1 && {
    echo "first arg must be <poly> subdir"
    exit 1
}

test -d $1 || {
    echo "subdir $1 missing"
    exit 1
}

APP_ROOT=.
SUB=$(trimFwdSlashes ${1})
outputMain=${SUB}/src/main.cpp
outputLib=${SUB}/src/lib.cpp
outputBench=${SUB}/bench.h
outputApi=${SUB}/include/lib.h
REGEX='"dev.*\.h\|common/.*\.h\|include.*types.h"'

if test -f ${outputMain} || test -f ${outputLib} || test -f ${outputLib} || test -f ${outputLib}; then
    echo "to_lib.sh: files exist. noop"; exit 0;
fi;
# rm -f ${outputMain} ${outputLib} ${outputBench} ${outputApi} 
(
    cd ${SUB}
    mv meson.build meson.build.v1
)
./new_poly.sh ${SUB} "lib_bench"
(
    cd ${SUB}
    mv meson.build meson.build.v2
    ln -s meson.build.v2 meson.build
)

fn() {
    if test -f ${1}; then
        echo "// ${1}" >> ${2}
        test -f "${1}" && grep -v ${REGEX} $_ >> ${2}
        echo "// ${1} end" >> ${2}
    fi
}

fn ${APP_ROOT}/common/types.h ${outputApi}
fn ${SUB}/include/dev_base.h ${outputApi}
fn ${SUB}/src/dev_base.cpp ${outputLib}
fn ${SUB}/include/dev_impl.h ${outputApi}
fn ${SUB}/src/dev_impl.cpp ${outputLib}
fn ${SUB}/include/dev_algo.h ${outputApi}
fn ${SUB}/src/dev_algo.cpp ${outputLib}
fn ${SUB}/include/dev_ctx.h ${outputApi}
fn ${SUB}/src/dev_ctx.cpp ${outputLib}
fn ${SUB}/include/dev_factory.h ${outputApi}
fn ${SUB}/src/dev_factory.cpp ${outputLib}
echo '#include "lib.h"' >> ${SUB}/src/user.cpp
echo 'using namespace std;' >> ${SUB}/src/user.cpp
echo 'using namespace '"${SUB}"';' >> ${SUB}/src/user.cpp
fn ${SUB}/src/user.cpp ${outputMain}

