#!/bin/bash

set -e

./regen_all_poly.sh 
rm -r builddir/
meson setup builddir
./_build.sh 