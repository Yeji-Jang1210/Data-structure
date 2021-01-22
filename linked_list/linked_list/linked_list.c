#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

node* create_node();
void insert_node(node** list, int index, int num);
int read_node(node* list,int index);
int update_node(node* list, int index, int newNum);
int delete_node(node* list , int index);

int main(void) 
{
    node* head = create_node(); //head��� �ּҸ� ���� head������ ����
    insert_node(&head, 0, 2);   //head�� �ּҸ� �Ѱ���
    insert_node(&head, 1, 3);
    insert_node(&head, 0, 5);
    insert_node(&head, 5, 1);

    printf("read node : %i\n",read_node(head, 0));
    update_node(head, 0, 7);
    delete_node(head, 2);
    free(head);
}

node* create_node()     //headNode ����
{
    node *newNode = malloc(sizeof(node));
    if (newNode == NULL)
    {
        printf("�޸� �Ҵ� ����");
        return NULL;
    }
    newNode->data = NULL;     
    newNode->next = NULL;     //�� ����� ���� �ּҴ� �����Ƿ� null
    return newNode;         //�� ����� �ּҸ� return
}

void insert_node(node **list, int index, int num)   //**list : head�ּ��ǰ�(newNode�ּ�)�� ����Ű�� ������
{
    node *link = *list; //link�����Ϳ� list�� ���� (link�� newNode�ּҸ� ����)
    int i = 0;

    if (link->data == NULL)     //1.headNode�ϰ��
    {
        link->data = num;
        printf("insert %i \n", link->data);
    }
    else {
        node* newNode = malloc(sizeof(node));   //�� ��� �߰�
        if (newNode == NULL)
        {
            printf("�޸� �Ҵ� ����");
            return NULL;
        }
        newNode->data = num;
        newNode->next = NULL;     //�� ����� ���� �ּҴ� �����Ƿ� null

        if (index == 0)     //2.���� ù��° ����
        {
            newNode->next = link;
            *list = newNode; //���θ��� ����� �ּҰ��� ����
        }
        else
        {
            while (i != index - 1 && link->next != NULL)
            {
                link = link->next;
                i++;
            }
            if (link->next != NULL)    //3.�߰��� ����
            {
                newNode->next = link->next;
            }
            link->next = newNode;    //4.�������� ����
        }
        printf("insert %i \n", newNode->data);
    }
}   

int read_node(node* list,int index) 
{
    node* readNode = list; 
    int i = 0;
    while (i != index && readNode->next != NULL)
    {
        readNode = readNode->next;
        i++;
    }
    if (readNode->next == NULL) 
    {
        printf("�������� �ε����� ����Ʈ���� ŭ\n");
        return 1;
    }
    printf("read node index : %i, node : %i \n", i, readNode->data);
    return readNode->data;
}

int update_node(node* list, int index, int newNum) 
{
    node *update_Node = list;
    int i = 0;
    while (i != index && update_Node->next != NULL)
    {
        update_Node = update_Node->next;
        i++;
    }
    if (update_Node->next != NULL) {
        printf("update�Ϸ��� �ε����� ����Ʈ���� ŭ");
        return 1;
    }
    printf("update node before : %i, ", update_Node->data);
    update_Node->data = newNum;
    printf("after : %i \n", update_Node->data);
}

int delete_node(node* list, int index) 
{
    node *delete = list;
    node *link = list;
    int i = 0;
    if (!index)     //�����Ϸ��� ����� �ε����� 0�� ���̸� -> list�� �ּ��ϰ��
    {   
        link = link->next;  //list�� �����ּҸ� ����Ŵ
        printf("delete : %i", delete->data);
        free(delete);    
    }
    else {
        while (i != index-1 && link->next != NULL)
        {
            link = link->next;
            i++;
        }
        delete = link->next;
        if (delete == NULL) 
        {
            printf("�����Ϸ��� �ε����� ����Ʈ���� ŭ");
            return 1;
        }
        link->next = delete->next;
        printf("delete %i \n", delete->data);
        free(delete);
    }
}
