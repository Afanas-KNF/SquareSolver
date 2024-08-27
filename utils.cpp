#include <stdio.h>
#include <math.h>

bool is_zero(double);
bool clear_buffer();
bool is_equal(double, double);

const double EPSILON = 1e-8;

//_______________________________________________________________________________________________________________

bool is_zero(double num)
{
    if (fabs(num) < EPSILON)
    {
        return true;
    }
    return false;
}

//_______________________________________________________________________________________________________________

bool is_equal(double first, double second)
{
    if (fabs(first - second) < EPSILON)
    {
        return true;
    }
    return false;
}

//_______________________________________________________________________________________________________________

bool clear_buffer()
{
    if (getchar() == '\n')
        return false;

    while (getchar() != '\n') {}

    return true;
}

//_______________________________________________________________________________________________________________
