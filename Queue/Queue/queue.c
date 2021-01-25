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
    enqueue(&head, 3);
    enqueue(&head, 4);
    printf("return : %i \n", dequeue(&head));
    printf("return : %i \n", dequeue(&head));
    free(head);
}

node* create_node()
{
    node* headNode = (node*)malloc(sizeof(int));
    if (headNode == NULL)
    {
        printf("���Ḯ��Ʈ ������ ������ ������ϴ�.");
        return NULL;
    }
    headNode->data = NULL;
    headNode->next = NULL;
}
int enqueue(node** list, int num)
{
    node* link = *list;
    if (link->data == NULL) //headNode�� �ƹ��͵� ����Ǿ����� ���� ���
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
            printf("�� ��带 �����ϴµ� ������ ������ϴ�.");
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
int dequeue(node** list)
{
    node* front = *list;    //front�� �� ���
    int tmp = 0; //��ȯ�� ����� �� ����
    if (front->data == NULL)
    {
        printf("��ȯ�� ��尡 �����ϴ�.(Buffer UnderFlow)");
        return 1;
    }

    tmp = front->data;
    if (front->next == NULL)    //�������� �������
    {
        front->data = NULL;     //NULL������ �������(�ʱ� �����常 ������������ ����)
    }
    else
    {
        *list = front->next;
        free(front);
    }
    return tmp;
}