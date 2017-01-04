//
//  heap.h
//  algo
//
//  Created by donhyun Kim on 2016. 11. 8..
//  Copyright © 2016년 donhyun Kim. All rights reserved.
//

#ifndef heap_h
#define heap_h

#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

typedef int ElementType;


typedef struct tagHeapNode{
    ElementType data;
}heapNode;


typedef struct tagHeap{

    heapNode* node;
    //생산 능력
    int capacity;
    //사용하고 있는 용량
    int usedSize;

}heap;

//힙 생성 함수
heap* heapCreate(int init);
//힙 소멸 함수
void heapDestroy(heap* h);
//힙 삽입 함수
void heapInsert(heap* h, ElementType newData);
//최소힙 삭제 함수
void heapDeleteMin(heap* h, heapNode* root);
//부모 위치 확인 함수
int heapGetParent(int index);
//왼쪽 자식 위치 확인 함수
int heapGetLeftChild(int index);
//노드 바꾸는 함수
void heapSwapNode(heap* h, int index1, int index2);
//노드 출력 함수
void heapPrintNodes(heap* h);



#endif /* heap_h */
