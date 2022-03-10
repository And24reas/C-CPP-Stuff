#include <iostream>

using namespace std;
#define ROWS 7
#define COLUMNS 6
int main()
{
    int **arr;

    arr=new int * [ROWS];
    if(!arr)cout<<"Error allocating memory!"<<endl;
    
    for(int i=0; i<ROWS; i++){
        arr[i]=new int[COLUMNS];
    }
    
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLUMNS;j++){
            arr[i][j]=i*j;
        }
        
    }
    
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLUMNS; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    
    for(int i=0; i<ROWS;i++)
        delete [] arr[i];

    
    delete [] arr;
    return 0;
}
