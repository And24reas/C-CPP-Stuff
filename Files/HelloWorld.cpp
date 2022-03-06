#include <iostream>
#include <stdio.h>
#include <string.h>

typedef struct key_value{
    char sno[50];
    char col1[50];
    char col2[50];
    char col3[50];
}dict;

void printValues(dict values[]){
    for(int i=0; i<999; i++){
        printf("sno->%s, Col 1 -> %s, Col 2 ->%s, Col3 -> %s", values[i].sno, values[i].col1, values[i].col2, values[i].col3);
    }
}

int calculate_num_line_breaks(char *file_name){
    FILE *fp = fopen(file_name,"r");
    int num_line_breaks;
    if(!fp){
        printf("An error occured!");
    }
    char curr;
    while(!feof(fp)){
        curr=fgetc(fp);
        if(curr=='\n'){
            num_line_breaks++;
        }
            
        else{printf("%c", curr);}

    }
    fclose(fp);
    return num_line_breaks;
}
int main(int argc, char* argv[]){
    int return_value=0;
    return_value=calculate_num_line_breaks("data.csv");
    printf("Number of lines: %d", return_value);
    
    FILE *fp=fopen("data.csv", "r"); //open in read mode

    if (!fp){
        printf("Error occured");
        return 0;
    }

    char buff[1024]; // store first 1024 lines in buffer
    int row_count = 0;
    int field_count = 0;

    dict values[999];
    int i = 0;
    while(fgets(buff, 1024,fp))
    {
        printf("%s\n", buff); //this will parse all the data
        
        field_count = 0;
        row_count++;
        if(row_count == 1)
            continue;
        
        char *field = strtok(buff, ","); //separates all commas
        while(field){
            switch (field_count)
            {
            case 0:
                strcpy(values[i].sno, field);
                break;
            case 1:
                strcpy(values[i].col1, field);
                break;
            case 2:
                strcpy(values[i].col2, field);
                break;
            case 3:
                strcpy(values[i].col3, field);
                break;
            default:
                break;
            }
            
            field = strtok(NULL, ","); //update field value
            field_count++;
        }
        i++;
        
    }

    fclose(fp);
    
    //function to print all the values of the array
    printValues(values);


    return 0;
}

