#include <stdio.h>

void caesarCipher(char text[], int shift){
    for(int i=0; text[i] != '\0'; ++i){
        char ch = text[i];

        if(ch >= 'a' && ch <= 'z'){
            ch = (ch - 'a' + shift) % 26 + 'a';

        } else if (ch >= 'A' && ch <= 'Z') {
            ch = (ch - 'A' + shift) % 26 + 'A';
        }
        text[i]= ch;
    }
}

int main(){
    char text[1000];
    int shift;

    printf("Wprowadź text: ");
    gets(text);
    
    printf("Wprowadź przesunięcie: ");
    scanf("%d",&shift);

    caesarCipher(text, shift);
    printf("Zaszyfrowany text: %s\n", text);

    caesarCipher(text, -shift);
    printf("Odszyfrowany text: %s\n", text);    
    
    return 0;
}