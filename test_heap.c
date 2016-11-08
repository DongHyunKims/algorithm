//
//  test_heap.c
//  algo
//
//  Created by donhyun Kim on 2016. 11. 8..
//  Copyright © 2016년 donhyun Kim. All rights reserved.
//


#include "heap.h"

int main(void){
    heap* h = heapCreate(3);
    
    heapNode minNode;
    
    heapInsert(h, 12);
    heapInsert(h, 87);
    heapInsert(h, 111);
    heapInsert(h, 34);
    heapInsert(h, 16);
    heapInsert(h, 75);
    heapPrintNodes(h);
    
    
    heapDeleteMin(h, &minNode);
    heapPrintNodes(h);
    
    heapDeleteMin(h, &minNode);
    heapPrintNodes(h);
    
    heapDeleteMin(h, &minNode);
    heapPrintNodes(h);
    
    heapDeleteMin(h, &minNode);
    heapPrintNodes(h);
    
    heapDeleteMin(h, &minNode);
    heapPrintNodes(h);
    
    heapDeleteMin(h, &minNode);
    heapPrintNodes(h);
    
    
    
    
    
    
    return 0;
    
    
    
}
