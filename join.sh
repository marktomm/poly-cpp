#!/bin/bash

test -z $1 && {
    echo "first arg must be subdir"
    exit 1
}

test -d $1 || {
    echo "subdir $1 missing"
    exit 1
}

APP_ROOT=.
SUB=$1
OUTPUT=${SUB}/amalgamation.cpp
REGEX='"dev.*\.h\|common\/.*\.h\|include.*types.h"'

test -f ${APP_ROOT}/common/types.h && cat $_ > ${OUTPUT}
test -f ${SUB}/include/dev_base.h && grep -v ${REGEX} $_ >> ${OUTPUT}
test -f ${SUB}/src/dev_base.cpp && grep -v ${REGEX} $_ >> ${OUTPUT}
test -f ${SUB}/include/dev_impl.h && grep -v ${REGEX} $_ >> ${OUTPUT}
test -f ${SUB}/src/dev_impl.cpp && grep -v ${REGEX} $_ >> ${OUTPUT}
test -f ${SUB}/include/dev_algo.h && grep -v ${REGEX} $_ >> ${OUTPUT}
test -f ${SUB}/src/dev_algo.cpp && grep -v ${REGEX} $_ >> ${OUTPUT}
test -f ${SUB}/include/dev_ctx.h && grep -v ${REGEX} $_ >> ${OUTPUT}
test -f ${SUB}/src/dev_ctx.cpp && grep -v ${REGEX} $_ >> ${OUTPUT}
test -f ${SUB}/include/dev_factory.h && grep -v ${REGEX} $_ >> ${OUTPUT}
test -f ${SUB}/src/dev_factory.cpp && grep -v ${REGEX} $_ >> ${OUTPUT}
test -f ${SUB}/src/user.cpp && grep -v ${REGEX} $_ >> ${OUTPUT}
