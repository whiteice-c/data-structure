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
	temp->next = NULL;/*注意这里一定要使指向下一个结点的指针为NULL，防止指针地址”失控“*/ 
	
	/*空队列时，入队元素唯一，既是头结点又是尾结点*/
	if(is_empty_queue(q))
	{
		q->front = temp;
		q->rear = temp;	
	}
	else
	{
		q->rear->next = temp;
		q->rear = temp;		
	}
}

/*4、出队:删除头结点，使下一个结点成为新的头结点*/
int dequeue(LinkQueue *q)
{
	LinkNode *temp = NULL;
	int value;
	temp = (LinkNode *)malloc(sizeof(LinkNode));
	
	if(is_empty_queue(q))
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
	LinkNode *temp = NULL;
	temp = (LinkNode *)malloc(sizeof(LinkNode));
	
	if(is_empty_queue(q))
		return;
	
	temp = q->front;	
	printf("\n当前队列内容：\n");

	while(temp != NULL)
	{
		printf("%d\n",temp->data);
		temp = temp->next;	
	}
	
	printf("\n");
}

int main()
{
	int i = 0;
	int temp;
	LinkQueue *q;
	
	q = create_empty_linkqueue();

	enqueue(q,1);
	printf_LinkQueue(q);;
	temp = dequeue(q);
	printf("%d\n",temp);
	
	enqueue(q,2);
	printf_LinkQueue(q);
	
	temp = dequeue(q);
	printf("%d\n",temp);

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
}
