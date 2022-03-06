/*Rewind returns the cursor back to 
the beginning of the file*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fp;
    char c;
    int i;

    fp=fopen("test.txt", "r");

    if(fp==NULL){
        printf("Error while opening file");
        exit(0);
    }

    for(i=0;i<5;i++){
        printf("%c",fgetc(fp));
    }

    rewind(fp);

    while((c=fgetc(fp))!=EOF){
        printf("%c",c);
    }
    fclose(fp);
}