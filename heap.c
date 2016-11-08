//
//  heap.c
//  algo
//
//  Created by donhyun Kim on 2016. 11. 8..
//  Copyright © 2016년 donhyun Kim. All rights reserved.
//

#include "heap.h"


//힙 생성 함수
heap* heapCreate(int init){
    
    //capacity 만큼의 용량을 차지하는 heap을 생성한다.
    heap* newHeap = (heap*)malloc(sizeof(heap));
    newHeap->capacity = init;
    newHeap->usedSize = 0;
    newHeap->node = (heapNode*)malloc(sizeof(heapNode) * newHeap->capacity);
    
    printf("size : %d\n",(int)sizeof(heapNode));
    
    
    return newHeap;
    
}



//힙 소멸 함수
void heapDestroy(heap* h){
    
    free(h->node);
    free(h);
    
    
}


//힙 삽입 함수
void heapInsert(heap* h, ElementType newData){
    //현재 위치
    int currentPosition = h->usedSize;
    //부모의 위치
    int parentPosition = heapGetParent(currentPosition);
    
    
    
    if(h->usedSize == h->capacity){
        h->capacity *= 2;
        h->node = (heapNode*)realloc(h->node, sizeof(heapNode) * h->capacity);
    }
    
    h->node[currentPosition].data = newData;
    
    //현재의 데이터가 부모 위치의 데이터 보다 작은경우
    while(currentPosition >0 && h->node[currentPosition].data < h->node[parentPosition].data){
        heapSwapNode(h, currentPosition, parentPosition);
        currentPosition = parentPosition;
        parentPosition = heapGetParent(currentPosition);
        
        
        
    }
    //가용공간을 하나 더 늘려준다.
    h->usedSize++;
}

//최소힙 삭제 함수
void heapDeleteMin(heap* h, heapNode* root){
    int parentPosition = 0 ;
    int leftPosition = 0;
    int rightPosition = 0;
    
    //root변수에 맨위의 것을 복사한다.
    memcpy(root,&h->node[0],sizeof(heapNode));
    //0으로 채운다. -> 삭제한다?
    memset(&h->node[0], 0, sizeof(heapNode));
    
    
    //삭제 했으므로 가용공간을 하나 줄여준다.
    h->usedSize--;
    heapSwapNode(h, 0, h->usedSize);
    
    //root의 왼쪽 자식 번호 추출
    leftPosition = heapGetLeftChild(0);
    //root의 오른쪽 자식 번호 추출
    rightPosition = leftPosition+1;
    
    //제 위치를 찾아가야한다.
    while(1){
        int selectedChild = 0;
        
        if(leftPosition >= h->usedSize){
            break;
        }
        //왼쪽 자식만 있다면
        if(rightPosition >= h->usedSize){
            selectedChild = leftPosition;
        }
        else{
            //더 작은것을 선택한다.
            if(h->node[leftPosition].data > h->node[rightPosition].data){
                selectedChild = rightPosition;
            }
            else{
                selectedChild = leftPosition;
            }
            
        }
    
        //자식이 작다면 바꾸어 주어야한다.
        if(h->node[selectedChild].data < h->node[parentPosition].data){
            heapSwapNode(h, parentPosition, selectedChild);
            parentPosition = selectedChild;
        }
        else{
            break;
        }
        
        leftPosition = heapGetLeftChild(parentPosition);
        rightPosition = leftPosition + 1;
    }
    
    if(h->usedSize < (h->capacity/2)){
        h->capacity /=2;
        h->node = (heapNode*) realloc(h->node,sizeof(heapNode) * h->capacity);
        
    }
    
    
    
    
    
}
//부모 위치 확인 함수
int heapGetParent(int index){
    
    return (index-1)/2;
    
}
//왼쪽 자식 위치 확인 함수
int heapGetLeftChild(int index){
    
    return (2*index) + 1;
    
    
}
//노드 바꾸는 함수
void heapSwapNode(heap* h, int index1, int index2){
    int copySize = sizeof(heapNode);
    heapNode* tmp = (heapNode*)malloc(copySize);
    
    memcpy(tmp, &h->node[index1], copySize);
    memcpy(&h->node[index1], &h->node[index2], copySize);
    memcpy(&h->node[index2], tmp, copySize);
    
    free(tmp);
}
//노드 출력 함수
void heapPrintNodes(heap* h){
    int i = 0;
    for(i =0;i<h->usedSize;i++){
        printf(" %d",h->node[i].data);
        
    }
    printf("\n");
}
