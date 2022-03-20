/*Copyright © 2022 Shilohiy All rights reserved*/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>	  //实现线性表的头文件只需要这三个头文件
#define MaxSize 100	  //定义了元素的最大容量
typedef int ElemType; // typedef定义了ElemType为int类型
typedef struct
{ //定义一个data数组来存放我所需要的线性表
	ElemType data[MaxSize];
	int length; //存放线性表的长度
} SqList;
void InitList(SqList *L)
{
	L = (SqList *)malloc(sizeof(SqList));
	L->length = 0; //准备一个空表
	printf("一个空的线性表已准备就绪！请继续操作。\n");
}
//建立一个线性表，并把需要存放的值转存到线性表中，记录线性表的长度
void CreateList(SqList *L, ElemType Num[], int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		L->data[i] = Num[i]; //将元素Num[i]的值存入L中
	}
	L->length = n; //重新设定新的线性表长度（等于n，也等于i）
	printf("您需要的数据已完成录入！请继续操作。\n");
}
//插入数据元素
int ListInsert(SqList *L, int i, ElemType e)
{ // i为插入数据的位置
	int j;
	i--; //将输入的i转化为数组下标
	for (j = L->length; j > i; j--)
	{ //将data[i]后数字全部向后移一位，使得data[i]的位置空出来，以存放新数据e
		L->data[j] = L->data[j - 1];
	}
	L->data[i] = e; //存放数据e
	L->length++;	//线性表长度+1
	printf("您需要的数据已完成插入！请继续操作。\n");
	return 1;
}
/*问题，如果判定为合法i的前提下，但是超出了MaxSize，如何向系统申请新的空间？*/
//删除数据元素
int ListDelete(SqList *L, int i)
{ // i为需要删除数据的位置
	int j;
	i--; //将输入的i转化为数组下标
	for (j = i; j < L->length - 1; j++)
	{
		L->data[j] = L->data[j + 1]; //将data[i]后的数据以此向前移动一位，覆盖前面的数，以达到删除的目的
	}
	L->length--; //线性表长度-1
	printf("您不需要的数据已完成删除！请继续操作。\n");
}
//表的输出
void DispList(SqList *L)
{
	if (L->length == 0)
	{
		printf("是一个空表！无法打印！\n");
	}
	else
	{
		int i;
		for (i = 0; i < L->length; i++)
		{
			printf("%d ", L->data[i]);
		}
		printf("\n数据已完成打印！请继续操作。\n");
	}
}
int main()
{
	SqList *L;
	L = (SqList *)malloc(sizeof(SqList));
	int choose, Num[MaxSize]; //说明，choose选择数字，Num[MaxSize]存储数据元素
	int n, e, i;			  //说明，n多个元素，e操作数据元素，i操作数据元素数组顺序（下标+1）
	while (1)
	{
		printf("*************************************\n");
		printf("*                                   *\n");
		printf("*   线性表顺序存储运算的算法实现    *\n");
		printf("*                                   *\n");
		printf("*      1.建立一个表单并初始化       *\n");
		printf("*      2.输入您的表单               *\n");
		printf("*      3.在线性表某一位置插入元素   *\n");
		printf("*      4.删除线性表某一位置的元素   *\n");
		printf("*      5.打印线性表                 *\n");
		printf("*      6.退出                       *\n");
		printf("*                                   *\n");
		printf("*************************************\n");
		printf("您的操作是: ");
		scanf("%d", &choose);
		switch (choose)
		{
		case 1:
			InitList(L);
			break;
		case 2:
		{
			int flag = 0;
			while (flag == 0)
			{
				printf("请输入您想输入的线性表中数据元素个数(1~100):  ");
				scanf("%d", &n);
				if (n < 0 || n > MaxSize)
				{ //判断i的值是否合法
					printf("请输入一个合法数字！\n");
				}
				else
				{
					flag = 1;
					if (n != 0)
					{
						printf("请依次输入您需要输入的数据，以空格分隔：\n");
						for (i = 0; i < n; i++)
						{
							scanf("%d", &Num[i]);
						}
					}
				}
			}
			CreateList(L, Num, n);
			break;
		}
		case 3:
		{
			int flag = 0;
			while (flag == 0)
			{
				printf("请输入您希望插入在第几个元素之前？\n");
				scanf("%d", &i);
				if (i < 1 || i > L->length + 1)
				{ //判断i的值是否合法
					printf("请输入一个合法数字！\n");
				}
				else
				{
					flag = 1;
					printf("请输入您想插入元素的数据：\n");
					scanf("%d", &e);
				}
			}
			ListInsert(L, i, e);
			break;
		}
		case 4:
		{
			int flag = 0;
			while (flag == 0)
			{
				printf("请输入您希望删除第几个元素？\n");
				scanf("%d", &i);
				if (i < 1 || i > L->length)
				{ //判断i的值是否合法
					printf("请输入一个合法数字！\n");
				}
				else
				{
					flag = 1;
				}
			}
			ListDelete(L, i);
			break;
		}
		case 5:
		{
			DispList(L);
			break;
		}
		case 6:
		{
			printf("欢迎下次使用！\n");
			exit(0);
			break;
		}
		}
	}
	return 0;
}
