#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**********文件说明：堆栈的基本操作 
***********作者：baibing
***********时间：2017.12.13	*********/

#define Max 3

typedef struct
{
	int buf[Max];
	int top;
}stack_t;

/*1、创建空队列*/
stack_t *create_empty_stack()
{
	stack_t *q;
	q = (stack_t *)malloc(sizeof(stack_t));
	
	q->top = -1;
	return q;
}

/*2、判断队列是否为空*/
int is_empty_stack(stack_t *q)
{
	return q->top == -1;
} 

/*3、判断队列是否满了:数组只有一个存储空间时为满*/
int is_full_stack(stack_t *q)
{
	return q->top == Max-1;/*注意数组越界*/
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
