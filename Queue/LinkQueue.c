#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**********文件说明：链式队列的基本操作 
***********作者：baibing
***********时间：2017.12.13	*********/

#define Max 3

/*基本结构体*/
typedef struct node
{
	int data;
	struct node *next;
}LinkNode;

typedef struct 
{
	LinkNode *front;
	LinkNode *rear;
}LinkQueue;

/*1、创建空队列*/
LinkQueue* create_empty_linkqueue()
{
	LinkQueue *q = NULL;
	q = (LinkQueue *)malloc(sizeof(LinkQueue));
	q->front = (LinkNode *)malloc(sizeof(LinkNode));
	q->rear = (LinkNode *)malloc(sizeof(LinkNode));
	
	q->front = q->rear = NULL;
	return q;
}

/*2、判断队列是否为空*/
int is_empty_queue(LinkQueue *q)
{
	return q->front == NULL;
}  

/*3、入队*/
void enqueue(LinkQueue *q,int data)
{		
	LinkNode *temp = NULL;
	temp = (LinkNode *)malloc(sizeof(LinkNode));
	
	temp->data = data;
	if(is_empty_queue(q))
	{
		q->front = temp;/*第一次将数据给队头*/
		q->rear = temp;	
	}
	else
	{
		q->rear->next = temp;
		q->rear = q->rear->next;
	}
}

/*4、出队:删除头结点，使下一个结点成为新的头结点*/
int dequeue(LinkQueue *q)
{
	LinkNode *temp = NULL;
	int value;
	temp = (LinkNode *)malloc(sizeof(LinkNode));
	
	if(q->front == NULL)
		return;
		
	temp = q->front;
	value = temp->data;	
		
	q->front = q->front->next;
	free(temp);
	
	return value;
}

/*5、打印队列*/
void printf_LinkQueue(LinkQueue *q)
{
	printf("\n当前队列内容：\n");
	LinkNode *temp = NULL;
	temp = (LinkNode *)malloc(sizeof(LinkNode));
	
	temp = q->front;
	while(temp != q->rear)
	{
		printf("%d\n",temp->data);
		temp = temp->next;	
	}
	printf("%d\n",temp->data);/*q->rear也有值*/
	printf("\n");
}

int main()
{
	int i = 0;
	int temp;
	LinkQueue *q;
	
	q = create_empty_linkqueue();

	for(i=0;i<5;i++)
	{
		enqueue(q,i);
	} 
	printf_LinkQueue(q);
	
	for(i=0;i<3;i++)
	{
		temp = dequeue(q);
		printf("%d\n",temp);
	}
	temp = dequeue(q);
	printf("%d\n",temp);
	printf_LinkQueue(q);
	for(i=0;i<5;i++)
	{
		enqueue(q,i);
	} 
	printf_LinkQueue(q);
	for(i=0;i<3;i++)
	{
		temp = dequeue(q);
		printf("%d\n",temp);
	}
	printf_LinkQueue(q);
}
