//
//  quickSortTest.c
//  algo
//
//  Created by donhyun Kim on 2016. 11. 4..
//  Copyright © 2016년 donhyun Kim. All rights reserved.
//

#include <stdio.h>



void swap(int *a, int *b);

int partition(int* dataSort, int leftPos, int rightPos);


void quickSort(int* dataSort, int leftPos, int rightPos);



int main(){
    
    int dataSort[] = {6,3,4,2,7,8,1};
    
    int len = sizeof(dataSort)/sizeof(dataSort[0]);
    int i = 0;
    
    quickSort(dataSort,0,len -1);
    
    for(i=0;i<len;i++){
        printf(" %d",dataSort[i]);
    }
    

    
    
    
    
    return 0;
}


void swap(int *a, int *b){
    
    
    int temp;
    
    
    temp = *a;
    *a = *b;
    *b = temp;
    
}


int partition(int* dataSort, int leftPos, int rightPos){
    
    
    int firstPos = leftPos;
    int pivot = dataSort[firstPos];
    
    
    
    leftPos++;
    
    
    
    
    
    
    while(leftPos < rightPos){
        
        
        while(dataSort[leftPos] < pivot &&  leftPos <  rightPos)
            leftPos++;
        //엇갈리게 하기위해서
        while(dataSort[rightPos] > pivot &&  leftPos <=  rightPos)
            rightPos--;
        
        
        if(leftPos< rightPos){
            swap(&dataSort[leftPos], &dataSort[rightPos]);
        }
        else{
            break;
        }
    }
    
    swap(&dataSort[firstPos], &dataSort[rightPos]);
    
    return rightPos;
}



void quickSort(int* dataSort, int leftPos, int rightPos){
    
    if(leftPos < rightPos){
        int index = partition(dataSort, leftPos, rightPos);
        
        quickSort(dataSort,leftPos,index-1);
        
        
        quickSort(dataSort,index+1,rightPos);
        
        
    }
    
    
    
    
    
    
}

