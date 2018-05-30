#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**********函数说明：顺序表的建立、插入和排序
***********作者：baibing
***********时间：2017.12.13	*********/

#define Max 20

typedef struct
{
	int data[Max];
	int n; 
}Seqlist;

/*创建顺序表*/
Seqlist *Create_Seqlist()
{
	Seqlist *l = NULL;
	
	l = (Seqlist *)malloc(sizeof(Seqlist));
	if(l == NULL)
	{
		printf("malloc Error!\n");	
		return NULL;
	}
	
	memset(l,0,sizeof(Seqlist));/*此处不初始化程序会跑飞，理解为要对指针完全的初始化*/
	
	return l;
}

/*判断顺序表是否满了*/
int is_full_Seqlist(Seqlist *l)
{
	return l->n == Max ? 1:0;
}

/*初始化，建立一个顺序表，逐个插入即可*/
void insert_data_Seqlist(Seqlist *l,int *a,int length)
{
	int i;
	
	for(i = 0;i<length;i++)
	{
		if((is_full_Seqlist(l))!= 1)
		{
			l->data[i] = a[i];
			l->n ++;/*数据数目增加*/
		}		
		else
		{
			printf("line is full!\n");
			return;	
		}
	}
}

/*将数据插入到指定位置*/
void insert_dataToPos_Seqlist(Seqlist *l,int data,int pos)
{
	int i;
	
	if((is_full_Seqlist(l))!= 1)
	{
		for(i = (Max-2);i>-1;i--)
		{
			if(pos == i)
			{
				l->data[i+1] = l->data[i];
				l->data[i] = data;
				l->n++;/*数据数目增加*/
				return;
			}
			else
			{
				l->data[i+1] = l->data[i];	
			}
		}
	}
}

/*删除指定位置的数据*/
void delete_PosData_Seqlist(Seqlist *l,int pos)
{
	int i,j;
	
	for(i=0;i<Max;i++)
	{
		if(i == (pos+1))
		{
			for(j=pos;j<Max;j++)
			{
				l->data[j] = l->data[i++];	
			}
			l->n --;
			return;
		}
	}
}

/*删除数据*/
void delete_data_Seqlist(Seqlist *l,int data)
{
	int i=0,j=0;
	
	for(i=0;i<Max;i++)
	{
		if(l->data[i] != data)
		{
			l->data[j] = l->data[i];
			j++;
		}	
		else
		{
			l->n --;	
		}
	}
}

/*排序*/
void sort_Seqlist(Seqlist *l )
{
	int i,j;
	int temp;
	
	for(i=0;i<l->n;i++)
	{
		for(j=0;j<l->n;j++)
		{
			if(l->data[i]<l->data[j])
			{
				temp = l->data[i];
				l->data[i] = l->data[j];
				l->data[j] = temp;
			}	
		}	
	}
}

/*打印数据*/
void print_Seqlist(Seqlist *l)
{
	char i;
	
	for(i=0;i<l->n;i++)
	{
		printf("%d",l->data[i]);	
		putchar('\n');
	}
	
	printf("complete!\n\n");
}

int main()
{
	Seqlist *l = NULL;
	int Data[6] = {11,33,22,55,55,44};
	
	l = Create_Seqlist();
	insert_data_Seqlist(l,Data,sizeof(Data)/sizeof(int));
	print_Seqlist(l);
	sort_Seqlist(l);
	print_Seqlist(l);
	
	insert_dataToPos_Seqlist(l,31,3);
	printf("添加一个元素\n");
	print_Seqlist(l);
	sort_Seqlist(l);
	printf("重排序\n");
	print_Seqlist(l);
	delete_PosData_Seqlist(l,3);
	printf("删除指定位置数据\n"); 
	print_Seqlist(l);
	delete_data_Seqlist(l,55);
	printf("删除数据\n"); 
	print_Seqlist(l);
	
	return 0;
}
