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
    node* head = create_node();
    printf("enqueue : %i\n", enqueue(&head, 3));
    printf("enqueue : %i\n", enqueue(&head, 4));
    printf("return : %i \n", dequeue(&head));
    printf("return : %i \n", dequeue(&head));
    free(head);
}

node* create_node()
{
    node* headNode = malloc(sizeof(node));
    if (headNode == NULL)
    {
        printf("연결리스트 생성에 오류가 생겼습니다.");
        return NULL;
    }
    headNode->data = NULL;
    headNode->next = NULL;

    return headNode;
}
int enqueue(node** list, int num)
{
    node* link = *list;
    if (link->data == NULL) //headNode에 아무것도 연결되어있지 않을 경우
    {
        link->data = num;
        link->next = NULL;
        return link->data;
    }
    else
    {
        node* newNode = malloc(sizeof(node));
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
        return insert->data;
    }
}
int dequeue(node** list)
{
    node* front = *list;    //front가 될 노드
    int tmp = 0; //반환될 노드의 값 저장
    if (front->data == NULL)
    {
        printf("반환할 노드가 없습니다.(Buffer UnderFlow)");
        return 1;
    }

    tmp = front->data;
    if (front->next == NULL)    //다음값이 없을경우
    {
        front->data = NULL;     //NULL값으로 만들어줌(초기 헤더노드만 생성했을때의 상태)
    }
    else
    {
        *list = front->next;
        free(front);
    }
    return tmp;
}