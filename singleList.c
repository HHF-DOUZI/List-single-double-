#include "stdio.h"
#include "stdlib.h"

struct student
{
    char *name;
    int number;
    int math;
};

struct Node
{
    int data;                   /* 数据 */
    struct Node *next;          /* 指向下一个 */
};

/* 创建节点 */
struct Node *creaList()
{
    struct Node * headNode = (struct Node*)malloc(sizeof(struct Node));

    headNode->next = NULL;

    return headNode;
}

/* 创建节点 */
struct Node *creaNode(int data)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

/* 打印链表内容 */
void printList(struct Node *headNode)
{
    struct Node *pMove = headNode->next;
    while(pMove)
    {
        printf("%d\t", pMove->data);
        pMove = pMove->next;
    }
    printf("\n");
}

/* 头插法 */
void  insertNodeByHeadNode(struct Node *headNode, int data)
{
    struct Node *newNode = creaNode(data);

    newNode->next = headNode->next;
    headNode->next = newNode;
}

/* 尾插法 */
void  insertNodeByTailNode(struct Node *headNode, int data)
{
    struct Node *newNode = creaNode(data);

    struct Node *p = headNode;          /* p 用来找到链表的最后面那个节点位置 */
    while(p->next != NULL)              /* 只要p后面的节点不为NULL，循环继续 */
        p = p->next;                    /* 循环成立，p就往后挪动 */
    p->next = newNode;
}

/* 删除链表 */
void delateListBySpot(struct Node *headNode, int posData)
{
    struct Node *posNode = headNode->next;
    struct Node *posNodeFront = headNode;

    if(posNode == NULL)
    {
        printf("无法删除,链表为空");
    }
    else
    {
        while(posNode->data != posData)
        {
            posNodeFront = posNode;
            posNode = posNodeFront->next;
            if(posNode == NULL)
            {
                printf("没有找到相关信息\n");
                return;
            }
        }
        posNodeFront->next = posNode->next;
        free(posNode);
    }

}

int main()
{
    struct Node *List = creaList();

    insertNodeByHeadNode(List, 1);
    insertNodeByHeadNode(List, 2);
    insertNodeByHeadNode(List, 3);
    insertNodeByHeadNode(List, 4);
    printList(List);
    delateListBySpot(List, 2);
    printList(List);

    return 0;
}
