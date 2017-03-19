#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char ** argv){
int c = fgetc(stdin);
    while (c != EOF){
        if(c <= 'Z' && c >= 'A')
            c = c | (1 << 5);
        fputc(c, stdout);
        c = fgetc(stdin);
        
    }
}