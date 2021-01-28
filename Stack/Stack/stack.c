#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node 
{
    int data;
    struct node* next;
}node;
node* create_node();
bool push(node** list, int num);
bool pop(node** list,int *a);
int read_size(node** list);

int main(void) 
{
    node* head = create_node();
    int a = 0;
    int b = 0;
    int d = 0;
    if (push(&head, 3) == false) 
    {
        printf("is error\n");
    }
    push(&head, 3);
    push(&head, 4);
    pop(&head, &a);
    pop(&head, &b);
    printf("pop : %i %i\n", a,b);

   if (pop(&head, &d) == false) 
    {
        printf("is error\n");
        free(head);
        return -1;
    }
   else
   {
       printf("pop : %i", d);
   }
    free(head);
}
node* create_node() 
{
    node* newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL) 
    {
        printf("헤더노드 생성 실패\n");
        return NULL;
    }
    newNode->data = NULL;
    newNode->next = NULL;
    return newNode;
}
bool push(node** list, int num) 
{
    node* old_node = *list;
    if (old_node->data == NULL) 
    {
        old_node->data = num;
        old_node->next = NULL;
        printf("push : %i\n", old_node->data);
    }
    else 
    {
        node* newNode = (node*)malloc(sizeof(node));
        if (newNode == NULL)
        {
            printf("새 노드를 생성 실패\n");
            return false;
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
    return true;
}
bool pop(node** list,int *a) 
{
    node* last_node = *list;
    node* pop_node = *list;
    int pop_num = 0;
    if (last_node->data == NULL && pop_node->data == NULL)
    {
        printf("반환할 값이 없습니다. : stack underflow\n");
        return false;
    }
    else 
    {
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
                return false;
            }
            pop_num = pop_node->data;
            last_node->next = NULL;
            free(pop_node);
        }
        *a = pop_num;
    }
    return true;
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