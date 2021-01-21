#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

node* insert_node(node* list, int num);
int read_node(node* list,int index);
int update_node(node* list, int index, int newNum);
void delete_node(node* list , int index);

int main(void) 
{
    node *list = malloc(sizeof(node));
    list = NULL;    //head node

    list = insert_node(list, 2);
    list = insert_node(list, 3);
    list = insert_node(list, 5);

    printf("read node : %i\n",read_node(list, 0));
    printf("update node : %i\n",update_node(list, 0, 7));
    delete_node(list, 2);
    free(list);
}

node* insert_node(node *list, int num) 
{
    node* n = malloc(sizeof(node)); //���ο� ��� ����
    if (n == NULL)
    {
        return 1;
    }
    n->data = num;     //��忡 �� ����
    n->next = NULL;     //�� ����� ���� �ּҴ� �����Ƿ� null

    if (list == NULL)   //��� ����
    {
        list = n;
    }
    else 
    {
        node* tail_node = list;
        while (tail_node->next != NULL)
        {
            tail_node = list->next;
        }
        tail_node->next = n;
    }
    return list;
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
    printf("update node before : %i, ", update_Node->data);
    update_Node->data = newNum;
    printf("after : %i \n", update_Node->data);
    return update_Node->data;
}

void delete_node(node* list, int index) 
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
            return NULL;
        }
        link->next = delete->next;
        printf("delete %i \n", delete->data);
        free(delete);
    }
}
