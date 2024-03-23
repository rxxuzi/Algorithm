#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void getXY(double *x, double *y) {
    *x = (double)rand() / RAND_MAX;
    *y = (double)rand() / RAND_MAX;
}

int main(void) {
    srand(time(NULL));
    const unsigned long count = 1000000l;
    unsigned long n = 0;

    double x, y;
    for (size_t i = 0; i < count; i++){
        getXY(&x, &y);
        if (x * x + y * y <= 1) {
            n++;
        }
    }
    
    double pi = 4.0 * n / count;
    printf("pi = %lf\n", pi);
    return 0;
}