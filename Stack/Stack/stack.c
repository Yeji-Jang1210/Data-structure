#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
}node;

node* create_node();
int push(node** list, int num);
int pop(node** list);
int read_size(node** list);

int main(void) 
{
    node* head = create_node();
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);
    printf("pop : %i\n", pop(&head));
    printf("size : %i\n", read_size(&head));
    printf("pop : %i\n", pop(&head));
    free(head);
}
node* create_node() 
{
    node* newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL) 
    {
        printf("헤더노드 생성 실패");
        return NULL;
    }
    newNode->data = NULL;
    newNode->next = NULL;
}
int push(node** list, int num) 
{
    node* old_node = *list;
    if (old_node->data == NULL) 
    {
        old_node->data = num;
        old_node->next = NULL;
        printf("push : %i\n", old_node->data);
    }
    else {
        node* newNode = (node*)malloc(sizeof(node));
        if (newNode == NULL)
        {
            printf("새 노드를 생성 실패");
            return 1;
        }
        newNode->data = num;
        newNode->next = NULL;

        while (old_node->next != NULL)
        {
            old_node = old_node->next;
        }
        old_node->next = newNode;
        printf("push : %i\n", newNode->data);
    }
}
int pop(node** list) 
{
    node* last_node = *list;
    node* pop_node = *list;
    int pop_num = 0;
    if (last_node == NULL) 
    {
        printf("반환할 값이 없습니다. : stack underflow");
        return 1;
    }
    else {
        if (pop_node->next == NULL)
        {
            pop_num = pop_node->data;
            pop_node->data = NULL;
        }
        else
        {
            int count = 0;
            int size = read_size(list);
            while (count < size - 1 && last_node->next != NULL)
            {
                last_node = last_node->next;
                count++;
            }
            pop_node = last_node->next;
            if (pop_node == NULL) 
            {
                printf("pop_node : NULL\n");
                return 1;
            }
            pop_num = pop_node->data;
            last_node->next = NULL;
            free(pop_node);
        }
        return pop_num;
    }
}
int read_size(node** list) 
{
    node* read_node = *list;
    int size = 0;
    while (read_node->next != NULL) 
    {
        read_node = read_node->next;
        size++;
    }
    return size;
}