#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char ** argv){
int c = fgetc(stdin);
FILE * output = stdout;
FILE* input = stdin;
int ver = 0;
int number;
for(int i = 1; i < argc; i++){
if(strcmp(argv[i],"-o") == 0)
   output = fopen(argv[++i],"w");
else if(argv[i][0] == '+')
    ver =1;
    else if(argv[i][0] == '-'){
        ver = 2;
    }
    else{
    printf("invalid parameter - %s\n",argv[i]);
    return 1;
    }
}
if(ver != 0)
    number = atoi(argv[1] + 1);
    while (c != EOF){
        if(c <= 'z' && c>= 'A'){
           if(c <= 'Z')
              c = c | (1 << 5);
           if(ver == 1){
                    c = c + number;
            }
            else{
                    c = c - number;
            }
        }
        fputc(c, output);
        c = fgetc(input);
    }
}
