#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**********文件说明：链式栈的基本操作 
***********作者：baibing
***********时间：2017.12.13	*********/

#define Max 3
/*1、建立基本结构体：
	包括数据和指向下一个结点的指针*/ 
/*基本结构体*/
typedef struct node
{
	int data;
	struct node *next;
}LinkNode

typedef struct
{
	int m;/*表示栈中有效元素的个数*/
	LinkNode *top;/*保存栈中第一个有效结点的地址*/ 
}LinkStack;

/*1、创建空链式栈*/
LinkStack *create_empty_linkstack()
{
	LinkStack *s;
	s = (LinkStack *)malloc(sizeof(LinkStack));
	
	s->n = 0;
	s->top = NULL;
	return s;
}

/*2、判断链式栈是否为空*/
int is_empty_linkstack()
{
	return s->top == NULL; 
}

/*3、入栈，类似于链表的头插法*/
void push_data_linkstack(LinkStack *s,int data)
{
	LinkNode *temp;
	temp = (LinkNode *)malloc(sizeof(LinkNode));
	
	temp->data = data;
	temp->next = NULL;
	s->top->next = temp;
	s->n++;
}

/*4、出栈*/ 
DataType pop_data_linkstack(LinkStack *s)
{
	s->top = s->top->next->next;
	s->n--;
}

/*5、获得栈顶元素的值*/
DataType get_top_linkstack(LinkStack *s)
{
	
}
/*4、入栈*/
void push_stack(stack_t *q,int value)
{
	q->top += 1; 
	q->buf[q->top] = value;
	printf("%d",q->buf[q->top]);
}

/*5、出队*/
int pop_stack(stack_t *q)
{
	int temp;
		
	temp = q->buf[q->top];
	printf("%d",q->buf[q->top]);
	q->top -= 1;
	
	return temp;
}

int main()
{
	static int i = 7;
	int j = 2;
	stack_t *q;
	
	q = create_empty_stack();
	
	while(j--)
	{
		while(!is_full_stack(q))
		{
			push_stack(q,i);
			i++;	
		}	
		while(!is_empty_stack(q))
		{
			pop_stack(q);	
		}
		putchar('\n');
	}
}
