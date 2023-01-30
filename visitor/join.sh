#!/bin/bash

APP_ROOT=../
SUB=./
OUTPUT=${SUB}/amalgamation.cpp

test -f ${APP_ROOT}/common/types.h && cat $_ > ${OUTPUT}
test -f dev_base.h && grep -v '"dev.*\.h\|common\/.*\.h' $_ >> ${OUTPUT}
test -f dev_base.cpp && grep -v '"dev.*\.h\|common\/.*\.h' $_ >> ${OUTPUT}
test -f dev_impl.h && grep -v '"dev.*\.h\|common\/.*\.h' $_ >> ${OUTPUT}
test -f dev_impl.cpp && grep -v '"dev.*\.h\|common\/.*\.h' $_ >> ${OUTPUT}
test -f dev_algo.h && grep -v '"dev.*\.h\|common\/.*\.h' $_ >> ${OUTPUT}
test -f dev_algo.cpp && grep -v '"dev.*\.h\|common\/.*\.h' $_ >> ${OUTPUT}
test -f dev_ctx.h && grep -v '"dev.*\.h\|common\/.*\.h' $_ >> ${OUTPUT}
test -f dev_ctx.cpp && grep -v '"dev.*\.h\|common\/.*\.h' $_ >> ${OUTPUT}
test -f dev_factory.h && grep -v '"dev.*\.h\|common\/.*\.h' $_ >> ${OUTPUT}
test -f dev_factory.cpp && grep -v '"dev.*\.h\|common\/.*\.h' $_ >> ${OUTPUT}
test -f user.cpp && grep -v '"dev.*\.h\|common\/.*\.h' $_ >> ${OUTPUT}
