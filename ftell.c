/*long ftell FILE *fp 
returns the position of the cursor within the file
in terms of bytes. In the case of a file with characters
by default it returns the number of characters of the file
since each character is equal to one byte*/

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
    //should return 0
    printf("\npos: %d\n",ftell(fp));
    for(i=0;i<5;i++){
        printf("%c", fgetc(fp));
    }
    printf("\npos:%d\n", ftell(fp));

    rewind(fp);

    printf("\npos: %d\n", ftell(fp));

    while((c=fgetc(fp))!=EOF)
        printf("%c",c);
    
    printf("\npos: %d\n", ftell(fp));
    fclose(fp);
}
