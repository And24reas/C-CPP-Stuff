#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fp;
    fp=fopen("exercise2.txt","w");
    fprintf(fp,"random text");
    fclose(fp);
/*mode "r" does not allow writing into the file
but it does not cause the programm to crash when 
an attempt is being made*/
    fp=fopen("exercise2.txt","r+");
    printf("%ld",ftell(fp));

    while(!feof(fp)){
        printf("%c", fgetc(fp));
    }
    //overwrite the first 4 characters
    rewind(fp);
    fprintf(fp,"XXXX");
    //rewind to make file ready to be read from the 
    // beginning
    rewind(fp);
    
    while(!feof(fp)){
        printf("%c", fgetc(fp));
    }    

    fclose(fp);
    return 0;
}