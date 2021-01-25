#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

node* create_node();
int insert_node(node** list, int index, int num);
int read_node(node* list,int index);
int update_node(node* list, int index, int newNum);
int delete_node(node **list , int index);
int read_list(node** list);

int main(void) 
{
    node* head = create_node(); //head��� �ּҸ� ���� head������ ����
    insert_node(&head, 0, 2);   //head�� �ּҸ� �Ѱ���
    read_list(&head);
    insert_node(&head, 1, 3);
    read_list(&head);
    insert_node(&head, 0, 5);
    read_list(&head);
    insert_node(&head, 5, 1);

    printf("read node : %i\n",read_node(head, 0));
    read_list(&head);
    update_node(head, 0, 7);
    read_list(&head);
    delete_node(&head, 0);
    read_list(&head);
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

int insert_node(node **list, int index, int num)   //**list : headnode�� ����Ű�� �ּ��� �ּ�
{
    node *link = *list; //link�����Ϳ� list�� ���� (link�� headnode�ּҸ� ����)
    int i = 0;

    if (link->data == NULL)     //1.headNode�ϰ��
    {
        link->data = num;
        printf("index : %i, insert %i \n",index, link->data);
    }
    else {
        node* newNode = malloc(sizeof(node));   //�� ��� �߰�
        if (newNode == NULL)
        {
            printf("�޸� �Ҵ� ����");
            return 1;
        }
        newNode->data = num;
        newNode->next = NULL;     //�� ����� ���� �ּҴ� �����Ƿ� null

        if (index == 0)     //2.���� ù��° ����
        {
            newNode->next = link;
            *list = newNode; //���θ��� ���� �ּҰ� ����
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
        printf("index : %i, insert %i \n", index, newNode->data);
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
    if (update_Node->next == NULL) {
        printf("update�Ϸ��� �ε����� ����Ʈ���� ŭ");
        return 1;
    }
    printf("update node before : %i, ", update_Node->data);
    update_Node->data = newNum;
    printf("after : %i \n", update_Node->data);
}

int delete_node(node **list, int index) 
{
    node *delete = *list;
    node *link = *list;
    int i = 0;
    if (index == 0)     //�����Ϸ��� ����� �ε����� 0�̸� -> list�� �ּ��ϰ��
    {   
        *list = link->next;  //list�� �����ּҸ� ����Ŵ
        printf("delete : %i \n", delete->data);
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

int read_list(node** list) 
{
    node *read = *list;
    if (*&read == NULL) 
    {
        printf("���Ḯ��Ʈ�� �������� �ʽ��ϴ�");
        return 1;
    }
    else 
    {
        printf("read all node : ");
        while (read->data != NULL && read->next != NULL)
        {
            printf("%i ", read->data);
            read = read->next;
        }
        printf("%i ", read->data);
        printf("\n");
    }
}