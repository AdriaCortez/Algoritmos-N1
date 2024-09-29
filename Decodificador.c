#include <stdio.h>
#include <string.h>
#include <math.h>

char HEX_VALUES[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'a', 'b', 'c', 'd', 'e', 'f'};
float A0 = 186.752;
float A1 = -148.235;
float A2 = 34.5049;
float A3 = -3.5091;
float A4 = 0.183166;
float A5 = -0.00513554;
float A6 = 0.0000735464;
float A7 = -4.22038 * pow(10, -7);

char msg_encoded[101];
char msg_decoded[51];

// Convertendo hexadecimal para inteiro
int hex_to_int(char hex_char) {
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

// Convertendo par hexadecimais em ASCII
int hex_to_ascii(char high, char low) {
    int high_value = hex_to_int(high);
    int low_value = hex_to_int(low);

    if (high_value == -1 || low_value == -1) {
        return -1;
    }

    return high_value * 16 + low_value;
}

// Validando caracteres
int validation(int x, int b) {
    float r = A0 + (A1 + b) * x + A2 * pow(x, 2) + A3 * pow(x, 3) +
                   A4 * pow(x, 4) + A5 * pow(x, 5) + A6 * pow(x, 6) + A7 * pow(x, 7);

    if (round(r) == 0) {
        return -1; // Remover o caractere
    }
    return 1; // Manter o caractere
}

// Decodificando a mensagem
void decode_message(char* msg_encoded, int b) {
    int length = strlen(msg_encoded);
    int last_char_index = 0;
    int active_char_index = 1;
    int i, ascii_value;

    for (i = 0; i < length && last_char_index < 50; i += 2) {
        ascii_value = hex_to_ascii(msg_encoded[i], msg_encoded[i + 1]);

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

int main() {
    int b;

    printf("Digite a chave de decodificação (-100 a 100): ");
    scanf("%d", &b);

    printf("Insira a mensagem codificada: ");
    scanf("%s", msg_encoded);

    decode_message(msg_encoded, b);

    printf("Mensagem decodificada: %s\n", msg_decoded);

    return 0;
}
