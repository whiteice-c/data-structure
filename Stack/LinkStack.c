#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**********文件说明：链式栈的基本操作 
***********作者：baibing
***********时间：2017.12.13	*********/

#define Max 3
/*1、建立基本结构体：
	包括栈结构体和结点*/ 
typedef struct node
{
	int data;
	struct node *next;
}LinkNode;

typedef struct
{
	int n;/*表示栈中有效元素的个数*/
	LinkNode *top;/*保存栈中第一个有效结点的地址*/ 
}LinkStack;

/*1、创建空链式栈*/
LinkStack *create_empty_linkstack()
{
	LinkStack *s = NULL;
	s = (LinkStack *)malloc(sizeof(LinkStack));
	s->top = (LinkNode *)malloc(sizeof(LinkNode));/*这里一定注意也要给结点分配空间
												造成产生野指针，是程序奔溃*/
	
	s->n = 0;
	s->top->next = NULL;
	return s;
}

/*2、判断链式栈是否为空*/
int is_empty_linkstack(LinkStack *s)
{
	return s->top->next == NULL; 
}

/*3、入栈，类似于链表的头插法，把栈顶当做链表头结点*/
void push_data_linkstack(LinkStack *s,int data)
{		
	LinkNode *temp = NULL;
	temp = (LinkNode *)malloc(sizeof(LinkNode));
	
	temp->data = data;
	temp->next = s->top->next;
	s->top->next = temp;
	s->n++;/*相当于栈顶位置的变化*/
}

/*4、出栈，类似于单链表删除结点的操作*/ 
LinkNode* pop_data_linkstack(LinkStack *s)
{
	LinkNode *temp = NULL;
	temp = (LinkNode *)malloc(sizeof(LinkNode));
	temp = s->top->next;
	
	if((s->top->next == NULL) || (s->top == NULL))
		return;
		
	s->top->next = s->top->next->next;
	s->n--;
	
	return temp;
}

/*5、获得栈顶元素的值*/
int get_top_linkstack(LinkStack *s)
{
	if(s->top->next == NULL)
		return;
	
	printf("\nstack->top = %d\n",s->top->next->data);
	return s->top->next->data;
}

/*6、打印链表数据：遍历每个结点并输出他们的数据域*/
void printf_LinkStack(LinkStack *s)
{
	LinkNode *temp = NULL;
	temp = (LinkNode *)malloc(sizeof(LinkNode));
	
	if((s->top->next == NULL) || (s->top == NULL))
		return;
		
	temp = s->top->next;
	while(temp != NULL)
	{
		printf("%d\n",temp->data);	
		temp = temp->next;
	}
	
	printf("\n\n");
}

int main()
{
	int i = 0;
	LinkStack *s = NULL;
	LinkNode *p = NULL;
	LinkNode *del = NULL;
	
	p = (LinkNode *)malloc(sizeof(LinkNode));
	del = (LinkNode *)malloc(sizeof(LinkNode));
	
	s = create_empty_linkstack();
	
	for(i = 0;i<5;i++)
	{
		push_data_linkstack(s,i);
	}
	printf_LinkStack(s);
	
	for(i=0;i<3;i++)
	{
		p = pop_data_linkstack(s);
		printf("%d\n",p->data);
		del = p;
		free(del);	
	}
	
	get_top_linkstack(s);
}
