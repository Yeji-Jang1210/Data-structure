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
    node* n = malloc(sizeof(node)); //새로운 노드 만듬
    if (n == NULL)
    {
        return 1;
    }
    n->data = num;     //노드에 값 저장
    n->next = NULL;     //새 노드의 다음 주소는 없으므로 null

    if (list == NULL)   //노드 연결
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
    if (!index)     //삭제하려는 노드의 인덱스가 0이 참이면 -> list의 주소일경우
    {   
        link = link->next;  //list는 다음주소를 가리킴
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
            printf("삭제하려는 인덱스가 리스트보다 큼");
            return NULL;
        }
        link->next = delete->next;
        printf("delete %i \n", delete->data);
        free(delete);
    }
}
