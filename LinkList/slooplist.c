#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/**********文件说明：单向循环链表的基本操作 
***********作者：baibing
***********时间：2018.2.23	*********/ 

/*1、建立基本结构体：
	包括数据和指向下一个结点的指针*/ 
/*基本结构体*/
typedef struct node
{
	int data;
	struct node *next;
}LinkNode;

/*2、建立空链表头和尾
	建立头结点，指针域指向自己，此时没有数据*/
LinkNode *create_LinkNode()
{
	LinkNode *head = NULL;
	
	head = (LinkNode*)malloc(sizeof(LinkNode));
	
	if(head == NULL)
	{
		printf("malloc failed!\n");
		return;
	}
	head->next = head;/*与单链表不同处*/
	
	return head;
}

/*3、头插法：每次插入数据都在头结点和头结点后的第一个结点
	之间插入数据，也就是让头结点的指针域指向新插入的结点，
	新插入的结点指针域指向头结点原来指向的结点，并让尾结点
	指向头结点，此时，新插入的结点变为头结点之后的第一个结点*/ 
void insert_to_head_data(LinkNode *head,int data)
{
	LinkNode *temp = NULL;
	
	temp = (LinkNode*)malloc(sizeof(LinkNode));
	if(temp == NULL)
	{
		printf("malloc failed!\n");
		return;	
	}
	
	temp->data = data;
	temp->next = head->next;
	head->next = temp;
}

/*4、打印链表数据：遍历每个结点并输出他们的数据域*/
void printf_LinkList(LinkNode *head)
{
	LinkNode *temp = NULL;
	
	if(head == NULL || head->next == head)
	{
		printf("LinkList is NULL!\n\n");	
	}
	
	temp = (LinkNode*)malloc(sizeof(LinkNode));
	temp = head->next;
	while(temp != head)/*与单链表不同处*/
	{
		printf("%d\n",temp->data);
	//	printf("%d\n\n",temp->next);	
		temp = temp->next;
	}
	
	printf("\n\n");
}

/*5、尾插法：首先找到链表的最后一个结点，然后让
	最后一个结点的指针域指向新插入的结点，从而新结点指向head*/ 
void insert_to_trail(LinkNode *head,int data)
{
	LinkNode *temp = NULL;
	LinkNode *temp1 = NULL;
	
	temp = (LinkNode*)malloc(sizeof(LinkNode));
	temp1 = (LinkNode*)malloc(sizeof(LinkNode));
	if((temp == NULL)||(temp1 == NULL))
	{
		printf("malloc failed!\n");
		return;	
	}
	temp1 = head;
	
	while(temp1->next != head)/*与单链表不同处*/
	{
		temp1 = temp1->next;	
	}
	
	temp1->next = temp;
	temp->data = data;
	temp->next = head;/*与单链表不同处*/
}

/*6、有序插入数据：将待插入的数据与链表当前非空结点进行比较，当该数据比结点数据
	小时，就插入当前结点之前*/
void insert_order_LinkList(LinkNode *head,int data)
{
	LinkNode *temp;
	LinkNode *Cur;
	LinkNode *Pre;

	Cur = (LinkNode*)malloc(sizeof(LinkNode));
	Pre = (LinkNode*)malloc(sizeof(LinkNode));/*加入前继结点是为了方便有序加入头结点和第一个结点之间*/
	temp = (LinkNode*)malloc(sizeof(LinkNode));
	temp->data = data;
	Pre = head;
	Cur = Pre->next;
	
	while((Cur != head)&&(temp->data > Cur->data))/*与单链表不同处*/
	{
		Pre = Pre->next;
		Cur = Cur->next;
	}
	
	temp->next = Cur;
	Pre->next = temp;
	printf_LinkList(head);
}

/*7、删除一个数据: 将想要删除的数据与链表中的结点进行比较，如果数据相同，则删除
	该结点的数据（也就是让该结点的前一个结点指向该结点的后一个结点）。如果数据
	比较不同，则结点后移继续比较，直到链表尾部
	注意：要将删除后的结点释放，防止内存泄露*/
void delete_data_LinkList(LinkNode *head,int data)
{
	LinkNode *front;
	LinkNode *rear;
	
	front = (LinkNode*)malloc(sizeof(LinkNode));
	front = head;
	rear = (LinkNode*)malloc(sizeof(LinkNode));
	rear = head->next;
	
	if(head->next == head)/*与单链表不同处*/
	{
		return;	
	}
	
	while(front->next != head)/*与单链表不同处*/
	{
		if(rear->data != data)
		{
			front = front->next;
			rear = rear->next;	
		}
		else
		{
			front->next = rear->next;
			free(rear);
			break;
		}		
	}
	
	printf_LinkList(head);
}

/*8、删除链表相同的数据：循环遍历当前结点与链表中其他结点的数据是否
	相同，如果相同，则删除两者靠前的结点。继续遍历后续当前结点，直到
	结点遍历完毕。*/
void delete_same_LinkList(LinkNode *head)
{
	LinkNode *front;
	LinkNode *rear;
	LinkNode *temp;
	
	
	front = (LinkNode*)malloc(sizeof(LinkNode));
	front = head->next;
	rear = (LinkNode*)malloc(sizeof(LinkNode));
	rear = front->next;
	temp = (LinkNode*)malloc(sizeof(LinkNode));
	temp = head;
	
	while((rear != head)||(front !=head))/*与单链表不同处*/
	{
		if(front->data == rear->data)
		{
			temp->next = front->next;/*删除当前结点而不是靠后的一个，防止找到相同结点并删除靠后的，然后继续只
										遍历之后的导致后面依旧有相同的结点，但无法判断出来*/
			front = front->next;
			rear = front->next;/*继续向后遍历比较*/
			if(rear == head)/*与单链表不同处*/
				return;
		}
		else
		{
			rear = rear->next;/*如果不同，拿下一个结点与当前结点比较*/
			if(rear == head)/*与单链表不同处*/
			{
				temp = front;/*遍历后没有相同结点，则(后移)换一个当前结点，继续循环遍历比较*/
				front = front->next;
				if(front == head)
					return;
				rear = front->next;	
				if(rear == head)
					return;	/*表示已遍历完最后一个结点并没有相同数据
							如果不结束则会在if判断出错，相当于
							if(data == (void)*)*/
			}	
		}
	}
}

/*9、清空链表中的数据：保留头结点，将其后的所有节点删除释放*/
void clear_LinkList(LinkNode *head)
{
	LinkNode *temp;
	LinkNode *temp1;
	
	if(head == NULL)
		return;
		
	temp = head->next;
	while(temp != head)
	{
		temp1 = temp->next;
		free(temp);
		temp = temp1;		
	}
	
	head->next = head;/*与单链表不同处*/
	printf_LinkList(head);
}


/*10、头插法逆置链表：新建逆置链表为空，原结点依次从链表中删除，再逐个插入逆置链表的
	表头(头插法)，使他成为逆置链表*/
void head_converse_LinkList(LinkNode *head)
{	
	LinkNode *Temp = NULL;
	LinkNode *New_P = NULL;
	
	Temp = (LinkNode*)malloc(sizeof(LinkNode));
	Temp = head->next;
	head->next = head;
	New_P = (LinkNode*)malloc(sizeof(LinkNode));
	
	while(Temp != head)/*与单链表不同处*/
	{
		New_P = Temp;
		Temp = Temp->next;
		
		New_P->next = head->next;
		head->next = New_P;	
	}
	
	printf_LinkList(head);
}

LinkNode* rec_converse_LinkList(LinkNode *head,LinkNode *s_head)
{	
	/*递归终止条件：链表为空或已是链表的最后一个结点
		递归终止操作：将最后一个结点作为新的头结点，“归”时插入
		新的头结点，实现逆序。*/
	LinkNode *New_Head;
	
	New_Head = (LinkNode*)malloc(sizeof(LinkNode));
	
	if(head->next == s_head)
		return head;
		
	New_Head = rec_converse_LinkList(head->next,s_head);/*递归*/ 
	
	/*回溯*/
	head->next->next = head;
	head->next = s_head;/*与单链表不同处*/
    
    return New_Head;
}

/*11、递归法逆置单链表：首先将当前单链表头结点分离出来，利用递归函数先找出剩余链表的最后
	一个结点并返回作为新的头结点，并将剩余链表逆序；最后，将之前分离的头结点插入新头结点
	之前，形成逆置新链表*/
void rec_converse(LinkNode *head)
{
	LinkNode *s_head; 
	s_head = (LinkNode*)malloc(sizeof(LinkNode));
	
	s_head = head;	/*保存原始头结点*/
	head = head->next;
	
	head = rec_converse_LinkList(head,s_head);
	s_head->next = head; /*将头插入完成逆序的链表*/ 
	printf_LinkList(s_head);	
}

/*12、获取链表长度*/
int GetListLength(LinkNode *head)
{
	int num = 0;
	LinkNode *temp;
	temp = (LinkNode*)malloc(sizeof(LinkNode));
	
	temp = head->next;
	while(temp != head)/*与单链表不同处*/
	{
		temp = temp->next;
		num++;
	}
	
	return num;/*不包括头结点*/
} 

/*13、链表排序：采用冒泡排序方法*/ 
void sort_linklist(LinkNode *head)
{
	int num=0,i=0,j=0;
	int temp_data;
	LinkNode *Front;
	LinkNode *Rear;
	LinkNode *s_head;
	
	Front = (LinkNode*)malloc(sizeof(LinkNode));
	Rear = (LinkNode*)malloc(sizeof(LinkNode));
	s_head = (LinkNode*)malloc(sizeof(LinkNode));
	
	s_head = head;/*保存头结点*/
	num = GetListLength(head);
	
	for(i=0;i<num-1;i++)
	{
		Front = s_head->next;
		Rear = Front->next;	
		
		for(j=0;j<num-i-1;j++)
		{
			if(Front->data > Rear->data)
			{
				temp_data = Rear->data;
				Rear->data = Front->data;
				Front->data = temp_data;	
			}	
			Rear = Rear->next;
			Front = Front->next;
		}	
	}
	
	printf("Sort Test:\n");
	printf_LinkList(head);
}

 
int main()
{
	LinkNode *head;
	int i;
	
	head = create_LinkNode();
	for(i=1;i<6;i++)
	{
		insert_to_head_data(head,i);		
	}
	printf_LinkList(head);

	for(i=6;i<11;i++)
	{
		insert_to_trail(head,i);		
	}
	printf_LinkList(head);

	insert_to_trail(head,7);
	insert_order_LinkList(head,7);
	delete_data_LinkList(head,6); 
	delete_same_LinkList(head);
	printf_LinkList(head);
	head_converse_LinkList(head);
	rec_converse(head);
	sort_linklist(head);
	clear_LinkList(head);
	
	return 0;
}

