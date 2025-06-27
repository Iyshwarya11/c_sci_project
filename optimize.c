#include <stdio.h>
#include <math.h>
#include "optimize.h"

// Function: f(x) = x^2 - 2 (Root ≈ √2 = 1.4142)
double f(double x) {
    return x * x - 2;
}

// Derivative: f'(x) = 2x
double f_prime(double x) {
    return 2 * x;
}

// Newton-Raphson Method
double newton_raphson(double x0, double tol, int max_iter) {
    double x = x0;
    for (int i = 0; i < max_iter; i++) {
        double fx = f(x);
        double fpx = f_prime(x);
        if (fabs(fpx) < 1e-8) {
            printf("Derivative near zero. Stopping iteration.\n");
            break;
        }
        double x_new = x - fx / fpx;
        if (fabs(x_new - x) < tol) {
            return x_new;
        }
        x = x_new;
    }
    return x;
}

void optimize_menu() {
    double guess, tolerance;
    int max_iter;

    printf("\n--- Root Finding using Newton-Raphson ---\n");
    printf("Solving: f(x) = x^2 - 2\n");
    printf("Enter initial guess: ");
    scanf("%lf", &guess);
    printf("Enter tolerance (e.g., 0.0001): ");
    scanf("%lf", &tolerance);
    printf("Enter max iterations: ");
    scanf("%d", &max_iter);

    double root = newton_raphson(guess, tolerance, max_iter);
    printf("Approximate root: %.5lf\n", root);
}
