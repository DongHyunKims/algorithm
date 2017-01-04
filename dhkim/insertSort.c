//
//  insertSort.c
//  algo
//
//  Created by donhyun Kim on 2016. 11. 3..
//  Copyright © 2016년 donhyun Kim. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



//삽입 정렬 예제
void insertSort(int* dataSort, int len);


int main(){
    
    
    int dataSort[] = {6,3,4,2,7,8,1};
    
    int len = sizeof(dataSort)/sizeof(dataSort[0]);
    int i = 0;
    
    insertSort(dataSort,len);
    
    for(i=0;i<len;i++){
        printf(" %d",dataSort[i]);
    }
    return 0;
}

void insertSort(int* dataSort, int len){
    
    
    int key = 0;
    int i,j =0;
    
    for(i = 1; i<len ; i++){
        
        //앞보다 뒤가 크면 바꾸지 않는다.
        if(dataSort[i]>=dataSort[i-1])
        continue;
        
        key = dataSort[i];
        
        for(j= 0;j<i; j++){
            
            if(dataSort[j]>key){
                //한칸씩 뒤로 밀어야 한다. param1 복사될 메모리, param2 복사할 메모리 , param3 복사할 바이트
                memmove(&dataSort[j+1],&dataSort[j],sizeof(dataSort[0])*(i-j));
                dataSort[j] = key;
                break;
            }
            
        }
    
    }
    
}
