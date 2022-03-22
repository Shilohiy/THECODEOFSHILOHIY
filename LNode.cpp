/*Copyright © 2022 Shilohiy All rights reserved*/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
typedef int ElemType;
//单链表的结构定义
typedef struct LNode
{
    ElemType data;      // data存放节点数据域
    struct LNode *next; //指向后继节点的指针
} LinkNode;             //定义单链表结点类型
//尾插法建立链表
void CreatListR(LinkNode *&L, ElemType Num[], int n) //要改变的变量引用型
{
    L = (LinkNode *)malloc(sizeof(LinkNode)); //申请L的头结点空间
    L->next = NULL;
    LinkNode *s, *r; //用s指向新申请的节点，r之中指向L的终端结点
    int i;
    r = L;                  // r指向头结点，因为此时头结点就是终端结点
    for (i = 0; i < n; ++i) //循环申请n个结点，来接受数组Num中的元素
    {
        s = (LinkNode *)malloc(sizeof(LinkNode)); // s指新申请的结点
        s->data = Num[i];                         //用新申请的结点来接受Num中的一个元素
        r->next = s;                              //用来接纳新结点
        r = r->next;                              // r指向终端结点，以便于接纳下一个到来的结点
    }
    r->next = NULL; //数组Num中所有的元素都已经装入链表L中，L的终端结点的指针域置为NULL，L建立完成
}
//插入链表的数据
bool ListInsert(LinkNode *&L, int i, ElemType e)
{
    int j = 0;
    LinkNode *p = L, *s; // p指向头结点，j重置为0(从头结点开始查找)
    if (i <= 0)
    {
        printf("请输入一个正确的数字！");
        return false; // i不合法，返回false
    }
    while (j < i - 1 && p != NULL) //查找第i-1个结点
    {
        j++;
        p = p->next;
    }
    if (p == NULL)
    {
        printf("没有第%d结点的元素！\n", i);
        return false; //未找到第i-1个结点，返回false
    }
    else //找到第i-1个结点p，插入新的结点并返回true
    {
        s = (LinkNode *)malloc(sizeof(LinkNode));
        s->data = e;       //创建新结点s，其data域值为e
        s->next = p->next; //将结点s插入到p结点之后
        p->next = s;
        return true;
    }
}
//删除链表的数据
bool ListDelete(LinkNode *&L, int i, ElemType &e)
{
    int j = 0;
    LinkNode *p = L, *q;
    if (i <= 0)
    {
        printf("没有第%d结点的元素！\n", i);
        return false; // i不合法，返回false
    }
    while (j < i - 1 && p != NULL) //查找第i-1个结点
    {
        j++;
        p = p->next;
    }
    if (p == NULL)
    {
        printf("没有第%d结点的元素！\n", i);
        return false; //未找到第i-1个结点，返回false
    }
    else //未到第i-1个结点p
    {
        q = p->next; // q指向第i个结点
        if (q == NULL)
        {
            printf("没有第%d结点的元素！\n", i);
            return false; //未找到第i个结点，返回false
        }
        e = q->data;
        p->next = q->next; //从单链表中删除(覆盖)q结点
        free(q);           //释放q结点
        return true;       //返回true表示成功删除第i个结点
    }
}
//打印链表数据
void DispList(LinkNode *L)
{
    LinkNode *temp = L;
    printf("表中的元素为：\n");
    while (temp->next)
    {
        temp = temp->next;
        printf("%d ", temp->data);
    }
    printf("\n");
}
int main()
{
    SetConsoleTitle("线性表顺序存储运算的算法实现");
    LinkNode *L;
    int choose; //说明，choose选择数字
    int n, i;   //说明，n指示操作元素个数，i操作数据元素数组顺序（下标+1）
    while (1)
    {
        printf("*************************************\n");
        printf("*                                   *\n");
        printf("*   线性表顺序存储运算的算法实现    *\n");
        printf("*                                   *\n");
        printf("*      1.输入您的链表               *\n");
        printf("*      2.在链表某一位置插入元素     *\n");
        printf("*      3.删除链表某一位置的元素     *\n");
        printf("*      4.打印链表                   *\n");
        printf("*      5.退出                       *\n");
        printf("*                                   *\n");
        printf("*************************************\n");
        printf("您的操作是: ");
        scanf("%d", &choose);
        system("cls");
        switch (choose)
        {
        case 1:
        {
            printf("请输入数组的个数：");
            scanf("%d", &n);
            ElemType Num[n];
            printf("请依次输入您需要输入的数据，以空格分隔：\n");
            for (i = 0; i < n; ++i)
                scanf("%d", &Num[i]);
            CreatListR(L, Num, n);
            break;
        }
        case 2:
        {
            printf("请输入您要插入在第几个元素之前：");
            scanf("%d", &n);
            ElemType e;
            printf("请输入您要插入的元素是：");
            scanf("%d", &e);
            ListInsert(L, n, e);
            break;
        }
        case 3:
        {
            printf("请输入您要删除第几个元素：");
            scanf("%d", &n);
            ElemType e_0;
            ListDelete(L, n, e_0);
            break;
        }
        case 4:
        {
            DispList(L);
            break;
        }
        case 5:
        {
            exit(0);
            break;
        }
        }
    }
    return 0;
}
