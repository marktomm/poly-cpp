#!/bin/bash

set -e

# other_script_output=$(./poly_list.sh)

while IFS= read -r line; do
    ./rplot.sh ${line}
done <<< "$(./poly_list.sh)"
./rplot.sh ${line} benchmarks
