#include <math.h>
#include "header.h"

// Validando caracteres
int validation(int x, int b) {

    float A0 = 186.752;
    float A1 = -148.235;
    float A2 = 34.5049;
    float A3 = -3.5091;
    float A4 = 0.183166;
    float A5 = -0.00513554;
    float A6 = 0.0000735464;
    float A7 = -4.22038 * pow(10, -7);

    float r = A0 + (A1 + b) * x + A2 * pow(x, 2) + A3 * pow(x, 3) + A4 * pow(x, 4) + A5 * pow(x, 5) + A6 * pow(x, 6) + A7 * pow(x, 7);

    if (round(r) == 0) {
        return -1; // Remover o caractere
    }
    return 1; // Manter o caractere
}