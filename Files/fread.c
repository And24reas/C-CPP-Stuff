/*read data from a binary file*/
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

    fp=fopen("binarydata.dat","rb");
    if(fp==NULL){
        printf("error while trying to open the file");
        exit(0);
    }
    /*time to read the file, works in the same 
    way as fwrite, the first parametes is the adress
    of the variable where we store the content, followed
    by the size of each variable, the number of 
    variables and a pointer to the actual file*/
    fread(data, sizeof(struct point), N, fp);

    /*Now print the data*/
    for(i=0; i<N; i++){
        printf("%d %d\n", data[i].x, data[i].y);
    }
    fclose(fp);


}