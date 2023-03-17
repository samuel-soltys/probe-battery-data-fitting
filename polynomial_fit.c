#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct DataFrame {
    double *V_STO;
    double *SoC;
    int nrows;
};

struct DataFrame read_excel(char *filename) {
    // Open the Excel file and read the data into a DataFrame struct
    struct DataFrame df;
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Unable to open file %s.\n", filename);
        exit(1);
    }
    int nrows = 0;
    double *V_STO = malloc(1000 * sizeof(double));
    double *SoC = malloc(1000 * sizeof(double));
    while (!feof(fp)) {
        if (fscanf(fp, "%lf,%lf", &V_STO[nrows], &SoC[nrows]) == 2) {
            nrows++;
        }
    }
    fclose(fp);
    df.V_STO = V_STO;
    df.SoC = SoC;
    df.nrows = nrows;
    return df;
}

double polyfit(double *x, double *y, int n, double num) {
    // Compute the polynomial fit of degree 24 for the data
    double p[25];
    double sumx = 0.0, sumy = 0.0, sumxy = 0.0, sumx2 = 0.0;
    for (int i = 0; i < n; i++) {
        sumx += x[i];
        sumy += y[i];
        sumxy += x[i] * y[i];
        sumx2 += x[i] * x[i];
    }
    double denom = n * sumx2 - sumx * sumx;
    if (denom == 0) {
        printf("Error: Denominator is zero.\n");
        exit(1);
    }
    double a = (n * sumxy - sumx * sumy) / denom;
    double b = (sumy - a * sumx) / n;
    for (int i = 0; i <= 24; i++) {
        p[i] = 0.0;
        for (int j = 0; j < n; j++) {
            p[i] += pow(x[j], i) * y[j];
        }
        p[i] /= denom;
    }
    double fit = 0.0;
    for (int i = 0; i <= 24; i++) {
        fit += p[i] * pow(num, i);
    }
    return fit;
}

int main() {
    struct DataFrame excel = read_excel("data.csv");
    double num = 3.7;
    double fit = polyfit(excel.V_STO, excel.SoC, excel.nrows, num);
    printf("FIT: %lf\n", fit);
    free(excel.V_STO);
    free(excel.SoC);
    return 0;
}