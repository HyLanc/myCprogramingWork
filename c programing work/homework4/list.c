#include <stdio.h>
#include <stdlib.h>
#include "list.h"

Node * find_tail(Node * someNode){
    Node * current = someNode;
    while(current != NULL && current -> next != NULL)
        current = current->next;
    return current;
}

Node * new_node_with_data(int data){
    Node * newNode = (Node * ) malloc( sizeof(Node)); 
    if (newNode != NULL) {//malloc 可能会失败
        newNode->data = data; 
        newNode->next = NULL;
        
    }
    return newNode; 
}

Node * append_data(Node * head, int data){
    Node * tail = find_tail(head);
    Node * newNode = new_node_with_data(data);
    if(head == NULL)
        return newNode; 
    else {
        tail->next = newNode; 
        return head;
    }
}

Node * delete_node(Node * head, Node * someNode){
    Node * nd = head;
    if (head == NULL || someNode == NULL) //特例
        return NULL;
    if(head == someNode){
        nd = someNode->next;
        free(someNode);
        return nd;
    }
    while(nd!=NULL && nd->next != someNode)
        nd = nd->next;
     if(nd!=NULL){ 
        nd->next = someNode->next;
        free(someNode);
    }
    // 如果没有找到要删除的节点，直接返回头指针
    return head; 
}

int count(Node * head){
    Node * current = head;
    int count = 0;
    while (current != NULL){
        count++;
        current = current -> next;   
    }
    return count;
}

void print_list(Node * head){
    Node * current = head;
    while (current != NULL){
        printf("%d ", current -> data);
        current = current -> next;   
    }
    puts("");
}

int free_list(Node * head){
    int count = 0;
    Node * current = head;
    Node * nextNd = NULL;
    while(current != NULL){
        nextNd = current -> next;
        free(current);
        current = nextNd;
        count++;
    }
    return count; 
}
Node * find_node(Node * head,int count){
    Node * current = head;
    int num=0; 
    while(num<=((count/2)-1)){ 
        current = current->next;
        num++;
    } 
    return current; 
}//找到中间的节点用作之后的删除与修改
Node *delete_midnode(Node *head,int count){
    Node * current =find_node(head,count);
    Node * nd= head;
    while(nd!=NULL&&nd->next!=current)
    nd=nd->next;
    if (nd!=NULL)
    {
        nd->next=current->next;
    }
    return head;
}
void print_node(Node * node){
    printf("%d",node->data);
}
void print_cnode(Node * node){
    printf("%c",node->data);
}