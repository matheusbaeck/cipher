#!/bin/bash

# Get the directory where the script is located
script_dir=$(dirname "$0")

# ANSI color codes
BLUE="\033[94m"
RESET="\033[0m"

# Recompile the libftmath library
make -C "$script_dir/../"

# Check if the compilation was successful
if [ $? -ne 0 ]; then
    echo "Compilation of libftmath failed."
    exit 1
fi

# Get the test name argument
test_name_arg="$1"

if [ -z "$test_name_arg" ]; then
    # If no test name argument is provided, run all test scripts
    for test_script in "$script_dir"/test_*.py; do
        if [ -f "$test_script" ]; then
            test_name=$(basename "$test_script" | sed 's/^test_//' | sed 's/.py$//')
            echo -e "${BLUE}Running tests for libftmath library${RESET}"
            echo -e "${BLUE}Test script: $test_name.py${RESET}"
            python "$test_script"
        fi
    done
else
    # Extract the test name from the argument
    test_name=$(echo "$test_name_arg" | sed 's/^test_//' | sed 's/.py$//')

    # Construct the test script filename
    test_script="$script_dir/test_$test_name.py"

    # Check if the specified test script exists
    if [ -f "$test_script" ]; then
        echo -e "${BLUE}Running tests for libftmath library${RESET}"
        echo -e "${BLUE}Test script: $test_script${RESET}"
        python "$test_script"
    else
        echo "Test script '$test_script' not found."
        exit 1
    fi
fi

