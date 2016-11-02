//
//  main.c
//  algo
//
//  Created by donhyun Kim on 2016. 11. 2..
//  Copyright © 2016년 donhyun Kim. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>




typedef struct tagNode{
    
    int data;
    struct tagNode* prev;
    struct tagNode* next;
    
}node;


//노드를 만드는 함수
node* createNode(int newDate);

//노드 추가 함수
void appendNode(node** head, node* newNode);


//노드 소멸
void destroyNode(node* node);


//노드 탐색
node* getNodeAt(node* head, int location);

//노드 삭제
void deleteNode(node** head,node* remove);

//앞에 노드 넣기
void insertAfter(node* current, node* newNode);


//노드 세기
int getNodeCount(node* head);

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}




node* createNode(int newData){
    
    
    node* newNode = (node*)malloc(sizeof(node));
    
    newNode->data = newData;
    newNode->prev = NULL;
    newNode->next = NULL;
    
    return newNode;

}


void appendNode(node** head, node* newNode){
    
    //헤드 노드가 없다면
    if( (*head) == NULL)
    {
        *head = newNode;
    }
    else{
        
        //테일을 찾아 newNode를 연결한다.
        node* tail = (*head);
        while(tail->next != NULL){
            tail = tail->next;
            
        }
        tail->next = newNode;
        //기존의 테일 주소를 넣는다.
        newNode->prev = tail;
    }
}

    
node* getNodeAt(node* head, int location){
        
        
        //처음에는 head에 위치 시킨다.
        node* current = head;
        //location 만큼 돈다.
    
    
        while( current!=NULL &&  location>0){
            current = current->next;
            location--;
        }
    
    return current;
        
}


void destroyNode(node* node){
    
    free(node);
    
}


void deleteNode(node** head,node* remove){
    
    if(*head == remove){
        //헤드를 바꾼다.
        (*head) = remove->next;
        //head를 바꾼 후 NULL이 아니라면 이전 주소를 NULL로 설정
        if((*head)!=NULL){
            (*head)->prev = NULL;
        }
        
        //삭제하는 노드의 prev, next를 NULL로 설정
        remove->prev = NULL;
        remove->next = NULL;
    }
    else{
        node* temp = remove;
        remove->prev->next = temp->next;
        
        //테일이 아닌 경우
        if(remove->next !=NULL)
        remove->next->prev = temp->prev;
        
        remove->next = NULL;
        remove->prev = NULL;
        
    }
    
    
}

void insertAfter(node* current, node* newNode){
    
    newNode->next = current->next;
    newNode->prev = current;
    
    //테일이 아닌 경우
    if(current->next != NULL){
        current->next->prev = newNode;
        
    }
    current -> next = newNode;
    
    
    
}


int getNodeCount(node* head){
    int count = 0;
    
    node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
        count++;
    }
    
        
        
        
        return count;
}


