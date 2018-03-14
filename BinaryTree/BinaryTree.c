#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/**********文件说明：二叉树的基本操作 
***********作者：baibing
***********时间：2017.3.5	*********/ 

/*1、建立基本结构体：
	包括存储的数据和指向左右孩子的指针。建立队列用来二叉树的层次遍历*/ 
typedef struct bnode
{
	char data;
	struct bnode *L_Child;
	struct bnode *R_Child;
}BTree_T;

typedef struct node
{
	struct bnode *t_data;
	struct node *next; 
}LinkNode;

typedef struct qnode
{
	LinkNode *front;
	LinkNode *rear;
}LinkQueue;

/*2、分配空间:给新建立的数结点分配空间*/
BTree_T* malloc_btree(BTree_T *root,char data)
{
	root = (BTree_T *)malloc(sizeof(BTree_T));
	
	if(root == NULL)
	{
		printf("malloc failed!\n");
		return;	
	}
	
	root->L_Child = NULL;
	root->R_Child = NULL;
	root->data = data;
	
	return root; 
} 

/*3、建立完全二叉树：采用递归的方法，建立根节点,然后建立左右孩子
	参数说明：a[]:树结点数据  num:当前数结点编号  n：树结点总数(2^z-1)
	所有左孩子结点满足：2*num <= n，右孩子结点满足：2*num+1<=n*/
BTree_T *create_full_binary_tree(char a[],int num,int n)
{
	BTree_T *root;
	
	root = malloc_btree(root,a[num]);
	
	if(2*num <= n)
	{
		root->L_Child = (BTree_T*)create_full_binary_tree(a,2*num,n);
	}
	
	if(2*num+1 <= n)
	{
		root->R_Child = (BTree_T*)create_full_binary_tree(a,2*num+1,n);
	}
	
	return root;
}

/*4、先序遍历二叉树,用递归按根左右的顺序依次遍历二叉树*/
void preorder_traversal(BTree_T *root)
{
	if(root == NULL)
		return;
	
	printf("%c",root->data);
	preorder_traversal(root->L_Child);
	preorder_traversal(root->R_Child);
}

/*5、中序遍历二叉树,用递归按左根右的顺序依次遍历二叉树*/
void inorder_traversal(BTree_T *root)
{
	if(root == NULL)
		return;
	
	inorder_traversal(root->L_Child);
	printf("%c",root->data);
	inorder_traversal(root->R_Child);
}

/*6、后序遍历二叉树,用递归按左右根的顺序依次遍历二叉树*/
void postorder_traversal(BTree_T *root)
{
	if(root == NULL)
		return;
	
	postorder_traversal(root->L_Child);
	postorder_traversal(root->R_Child);
	printf("%c",root->data);
}

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
void enqueue(LinkQueue *q,BTree_T *t)
{		
	LinkNode *temp = NULL;
	
	temp = (LinkNode *)malloc(sizeof(LinkNode));
	temp->t_data = (BTree_T *)malloc(sizeof(BTree_T));
	
	temp->t_data = t;
	temp->next = NULL;/*注意这里一定要下一个结点指向NULL，不然会导致队列
					指针指向野地址，造成入队出队混乱，指针跑飞等结果*/
	
	if(is_empty_queue(q))
	{
		q->front = temp;/*第一次将数据给队头*/
		q->rear = temp;
	}
	else
	{
		q->rear->next = temp;
		q->rear = temp;
	}
}

/*4、出队:删除头结点，使下一个结点成为新的头结点*/
BTree_T * dequeue(LinkQueue *q)
{
	LinkNode *temp = NULL;
	BTree_T *t = NULL;
	
	temp = (LinkNode *)malloc(sizeof(LinkNode));
	temp->t_data = (BTree_T *)malloc(sizeof(BTree_T));
	t = (BTree_T *)malloc(sizeof(BTree_T));
	
	if(q->front == NULL)
		return;
		
	temp = q->front;
	t = temp->t_data;	
		
	q->front = q->front->next;
	free(temp);
	
	return t;
}

/*7、层次遍历二叉树:首先使根结点入队，然后循环判断队列是否为空，不为空，
	则开始出队，并获取出队元素指向的结点，并入队他的左右孩子的元素，直到
	队列为空*/
void levelorder_traversal(BTree_T *root)
{ 	
	LinkQueue *q;
	BTree_T *t;
	t = (BTree_T *)malloc(sizeof(BTree_T));
	t = root;
	
	q = create_empty_linkqueue();
	enqueue(q,t);
	while(!is_empty_queue(q))
	{
		t = dequeue(q);
		printf("%c",t->data);
	
		if(t->L_Child)
			enqueue(q,t->L_Child);
		if(t->R_Child)
			enqueue(q,t->R_Child);
	}
}

/*8、按层次顺序建立普通二叉树：采用递归的方法，建立根节点,然后建立左右孩子
	参数说明：a[]:树结点数据  num:当前数结点编号  n：树结点总数(2^z-1)
	所有左孩子结点满足：2*num <= n，右孩子结点满足：2*num+1<=n*/
BTree_T *create_binary_tree(char a[],int num,int n)
{
	BTree_T *root;
	
	if(a[num] != ' ')
	{
		root = malloc_btree(root,a[num]);		
	}
	else
	{
		return NULL;
	}
	
	root->L_Child = (BTree_T*)create_full_binary_tree(a,2*num,n);

	root->R_Child = (BTree_T*)create_full_binary_tree(a,2*num+1,n);
	
	return root;
}

/*9、先序建立普通二叉树：采用递归的方法，建立根节点,然后建立左右孩子
	参数说明：a[]:树结点数据  num:当前数结点编号  n：树结点总数(2^z-1)
	所有左孩子结点满足：2*num <= n，右孩子结点满足：2*num+1<=n*/
void preorder_create_binary_tree(BTree_T *root,char a[],int num)
{
	char ch = a[num++];
		
	if(ch == ';')
	{
		return;	
	}
	
	if(ch !=' ')
	{
		root = (BTree_T*)malloc(sizeof(BTree_T));
		root->data = ch;
		preorder_create_binary_tree(root->L_Child,a,num);
		preorder_create_binary_tree(root->R_Child,a,num);	
	}
	else
	{
		root = NULL;
		num++;
	}
}

int main()
{
	char a[] = {-1,'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O'};
	char a1[] = {-1,'A','B','D',' ','C','E','F'};
	char a2[] = {-1,'A','B',' ','C',' ',' ','D','E',' ',' ','F',' ',' ',';'};
	int num = 1;/*二叉树结点一般从1开始计数*/
	BTree_T *root;
	
	//root = create_full_binary_tree(a,num,sizeof(a)/sizeof(a[0])-1);
	root = create_binary_tree(a1,num,sizeof(a1)/sizeof(a1[0])-1);
	//preorder_create_binary_tree(root,a2,num);
	
	preorder_traversal(root);
	printf("\n\n");
	inorder_traversal(root);
	printf("\n\n");
	postorder_traversal(root);
	printf("\n\n");
	levelorder_traversal(root);
	printf("\n\n");

	return 0;
}
