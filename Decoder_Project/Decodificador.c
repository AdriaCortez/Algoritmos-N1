#include <stdio.h>
#include <string.h>
#include <math.h>
#include "header.h"

char msg_encoded[101];
char msg_decoded[51];
int b;

int main() {

    printf("Digite a chave de decodificação (-100 a 100): ");
    scanf("%d", &b);

    printf("Insira a mensagem codificada: ");
    scanf("%s", msg_encoded);

    decode_message(msg_encoded, b);

    printf("%s", msg_decoded);

    return 0;
}
