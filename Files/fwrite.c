//Write a table of structs in a file
#include <stdio.h>
#include <stdlib.h>

#define N 10

struct point{
    int x;
    int y;
};

int main(){
    FILE *fp;
    char c;
    int i;
    struct point data[N];

    fp = fopen("binarydata.dat", "wb");
    if(fp==NULL){
        printf("Error in opening file");
        exit(0);
    }

    /*random creation of structs*/
    for (i=0;i<N;i++){
        data[i].x=rand()%100;
        data[i].y=rand()%100;
    }

    /* Write the table data into the file
    fwrite(adress of variable, the size of each one, 
    how many should be written, pointer to file)
    for one data element the adress should be passed to 
    the function. But in this case since data is
    an array of struct point, passing data to the function
    gives the adress of the first element in data
    as the first parameter to fwrite*/
    fwrite(data, sizeof(struct point), N, fp);
    fclose(fp);
}
