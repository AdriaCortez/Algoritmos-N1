#include "header.h"

// Convertendo par hexadecimais para ASCII
int hex_to_ascii(char high, char low) {

    int high_value = hex_to_int(high);
    int low_value = hex_to_int(low);

    if (high_value == -1 || low_value == -1) {
        return -1;
    }

    return high_value * 16 + low_value;
}