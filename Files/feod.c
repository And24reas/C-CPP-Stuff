/*found end of file size_t feof(file pointer)
while(!feof(fp))->while end of file has not
yet been reached*/
#include <stdio.h>
#include <stdlib.h>

#define N 10

struct point{
    int x;
    int y;
};
int main(){
    FILE *fp;
    int i;
    struct point data;
    fp=fopen("binarydata.dat","rb");

    if(fopen==NULL){
        printf("Erro while processing file");
        exit(0);
    }

    while(!feof(fp)){
        if((fread(&data, sizeof(struct point), 1, fp))==1){
            printf("%d %d", data.x, data.y);
        }

    }
    fclose(fp);
}