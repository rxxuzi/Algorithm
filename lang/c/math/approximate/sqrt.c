#include <stdio.h>

// 連分数による平方根の近似
double sqrtApprox(int n, int itr) {
    double result = n;
    for (int i = 0; i < itr; i++) {
        result = 0.5 * (result + (n / result));
    }
    return result;
}

int main() {
    int number;
    printf("Enter a number: ");
    scanf("%d" , &number);
    int iterations = 100; // 反復回数
    double approx = sqrtApprox(number, iterations);
    printf("Approximation of sqrt(%d) is: %f\n", number, approx);
    return 0;
}