/*int fseek(FILE *fp, long offset, int origin)
positions the cursor (offset)-bytes form origin
origin can be SEEK_SET->beginning of FILE
SEEK_CUR->current cursor position, or SEEK_END->end of file
SEEK_SET=0,SEEK_CUR=1,SEEK_END=2, returns 0 if succesfull 
otherwise returns non-zero value
*/
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
    if (fp==NULL){
        printf("Error in opening file");
        exit(0);
    }

    printf("To which element should the cursor be moved?(0-9):");
    scanf("%d",&i);
    fseek(fp, sizeof(struct point)*i, SEEK_SET);
    fread(&data,sizeof(struct point),1,fp);

    printf("Element %d:", i);
    printf("%d %d\n", data.x, data.y);
    fclose(fp);    
}