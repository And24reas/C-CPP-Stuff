#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 80
#define TRUE 1
#define FALSE 0

struct record{
    char name[SIZE];
    char surname[SIZE];
    int age;
    int grade;
};

int open(char* file_name, FILE **fp, int *num_elements);
int close(FILE **fp);
int add(FILE *fp);
int read(FILE *fp, int num, int rec, struct record *entry);
int print(struct record temp);
void printall(FILE *fp, int num_elements);


int main(){
    FILE *fp;
    int choice, check, N, rec;
    char file_name[]= "data.dat";
    struct record temp;

    while(1){
        printf("\nMENU:\n=====================");
        printf("\n1. Open file\n====================");
        printf("\n2. Close file\n====================");
        printf("\n3. Add Entry\n====================");
        printf("\n4. Read Entry\n====================");
        printf("\n5. Print all Entries\n====================");
        printf("\n6. Exit \n====================\n");
        scanf("%d", &choice);

        switch(choice){
        case 1:
            check = open(file_name, &fp, &N);
            if(check){
                printf("Successfully opened!");
            }
            else{
                printf("Error");
                exit(0);
            }
            break;
        case 2:
            check = close(&fp);
            if(check){
                printf("Successfully closed!");
            } else{
               printf("Error");
               exit(0);
            }
            break;
            
        case 3:
            check = add(fp);
            if(check){
                printf("Successfully added!");
                N++;
            }
                
            else{
                printf("Error");
                exit(0);
            }
            break;
        case 4:
            printf("Which entry should be read?");
            scanf("%d", &rec);
            check = read(fp, N, rec, &temp);
            if(!check){
                printf("Error index overflow!");
                continue;
            }
                
            printf("\nEntry %d:\n", rec);
            print(temp);
            break;

        case 5:
            printall(fp, N);
            break;
        case 6:
            printf("Bye bye!");
            exit(0);
        default:
            printf("Wrong choice!");

    }
    }
    
    
    return 0;
}

int add(FILE *fp){
    struct record temp;
    printf("Name:\n");
    scanf("%s", temp.name);
    printf("Surname:\n");
    scanf("%s", temp.surname);
    printf("Age:\n");
    scanf("%d", &temp.age);
    printf("Grade:\n");
    scanf("%d", &temp.grade);

    fseek(fp, 0, SEEK_END);
    if(fwrite(&temp, sizeof(struct record), 1, fp)==1)
        return TRUE;
    else
        return FALSE;
}

int close(FILE **fp){
    if(fclose(*fp)==0)
        return TRUE;
    else
        return FALSE;
    
}

int open(char *file_name, FILE **fp, int *num_elements){
    struct record temp;
    *fp = fopen(file_name, "rb");
    if(*fp==NULL){
        printf("The file does not exist\nCreating File ....\n");
        *fp = fopen(file_name, "wb+");
        if(*fp==NULL){
            printf("Error opening file!");
            return FALSE;
        }
        (*num_elements)=0;
        return TRUE;
    }
    else{
        fclose(*fp);
        *fp=fopen(file_name, "rb+");
        if(*fp==NULL){
            printf("Error opening file!");
            return FALSE;
        }
        (*num_elements) = 0;
        while(fread(&temp, sizeof(struct record), 1, *fp) == 1){
            (*num_elements)++;
        }
        return TRUE;
    }
    return 0;
}

int print(struct record temp){
    printf("\nName: %s\nSurname: %s\nAge:%d\nGrade: %d\n", temp.name, temp.surname, temp.age, temp.grade);
}

void printall(FILE *fp, int num_elements){
    struct record temp;
    int i;
    for(i=0; i<num_elements; i++){
        read(fp, num_elements, i, &temp);
        printf("Entry %d\n",i);
        printf("-----------------------");
        print(temp);
    }
}

int read(FILE *fp, int num, int rec, struct record *entry){
    if(rec>=0 && rec <= num -1){
        fseek(fp, rec*sizeof(struct record), SEEK_SET);
        if(fread(entry, sizeof(struct record),1,fp)==1)
            return TRUE;
        else
            return FALSE;       
    }
    else
        return FALSE;
    
}