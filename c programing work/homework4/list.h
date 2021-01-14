#ifndef _LIST_H_
#define _LIST_H_

struct node { 
    int data;
    struct node * next; 
};

typedef struct node Node;


Node * find_tail(Node * someNode);
Node * new_node_with_data(int data);
Node * append_data(Node * head, int data);
Node * delete_node(Node * head, Node * someNode);
int count(Node * head);
void print_list(Node * head);
int free_list(Node * head);
Node * find_node(Node * head,int count);
Node *delete_midnode(Node *head,int count);
void print_node(Node * node);
void print_cnode(Node * node);

#endif