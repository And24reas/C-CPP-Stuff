#include <stdio.h>
#include <stdlib.h>

int main(){
    //creation and opening of file
    FILE *fp = fopen("test.txt", "w");
    int x = 1;
    if(fp==NULL){
        printf("Error during creation of file");
        exit(0);
    }
    
    //Writing into the file
    fprintf(fp,"A random line\n");
    fprintf(fp,"Added random numbers: %d %d %d", x, x*2, x/2);

    //close file
    fclose(fp);


}