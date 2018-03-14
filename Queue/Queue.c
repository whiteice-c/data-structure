#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**********文件说明：队列的基本操作 
***********作者：baibing
***********时间：2017.12.13	*********/

#define Max 5

typedef struct
{
	int buf[Max];
	int front;
	int rear;
}queue_t;

/*1、创建空队列*/
queue_t *create_empty_queue()
{
	queue_t *q;
	q = (queue_t *)malloc(sizeof(queue_t));
	
	q->front = q->rear = 0;
	return q;
}

/*2、判断队列是否为空*/
int is_empty_queue(queue_t *q)
{
	return q->front == q->rear;
} 

/*3、判断队列是否满了:数组只剩一个存储空间时为满*/
int is_full_queue(queue_t *q)
{
	return q->front == (q->rear+1)%Max;
} 

/*4、入队*/
void enqueue(queue_t *q,int data)
{		
	if(is_full_queue(q))
		return;
			
	q->buf[q->rear] = data;
	printf("%d",q->buf[q->rear]);
	q->rear = (q->rear+1)%Max;
}

/*5、出队*/
int dequeue(queue_t *q)
{
	int temp;
		
	if(is_empty_queue(q))
		return;
		
	temp = q->buf[q->front];
	printf("%d",q->buf[q->front]);
	q->front = (q->front+1)%Max;
	
	return temp;
}

/*6、判断当前队列元素个数*/
int element_count(queue_t *q)
{
	return (q->rear-q->front+Max)%Max;
}

int main()
{
	int i = 0;
	int j = 5;
	int count = 0;
	queue_t *q;
	
	q = create_empty_queue();
	
	while(j--)
	{
		while(!is_full_queue(q))
		{
			enqueue(q,i++);	
		}	
		while(!is_empty_queue(q))
		{
			dequeue(q);	
		}
		putchar('\n');
	}
	
	enqueue(q,5);
	enqueue(q,5);
	enqueue(q,5);
	enqueue(q,6);
	count = element_count(q);
	printf("\nelement num = %d\n",count);
}
