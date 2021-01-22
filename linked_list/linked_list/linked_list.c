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
    node* head = create_node(); //head노드 주소를 가진 head포인터 만듬
    insert_node(&head, 0, 2);   //head의 주소를 넘겨줌
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

node* create_node()     //headNode 생성
{
    node *newNode = malloc(sizeof(node));
    if (newNode == NULL)
    {
        printf("메모리 할당 실패");
        return NULL;
    }
    newNode->data = NULL;     
    newNode->next = NULL;     //새 노드의 다음 주소는 없으므로 null
    return newNode;         //새 노드의 주소를 return
}

int insert_node(node **list, int index, int num)   //**list : headnode를 가르키는 주소의 주소
{
    node *link = *list; //link포인터에 list값 복사 (link는 headnode주소를 가짐)
    int i = 0;

    if (link->data == NULL)     //1.headNode일경우
    {
        link->data = num;
        printf("index : %i, insert %i \n",index, link->data);
    }
    else {
        node* newNode = malloc(sizeof(node));   //새 노드 추가
        if (newNode == NULL)
        {
            printf("메모리 할당 실패");
            return 1;
        }
        newNode->data = num;
        newNode->next = NULL;     //새 노드의 다음 주소는 없으므로 null

        if (index == 0)     //2.제일 첫번째 삽입
        {
            newNode->next = link;
            *list = newNode; //새로만든 노드로 주소값 변경
        }
        else
        {
            while (i != index - 1 && link->next != NULL)
            {
                link = link->next;
                i++;
            }
            if (link->next != NULL)    //3.중간에 삽입
            {
                newNode->next = link->next;
            }
            link->next = newNode;    //4.마지막에 삽입
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
        printf("읽으려는 인덱스가 리스트보다 큼\n");
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
        printf("update하려는 인덱스가 리스트보다 큼");
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
    if (index == 0)     //삭제하려는 노드의 인덱스가 0이면 -> list의 주소일경우
    {   
        *list = link->next;  //list는 다음주소를 가리킴
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
            printf("삭제하려는 인덱스가 리스트보다 큼");
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
        printf("연결리스트가 존재하지 않습니다");
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