//
//  binarySearch.c
//  algo
//
//  Created by donhyun Kim on 2016. 11. 4..
//  Copyright © 2016년 donhyun Kim. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>



//이진 검색 트리 - 정렬된 상태에서만 사용가능하다.
int binarySearch(int* dataSearch, int size, int target);
//숫자 비교 함수
int compareNumber(const void *_elem1, const void *_elem2);

int main(){
    
    
    //int i = 0;
    int dataSearch[] = {10,2,3,90,39,65,30};
    
    
    int size = sizeof(dataSearch)/sizeof(dataSearch[0]);
    
    
    qsort((void*)dataSearch,size,sizeof(int),compareNumber);
    /*
    for(i= 0; i<sizeof(dataSearch)/sizeof(dataSearch[0]);i++){
        printf(" %d",dataSearch[i]);
    }
    printf("\n");
    */
    
    
    int check = binarySearch(dataSearch,size,39);
    
    if(check < 0){
        printf("No number!!!\n");
    }
    else{
        printf("Check!!! I got it!!!\n");
    }
    
    
    
    return 0;
}



int binarySearch(int* dataSearch, int size, int target){
    
    int leftPos, rightPos, midPos;
    

    leftPos = 0;
    rightPos = size-1;
 
    // 탐색 범위가 0이 될 때까지 루프를 반복.
    while(leftPos <= rightPos){
        midPos = (leftPos + rightPos)/2;
        if(target < dataSearch[midPos])
             return dataSearch[midPos];
        //left와 right의 위치를 계속 바꾸어 줘야 한다.
        else if(target < dataSearch[midPos])
            rightPos = midPos - 1;
        else
            leftPos = midPos + 1;
    }
    
    return -1;
}



int compareNumber(const void *_elem1, const void *_elem2){
    
    int* elem1 = (int*)_elem1;
    int* elem2 = (int*)_elem2;
    
    if(*elem1 > *elem2)
        return 1;
    else if(*elem1 < *elem2)
        return -1;
    else
        return 0;
    
    
}
