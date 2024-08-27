#include <stdio.h>
#include <math.h>

#include "utils.cpp"
#include "solver.cpp"
#include "tests.cpp"

//#define TESTS

int main()
{
    #ifdef TESTS
    run_tests();
    #else
    printf("enter a,b,c \n");

    struct SquareEqData variables = {0, 0, 0, 0, 0, ZERO_SOLUTIONS};

    input_coeffs(&(variables.a), &(variables.b), &(variables.c));

    solve_square(&variables);

    output_solutions(&variables);
    #endif
}
