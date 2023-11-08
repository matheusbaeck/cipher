import subprocess

# ANSI color codes
GREEN = "\033[92m"
RED = "\033[91m"
RESET = "\033[0m"

# Define the list of test cases as tuples (n, m)
test_cases = [(10, 3), (7, 5), (15, 8)]  # Add more test cases as needed

# Define the relative path to the libftmath library
relative_lib_path = "../.lib/libftmath.a"

# Iterate through the test cases
for test_case in test_cases:
    n, m = test_case

    # Create the test program source code
    test_source = f"""
#include <stdio.h>
#include <math.h>
#include "../src/ftmath.h"

int main() {{
    unsigned long long n = {n};
    unsigned long long m = {m};
    
    unsigned long long result = ft_mod(n, m);
    unsigned long long result_std = n % m;

    if (result == result_std) {{
        printf("{GREEN}Using libftmath's ft_mod function: %llu %% %llu = %llu{RESET}\\n", n, m, result);
    }} else {{
        printf("{RED}Using libftmath's ft_mod function: %llu %% %llu = %llu (Mismatch){RESET}\\n", n, m, result);
    }}

    if (result_std == n % m) {{
        printf("{GREEN}Using standard library's %% operator: %llu %% %llu = %llu{RESET}\\n", n, m, result_std);
    }} else {{
        printf("{RED}Using standard library's %% operator: %llu %% %llu = %llu (Mismatch){RESET}\\n", n, m, result_std);
    }}

    return 0;
}}
"""

    # Save the test program source code to a temporary file
    with open("test_mod.c", "w") as file:
        file.write(test_source)

    # Compile the test program, including the relative path to the libftmath library
    subprocess.run(["gcc", "test_mod.c", "-o", "test_mod", relative_lib_path, "-lm"])

    # Run the test program
    subprocess.run(["./test_mod"])

    # Clean up the temporary test program
    subprocess.run(["rm", "test_mod.c", "test_mod"])

