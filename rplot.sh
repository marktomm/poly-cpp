#!/bin/bash

set -e 

trimFwdSlashes() {
  a1="${1#/}"       # Remove leading /
  a1="${a1%/}"     # Remove preceding /
  echo "${a1}"
}

ARG1=$1
ARG1=$(trimFwdSlashes ${ARG1})

./builddir/${ARG1}/${ARG1}_benchmark_google_opt --benchmark_filter='BM_[01]' --benchmark_format=csv  | ./plot.sh ${ARG1} && mv ${ARG1}/bench.png ${ARG1}/${ARG1}_opt_01.png
./builddir/${ARG1}/${ARG1}_benchmark_google_opt --benchmark_filter='BM_[AB]' --benchmark_format=csv  | ./plot.sh ${ARG1} && mv ${ARG1}/bench.png ${ARG1}/${ARG1}_opt_ab.png
./builddir/${ARG1}/${ARG1}_benchmark_google_no_opt --benchmark_filter='BM_[01]' --benchmark_format=csv  | ./plot.sh ${ARG1} && mv ${ARG1}/bench.png ${ARG1}/${ARG1}_no_opt_01.png
./builddir/${ARG1}/${ARG1}_benchmark_google_no_opt --benchmark_filter='BM_[AB]' --benchmark_format=csv  | ./plot.sh ${ARG1} && mv ${ARG1}/bench.png ${ARG1}/${ARG1}_no_opt_ab.png
