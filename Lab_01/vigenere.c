#include <stdio.h>
#include <string.h>

void vigenereCipher(char text[], char key[]) {
    int textLen = strlen(text);
    int keyLen = strlen(key);
    char newKey[textLen];

    for(int i = 0, j = 0; i < textLen; ++i, ++j){
        if (j == keyLen) j = 0;
        newKey[i] = key[j];
    }
    newKey[textLen] = '\0';

    for(int i = 0; i < textLen; ++i) {
        if(text[i] >= 'A' && text[i] <= 'Z')
            text[i] = (text[i] + newKey[i]) % 26 + 'A';
        else if(text[i] >= 'a' && text[i] <= 'z')
            text[i] = (text[i] + newKey[i]) % 26 + 'a';
    }
}

void vigenereDecipher(char text[], char key[]){
    int textLen = strlen(text);
    int keyLen = strlen(key);
    char newKey[textLen];
    for(int i = 0, j = 0; i < textLen; ++i, ++j){
        if (j == keyLen) j = 0;
        newKey[i] = key[j];
    }
    newKey[textLen] = '\0';

    for(int i = 0; i < textLen; ++i) {
        if(text[i] >= 'A' && text[i] <= 'Z')
            text[i] = (text[i] - newKey[i] + 26) % 26 + 'A';
        else if(text[i] >= 'a' && text[i] <= 'z')
            text[i] = (text[i] - newKey[i] + 26) % 26 + 'a';
    }
}

int main(){
    char text[1000], key[100];
    printf("Wprowadź tekst do zaszyfrowania: ");
    gets(text);

    printf("Wprowadź klucz: ");
    gets(key);    

    vigenereCipher(text, key);
    printf("Zaszyfrowany tekst: %s\n", text);

    vigenereDecipher(text, key);
    printf("Odszyfrowany tekst: %s\n", text);    
    return 0; 
}