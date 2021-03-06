#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char ** argv){
    FILE * output = stdout;
    FILE* input = stdin;
    int ver = 0;
    int number;
    char s[31];
    for(int i = 1; i < argc; i++){
            if(strcmp(argv[i], "-i") == 0){
                input = fopen(argv[++i],"r");
            }
            else if(strcmp(argv[i],"-o") == 0){
                printf("Enter output file name:");
                fgets(s,30,stdin);
                char* pos = strchr(s,'\n');
                if(pos != NULL)
                    *pos = '\0';
                output = fopen(s,"w");
            }
            else if(argv[i][0] == '+'){
                ver =1;
            }
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
    int c = fgetc(input);
    while (c != EOF){
        if((c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A')){
            if(c <= 'Z' && c >='A')
                c = c | (1 << 5);
            if(ver == 1){
                        c = c + number;
            }
            else if(ver == 2){
                    c = c - number;
            }
        }
        fputc(c, output);
        c = fgetc(input);
    }
}
