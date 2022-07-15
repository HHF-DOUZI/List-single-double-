#include "stdio.h"
#include "stdlib.h"

struct student
{
    char name[20];
    int number;
    int math;
};

struct Node
{
    struct student data;                    /* 数据 */
    struct Node *next;                      /* 指向下一个 */
};

/* 创建节点 */
struct Node *creaList()
{
    struct Node * headNode = (struct Node*)malloc(sizeof(struct Node));

    headNode->next = NULL;

    return headNode;
}

/* 创建节点 */
struct Node *creaNode(struct student data)
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
    printf("name\tnum\tmath\n");
    while(pMove)
    {
        printf("%s\t%d\t%d\n", pMove->data.name, pMove->data.number, pMove->data.math);
        pMove = pMove->next;
    }
    printf("\n");
}

/* 插入节点 */
void   insertNodeByHeadNode(struct Node *headNode, struct student data)
{
    struct Node *newNode = creaNode(data);

    newNode->next = headNode->next;
    headNode->next = newNode;
}

/* 删除链表 */
void delateListBySpot(struct Node *headNode, int num)
{
    struct Node *posNode = headNode->next;
    struct Node *posNodeFront = headNode;

    if(posNode == NULL)
    {
        printf("无法删除,链表为空");
    }
    else
    {
        while(posNode->data.number != num)
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
    struct student info;
    while(1)
    {
        printf("请输入学生的姓名 学号 数学成绩：");
        setbuf(stdin, NULL);
        scanf("%s%d%d", info.name, &info.number, &info.math);
        insertNodeByHeadNode(List, info);
        printf("continue(Y/N)?\n");
        setbuf(stdin, NULL);
        int choice = getchar();
        if(choice == 'N' || choice == 'n')
        {
            break;
        }
    }
    printList(List);
    printf("请输入要删除学生的编号：");
    scanf("%d", &info.number);
    delateListBySpot(List, info.number);
    printList(List);

    return 0;
}