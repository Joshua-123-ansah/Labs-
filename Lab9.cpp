//Name: Joshua Owusu Ansah 
//Student ID: 71392023

//Name: Samuel Oppong Peprah 
// Student ID: 09002023

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

// Creating a zero multidimentional array.
// The undefined value for this program is 0
// Question A
int** zeroMatrix(int size){
    int** matrix=new int*[size];
    for(int i=0;i<size;++i){
         matrix[i]=new int[size];
        for(int j=0;j<size;++j){
            matrix[i][j]=0;
        }
    }
    return matrix;
}

// Question B
//This is the populated array
int** populateArray(int N){
    int** matrix= zeroMatrix(N);
        for(int k=0;k<2000;++k){
            int i = rand() % N;
            int j = rand() % N;
            if(matrix[i][j]==0){
                matrix[i][j]=1;
            }else{
                matrix[i][j]+=1;
            }
        }
        return matrix;
}
    
    

//Function to print matrix. 

void printMatrix(int size){
    int** arr=populateArray(size);
    int i,j;
    for(i=0;i<size;++i){
        for(j=0;j<size;++j){
            printf("%4d",arr[i][j]);
        }
        cout<<endl;
    }
}

//Question C
void searchValidEntries(int N, int x_1,int y_1,int x_2,int y_2){
    int** arr=populateArray(N);
    for(int i=x_1;i<=x_2;++i){
        for(int j=y_1;j<=y_2;++j){
            if(arr[i][j]>0){
                cout<<"("<<i<<","<<j<<")"<<" :"<<arr[i][j]<<endl;
            }
             
        }
       
    }
}


int main()
{
    /* Question D */
    cout<<"\n First Result"<<endl<<endl;
    searchValidEntries(101,80,1,100,10);

    cout<<"\n Second Result"<<endl<<endl;
    searchValidEntries(101,10,20,40,79);

    cout<<"\n Third Result"<<endl<<endl;
    searchValidEntries(101,1,90,100,100);

    cout<<"\n Forth Result"<<endl<<endl;
    searchValidEntries(101,40,30,70,60);

    cout<<" \nFifth Result"<<endl<<endl;
    searchValidEntries(101,50,50,70,70);

    
    return 0;
}