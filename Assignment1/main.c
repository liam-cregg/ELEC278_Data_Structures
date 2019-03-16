#include <stdio.h>
#include <stdlib.h>
#include "poly.h"

int main()
{
    Poly p1;
    initPoly(&p1);
    display(&p1);
    createPoly(&p1, 3);
    setCoefficient(0, 2, &p1);
    setCoefficient(1, 4, &p1);
    setCoefficient(2, 3, &p1);
    setCoefficient(3, 1, &p1);
    display(&p1);
}