#include<stdio.h>
#include<time.h>

long long int factIterative(int num);
long long int factRecursive(int num);

int main(){


    long long int num,factorialIterative,factorialRecursive;
    scanf("%d",&num);
    clock_t beginIterative = clock();
    factorialIterative = factIterative(num);
    clock_t endIterative = clock();
    
    double time_spent_Iterative = (double)(endIterative - beginIterative) / CLOCKS_PER_SEC;
	
    clock_t beginRecursive = clock();
    factorialRecursive = factRecursive(num);
    clock_t endRecursive = clock();
    double time_spent_Recursive = (double)(endRecursive - beginRecursive) / CLOCKS_PER_SEC;
    
	printf("executiontime Iterative example : %f \n executiontime Recursive example : %f", time_spent_Iterative,time_spent_Recursive);
	printf("\n Answer1: %lld \n Answer2: %lld", factIterative,factRecursive);
}

long long int factIterative(int num){

	int toReturn = 1;
	if(num == 0 || num == 1){
		return 1;
	}

	else{
		while(num>1){
			toReturn *=num;
			num--;
			
		}
	}
	return toReturn;
}

long long int factRecursive(int num){
	if(num == 1 || num == 0){
		return 1;
	}else{
		return num*factRecursive(num-1);
	}
}
