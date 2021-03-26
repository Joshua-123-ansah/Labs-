
#include <iostream>
#include <stdio.h>
#include<stdlib.h>
using namespace std;

//Creating a struct/ It is like a class in java
struct multiDimenPos{
    int row,col;
};

//Signatures 
int linearIndx(int i,int j);
int** multiArray(int size);
void printingMultiArray(int** diArray,int size);
int linearIndx(int i,int j);
void printArray(int* A,int size);
int** zeroMultiArray(int size);
void majorMehtod(int size);
multiDimenPos InverseIdx(int length);

//Creating the multidimentional array
int** multiArray(int size){
    int **diArray=new int* [size];
    int row;
    for(row=0;row<size;row++){
        diArray[row]=new int[size]; //This particula code create the columns of out multidimentional array
    }
    //Generating random number and populating it at the lower part of our multidimentional array
    for(int i=0;i<size;++i)
    {
        for(int j=0;j<size;++j){
            //This will generate values of 0's for the upper part of our multidimentional array
            if(i<j){diArray[i][j]=0;
            }
            else{
                //This will generate values between 0 to 1000 for the lower part of our multidimentional array
                diArray[i][j]=(rand()%1000)+1;}
        }
    }
    return diArray;
}

//Creating a function that will print the above multidimentional array
void printingMultiArray(int** diArray,int size){
    for(int i=0;i<size;++i){
        for(int j=0;j<size;++j){
            printf("%4d",diArray[i][j]);
        }
        cout<<endl;
    }
}

int linearIndx(int i,int j){
    // The variable index will help us get the index for each element in the multdimentional array in our single array when given i and j.
    int index=0;
    for(int a=1;a<=i;++a)
    {
        index+=a;
    }
    index+=j;
    return index;
}

//Creating a function that print the element  of the single array
void printArray(int* A,int size){
    for(int i=0;i<size;++i)
    {
        
        printf("%1d ",A[i]);
    }
}

//Creating a zero multidimentional array that will help us with the question b of the assignment
int** zeroMultiArray(int size){
    int **diArray=new int*[size];
    for(int i=0;i<size;++i){
        diArray[i]=new int[size];
    }
    //Creating the columns of the multiArray
    for(int i=0;i<size;i++){
        for(int j=0;j<size;++j){
            diArray[i][j]=0;
        }
    }
    return diArray;
}

//Creating a major function that will do major computations and movement
void majorMehtod(int size){
    //Creating a multidimentional array
    int** arr=multiArray(size);
    //printing the array
    printingMultiArray(arr,size);
    cout<<endl;
    cout<<endl;

    //Copying the lower triangular element into the single array
    int i=(size*(size-1))/2 +size;
    int* singleArray=(int *)malloc(i*(sizeof(int)));
    for(int i=0;i<size;++i){
        for(int j=0;j<size;++j){
            int indexOfSingleArray=linearIndx(i,j);
            singleArray[indexOfSingleArray]=arr[i][j];
        }
    }

    // Using my printArray function to print elements into the singleArray
    printArray(singleArray,i);
    cout<<endl<<endl;

    int** zerosMultiArray=zeroMultiArray(size);
    for(int a=0;a<i;a++)
    {
        multiDimenPos position=InverseIdx(a);
        zerosMultiArray[position.row][position.col]=singleArray[a];
    }

    cout<<endl;
    //Printing the second matrix
    printingMultiArray(zerosMultiArray,size);

}

multiDimenPos InverseIdx(int length){
    if(length==0)
    {
        multiDimenPos position;
        position.row=0;
        position.row=0;
        return position;
    }
    int index=1;
    int nextIndex=1;
    while((nextIndex<length)&&(length-nextIndex>index))
    {
        index+=1;
        nextIndex+=index;
    }
    multiDimenPos position;
    position.row;
    position.col;
    return position;
}


int main(){
    //Testing the function linear matrix
    cout<<linearIndx(3,1);

    //When the multidimentional array is 6
    majorMehtod(8);
    cout<<endl<<endl;
    //When the multidimentional array is 16
    majorMehtod(16);
    cout<<endl<<endl;
    //When the multidimentional array is 16
    majorMehtod(128);


    return 0;
}