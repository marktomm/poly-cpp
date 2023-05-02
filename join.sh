#!/bin/bash

set -e

trimFwdSlashes() {
  a1="${1#/}"       # Remove leading /
  a1="${a1%/}"     # Remove preceding /
  echo "${a1}"
}

test -z $1 && {
    echo "first arg must be subdir"
    exit 1
}

test -d $1 || {
    echo "subdir $1 missing"
    exit 1
}

APP_ROOT=.
SUB=$(trimFwdSlashes ${1})
OUTPUT=${SUB}/amalgamation.cpp
REGEX='"dev.*\.h\|common/.*\.h\|include.*types.h"'

rm -f ${outputMain} ${outputLib} ${outputBench} ${outputApi} ${OUTPUT}

fn() {
    echo "// ${1}" >> ${2}
    test -f "${1}" && grep -v ${REGEX} $_ >> ${2}
    echo "// ${1} end" >> ${2}
}

fn ${APP_ROOT}/common/types.h ${OUTPUT}
fn ${SUB}/include/dev_base.h ${OUTPUT}
fn ${SUB}/src/dev_base.cpp ${OUTPUT}
fn ${SUB}/include/dev_impl.h ${OUTPUT}
fn ${SUB}/src/dev_impl.cpp ${OUTPUT}
fn ${SUB}/include/dev_algo.h ${OUTPUT}
fn ${SUB}/src/dev_algo.cpp ${OUTPUT}
fn ${SUB}/include/dev_ctx.h ${OUTPUT}
fn ${SUB}/src/dev_ctx.cpp ${OUTPUT}
fn ${SUB}/include/dev_factory.h ${OUTPUT}
fn ${SUB}/src/dev_factory.cpp ${OUTPUT}
fn ${SUB}/src/user.cpp ${OUTPUT}
