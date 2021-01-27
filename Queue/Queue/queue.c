#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node 
{
    int data;
    struct node* next;
}node;

node* create_node();
bool enqueue(node** list, int num);
bool dequeue(node** list, int *num);

int main(void)
{
    node* head = create_node();
    int num1 = 0;
    int num2 = 0;
    if (enqueue(&head, 3) == false) 
    {
        printf("is error\n");
    }
    
    enqueue(&head, 4);
    dequeue(&head, &num1);
    dequeue(&head, &num2);
    printf("return : %i \n", num1);
    printf("return : %i \n", num2);

    if (dequeue(&head, &num2) == false) 
    {
        printf("is error");
        free(head);
        return -1;
    }
    free(head);
}

node* create_node()
{
    node* headNode = malloc(sizeof(node));
    if (headNode == NULL)
    {
        printf("���Ḯ��Ʈ ������ ������ ������ϴ�.\n");
        return NULL;
    }
    headNode->data = NULL;
    headNode->next = NULL;

    return headNode;
}
bool enqueue(node** list, int num)
{
    node* link = *list;
    if (link->data == NULL) //headNode�� �ƹ��͵� ����Ǿ����� ���� ���
    {
        link->data = num;
        link->next = NULL;
        printf("enqueue : %i \n",link->data);
    }
    else
    {
        node* newNode = malloc(sizeof(node));
        if (newNode == NULL)
        {
            printf("�� ��带 �����ϴµ� ������ ������ϴ�.\n");
            return false;
        }
        newNode->data = num;
        newNode->next = NULL;

        node* insert = newNode;
        while (link->next != NULL)
        {
            link = link->next;
        }
        link->next = insert;
        printf("enqueue: %i\n",insert->data);
    }
    return true;
}
bool dequeue(node** list, int *num)
{
    node* front = *list;    //front�� �� ���
    int tmp = 0; //��ȯ�� ����� �� ����
    if (front->data == NULL && front->next == NULL)
    {
        printf("��ȯ�� ��尡 �����ϴ�.(Buffer UnderFlow)\n");
        return false;
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
    *num = tmp;
    return true;
}