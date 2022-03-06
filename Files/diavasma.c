#include <stdio.h>
#include <stdlib.h>

int main(){

    FILE * fp = fopen("test.txt", "r");
    char c;

    if(fp==NULL){
        printf("Error in opening file");
        exit(0);
    }
        

    while(c=(fgetc(fp)!=EOF))
        printf("%c", c);
    
    fclose(fp);
}
