#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void hex_to_string(long long hex_value, char text[]) {
    char hex[17];
    sprintf(hex, "%llx", hex_value);

    int len = strlen(hex);

    for (int i = 0; i < len; i += 2) {
        sscanf(&hex[i], "%2hhx", &text[i / 2]);
    }
    text[len / 2] = '\0';
}

long long str_to_hex(char texto[], int size) {
    char txt_hex[size * 2 + 1];
    int len = strlen(texto);

    int i;
    for(i = size-1; i > 0; i--) {
        if (texto[i] == '\n') {
            texto[i] = '\0';
        }
    }

    for (i = 0; i < len; i++) {
        sprintf(txt_hex + i * 2, "%02X", texto[i]);
    }

    txt_hex[len * 2] = '\0';

    return strtoull(txt_hex, NULL, 16);
}

int main(){
    long long hex_value = 0x436F6D7075746572;
    char text[18];

    hex_to_string(hex_value, text);

    printf("%s\n", text);

    int tamanho = strlen(text);

    long long hexfinal = str_to_hex(text, tamanho);

    printf("%llX\n", hexfinal);
}