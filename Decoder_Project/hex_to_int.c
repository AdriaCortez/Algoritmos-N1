#include "header.h"

// Convertendo hexadecimal para inteiro
int hex_to_int(char hex_char) {

    char HEX_VALUES[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'a', 'b', 'c', 'd', 'e', 'f'};

    int i;

    for (i = 0; i < 22; i++) {
        if (hex_char == HEX_VALUES[i]) {
            if (i > 15) {
                return i - 6; // Ajuste para letras minúsculas
            }
            return i;
        }
    }
    return -1;
}