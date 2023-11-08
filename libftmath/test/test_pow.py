import subprocess

# ANSI color codes
GREEN = "\033[92m"
RED = "\033[91m"
RESET = "\033[0m"

# Define the list of test cases as tuples (n, p)
test_cases = [(2, 3), (4, 2), (10, 5)]  # Add more test cases as needed

# Define the relative path to the libftmath library
relative_lib_path = "../.lib/libftmath.a"

# Iterate through the test cases
for test_case in test_cases:
    n, p = test_case

    # Create the test program source code
    test_source = f"""
#include <stdio.h>
#include <math.h>
#include "../src/libftmath.h"

int main() {{
    long long unsigned int n = {n};
    size_t p = {p};
    
    long long unsigned int result = ft_pow(n, p);
    long long unsigned int result_std = pow(n, p);

    if (result == result_std) {{
        printf("{GREEN}Using libftmath's ft_pow function: %llu^{p} = %llu{RESET}\\n", n, result);
    }} else {{
        printf("{RED}Using libftmath's ft_pow function: %llu^{p} = %llu (Mismatch){RESET}\\n", n, result);
    }}

    if (result_std == pow(n, p)) {{
        printf("{GREEN}Using standard library's pow function: %llu^{p} = %llu{RESET}\\n", n, result_std);
    }} else {{
        printf("{RED}Using standard library's pow function: %llu^{p} = %llu (Mismatch){RESET}\\n", n, result_std);
    }}

    return 0;
}}
"""

    # Save the test program source code to a temporary file
    with open("test_pow.c", "w") as file:
        file.write(test_source)

    # Compile the test program, including the relative path to the libftmath library
    subprocess.run(["gcc", "test_pow.c", "-o", "test_pow", relative_lib_path, "-lm"])

    # Run the test program
    subprocess.run(["./test_pow"])

    # Clean up the temporary test program
    subprocess.run(["rm", "test_pow.c", "test_pow"])

