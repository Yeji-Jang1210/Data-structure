#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
}node;

node* create_node();
int enqueue(node** list, int num);
int dequeue(node** list);

int main(void) 
{
    node *head = create_node();
    enqueue(&head, 3);
    enqueue(&head, 4);
    printf("return : %i \n",dequeue(&head));
    printf("return : %i \n", dequeue(&head));
    free(head);
}

node* create_node() 
{
    node* headNode = (node*)malloc(sizeof(int));
    if (headNode == NULL) 
    {
        printf("연결리스트 생성에 오류가 생겼습니다.");
        return NULL;
    }
    headNode->data = NULL;
    headNode->next = NULL;
}
int enqueue(node** list, int num)
{
    node* link = *list;
    if (link->data == NULL) //headNode에 아무것도 연결되어있지 않을 경우
    {
        link->data = num;
        link->next = NULL;
        printf("enqueue : %i\n", link->data);
    }
    else
    {
        node* newNode = (node*)malloc(sizeof(int));
        if (newNode == NULL)
        {
            printf("새 노드를 삽입하는데 오류가 생겼습니다.");
            return 1;
        }
        newNode->data = num;
        newNode->next = NULL;

        node* insert = newNode;
        while (link->next != NULL)
        {
            link = link->next;
        }
        link->next = insert;
        printf("enqueue : %i\n", insert->data);
    }
}
int dequeue(node **list) 
{
    node* front = *list;
    node* r_node = *list;
    int tmp = r_node->data;
    if (r_node->data == NULL) 
    {
        printf("반환할 노드가 없습니다.(Buffer UnderFlow)");
        return 1;
    }
    else {
        
        if (front->next == NULL)    //다음값이 없을경우
        {
            front->data = NULL;     //NULL값으로 만들어줌(초기 헤더노드만 생성했을때의 상태)
            return tmp;
        }
        else
        {
            front = front->next;
            free(r_node);
            return tmp;
        }
    }
}