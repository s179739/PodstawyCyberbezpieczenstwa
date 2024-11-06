#include <stdio.h>

void xorEncryptDecrypt(char text[], char key){
    for(int i = 0; text[i] != '\0'; ++i){
        text[i] = text[i] ^ key;  // XOR
    }
}

void printHex(const char text[]) {
    for (int i = 0; text[i] != '\0'; ++i) {
        printf("%02x ", (unsigned char)text[i]);
    }
    printf("\n");
}

int main(){
    char text[1000];
    char key;
    printf("Wprowadź tekst do zaszyfrowania: ");
    gets(text);

    printf("Wprowadź klucz (jeden znak): ");
    scanf("%c", &key);    

    printf("Wprowadzony text w postaci szesnastkowej:");
    printHex(text);

    xorEncryptDecrypt(text, key);
    printf("Zaszyfrowany tekst: %s\n", text);
    printf("Zaszyfrowany tekst w postaci szesnastkowej:");
    printHex(text);    

    xorEncryptDecrypt(text, key);
    printf("Odszyfrowany tekst: %s\n", text);   
    printf("Odszyfrowany tekst w postaci szesnastkowej:");
    printHex(text);
    
    return 0;
}