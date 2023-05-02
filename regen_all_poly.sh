#!/bin/bash

set -e

# other_script_output=$(./poly_list.sh)

while IFS= read -r line; do
    ./new_poly.sh ${line} regen_meson
done <<< "$(./poly_list.sh)"