/*exercise on "w"mode 
1. check the position of the cursor while opening 
the file
2. Write 4 characters into the file
3. rewind the cursor
4. Print the contents onto the screen*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fp;
    fp=fopen("Exercise3.txt","w");
    fprintf(fp,"0123456789");
    fclose(fp);
/*remember that mode w removes all existing content of a file
so position will always be at zero when opening with w mode*/
    fp=fopen("Exercise3.txt","w+");
    printf("Position: %ld\n", ftell(fp));
    fprintf(fp,"XXXX");
    rewind(fp);
/*reading in w-mode will not succeed, since it is only intended 
to write into a file, w+ mode allows that r+ is most commonly 
used in application where reading and writing is required 
since w+ deletes file contents prior to opening*/
    while(!feof(fp)){
        printf("%c", fgetc(fp));
    }

    fclose(fp);
    return 0;
}