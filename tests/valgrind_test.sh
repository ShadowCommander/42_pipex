#!/bin/bash

SCRIPT_DIR="$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd
)"
valgrind --leak-check=full \
--show-leak-kinds=all \
--track-origins=yes \
--verbose \
--log-file=valgrind-out.txt \
$1 $2 $3 $4 $5
less valgrind-out.txt

