#include <math.h>
#include <stdio.h>


double calculate_y(double x) {
    double y = 0.0;
    y += 8.2606e+07 * pow(x, 0);
    y += -5.1232e+08 * pow(x, 1);
    y += 1.2060e+09 * pow(x, 2);
    y += -1.1049e+09 * pow(x, 3);
    y += -2.7128e+08 * pow(x, 4);
    y += 1.0611e+09 * pow(x, 5);
    y += 7.8537e+07 * pow(x, 6);
    y += -1.0128e+09 * pow(x, 7);
    y += -3.4322e+07 * pow(x, 8);
    y += 1.0105e+09 * pow(x, 9);
    y += -9.6543e+07 * pow(x, 10);
    y += -1.0198e+09 * pow(x, 11);
    y += 5.2266e+08 * pow(x, 12);
    y += 7.5147e+08 * pow(x, 13);
    y += -1.2916e+09 * pow(x, 14);
    y += 9.6513e+08 * pow(x, 15);
    y += -4.4967e+08 * pow(x, 16);
    y += 1.4206e+08 * pow(x, 17);
    y += -3.1107e+07 * pow(x, 18);
    y += 4.6895e+06 * pow(x, 19);
    y += -4.7365e+05 * pow(x, 20);
    y += 3.0701e+04 * pow(x, 21);
    y += -1.2301e+03 * pow(x, 22);
    y += 3.2336e+01 * pow(x, 23);
    y += 3.0715e+00 * pow(x, 24);
    return y;
}

int main() {
    double x = 3.8;
    printf("%f", calculate_y(x));
    return 0;
}