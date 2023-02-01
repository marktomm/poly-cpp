#!/bin/bash

function is-app-installed(){
    hash $1 2>&-
    return $?
}

is-app-installed muon || {
    echo "You don't have muon installed. Visit https://muon.build/"
    exit 1
}

muon fmt -i meson.build 
muon fmt -i enum/meson.build 
muon fmt -i oop/meson.build 
muon fmt -i visitor/meson.build 
muon fmt -i type_erasure_up/meson.build 
muon fmt -i variant_t/meson.build 
muon fmt -i strategy/meson.build 
muon fmt -i benchmarks/meson.build 
