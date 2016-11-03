//
//  bubbleSort.c
//  algo
//
//  Created by donhyun Kim on 2016. 11. 3..
//  Copyright © 2016년 donhyun Kim. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>


//버블정렬 예제

void bubbleSort(int* dataSort, int len);


int main(){
    
    
    int dataSort[] = {6,3,4,2,7,8,1};
    
    int len = sizeof(dataSort)/sizeof(dataSort[0]);
    int i = 0;
    
    bubbleSort(dataSort,len);
    
    
    
    for(i=0;i<len;i++){
    printf(" %d",dataSort[i]);
    
    }
    
    
    
    
    return 0;
    
}

void bubbleSort(int* dataSort, int len){
    
    int temp = 0;
    int i,j = 0;
    
    //바깥에 있는 for 루프는 데이터 집합의 크기마큼 내부에 있는 for loop을 실행 합니다.
    for(i=0;i<len;i++){
        //내부에 있는 for루프는 바깥에 있는 for 루프가 한번 싱핼 될깨마다 그 반복 횟수가 줄어들기 때문에 i만큼 빼주어야 한다.
        for(j = 0;j<len-i;j++){
            
        if(dataSort[j] > dataSort[j+1])
        {
            temp = dataSort[j];
            dataSort[j] = dataSort[j+1];
            dataSort[j+1] = temp;
            
        }
        }
        
        
    }
    
    
}
