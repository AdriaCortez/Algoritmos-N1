#include <string.h>
#include "header.h"

// Decodificando a mensagem
void decode_message(char* encoded, int b) {

    int length = strlen(encoded);
    int last_char_index = 0;
    int active_char_index = 1;
    int i, ascii_value;

    for (i = 0; i < length && last_char_index < 50; i += 2) {
        ascii_value = hex_to_ascii(encoded[i], encoded[i + 1]);

        if (ascii_value == -1) { // Ignora caracteres inválidos
            continue; 
        }

        // Se encontrar '00' encerra a decodificação
        if (ascii_value == 0) {
            break;
        }

        if (validation(active_char_index, b) == 1) {
            msg_decoded[last_char_index++] = (char)ascii_value;
            active_char_index++;
        }
        else {
            active_char_index++;
        }
    }

    msg_decoded[last_char_index] = '\0'; // Finalizando a string
}