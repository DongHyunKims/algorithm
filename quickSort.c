//
//  quickSort.c
//  algo
//
//  Created by donhyun Kim on 2016. 11. 4..
//  Copyright © 2016년 donhyun Kim. All rights reserved.
//

#include <stdio.h>



void swap(int *a, int *b);

int partition(int* dataSort, int left, int right);

void quickSort(int* dataSort , int leftPos, int rightPos);

int main()
{
    
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
    //기준값
    int pivot = dataSort[firstPos];
    
    
    
    leftPos++;
    
    
    //가리키고 있는 위치
    while(leftPos <= rightPos){
        //왼쪽 값이 기준보다 작고 왼쪽위치가 아직 오른쪽 위치 보다 작을떄.
        while(dataSort[leftPos] <= pivot && leftPos < rightPos)
            leftPos++;
        
        //오른쪽 값이 기준보다 크고 왼쪽위치가 오른쪽 위치와 같거나 작을떄.
        while(dataSort[rightPos] > pivot && leftPos <= rightPos)
            rightPos--;
        
        //왼쪽의 위치가 아직도 오른쪽의 위치보다 작다면 두 수를 바꾸어준다.
        if(leftPos < rightPos){
            swap(&dataSort[leftPos], &dataSort[rightPos]);
        }
        else{
            break;
        }
        
        
        
    }
    //전부 교환후 기준 점과 마지막으로 바꾸어 준다.
    swap(&dataSort[firstPos], &dataSort[rightPos]);
    return rightPos;
}


void quickSort(int* dataSort , int leftPos, int rightPos){
    
    if(leftPos< rightPos){
        int index = partition( dataSort,leftPos,rightPos);
        
        
        //왼쪽 부분
        quickSort(dataSort, leftPos, index -1);
        //오른쪽 부분
        quickSort(dataSort, index+1, rightPos);
        
        
        
    }
    
}





