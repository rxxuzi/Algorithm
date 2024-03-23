#include <stdio.h>
#include <math.h>

double calculatePI(int itr) {
    double a = 1.0, b = 1.0 / sqrt(2), t = 1.0 / 4.0, p = 1.0;
    double a_n, b_n, t_n;
    for (int i = 0; i < itr; i++) {
        a_n = (a + b) / 2.0;
        b_n = sqrt(a * b);
        t_n = t - p * pow(a - a_n, 2);
        a = a_n;
        b = b_n;
        t = t_n;
        p *= 2;
    }
    return pow(a + b, 2) / (4 * t);
}

int main(void) {
    int itr = 15;
    double pi = calculatePI(itr);
    printf("Iterations = %d\n", itr);
    printf("PI = %0.12Lf\n", pi);
    return 0;
}