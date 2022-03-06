/*create a temporary file with some random text
and practise file opening with mode-a
1. Check the position of the cursor
2. write 4 characters in the file
3. return the cursor to the beginning of the file
4. print the file on the screen*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fp;
    fp=fopen("tmp.txt","w");
    if(fp==NULL)
        exit(0);
    fprintf(fp,"0123456789");
    fclose(fp);

    fp=fopen("random.txt","a+");
    printf("Position: %ld\n", ftell(fp));

    fprintf(fp,"XXXX");
    //brings cursor back to position 0
    rewind(fp);
    while(!feof(fp)){
        printf("%c",fgetc(fp));
    }
    printf("\n");
    fclose(fp);   
}