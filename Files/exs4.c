/*Create a program that asks the user for a file name
which will copy the contents of the file into a new file
also named by the user*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *ffrom;
    FILE *fto;
    char file_name[80];
    char new_file_name[80];
    printf("Enter the name of the file to be copied:\n");
    scanf("%s", file_name);

    ffrom = fopen(file_name, "r");
    if(!ffrom){
        printf("The file does not exist");
        exit(0);
    }
    
    
    printf("Give the name of the new file: \n");
    scanf("%s",  new_file_name);

    fto = fopen(new_file_name, "r");
    
    if (fto){
        printf("A file with that name already exists");
        exit(0);
    }

    fclose(fto);
    
    fto = fopen(new_file_name,"w");
    if(!fto){
        printf("Error opening file");
        exit(0);
    }

    while(!feof(ffrom)){
        fputc(fgetc(ffrom),fto);
    }
    fclose(ffrom);
    fclose(fto);

    
    return 0;

}