#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/**********文件说明：八大排序算法 
***********作者：baibing
***********时间：2018.1.29	*********/ 
void printf_array(int *arr,int num);

/*1、直接插入排序：假设有R0，R1，R2，R3，R4五个未排序数组 
	（1）将数组第一个数R0当做有序序列，剩余部分为非有序序列
	（2）依次选取未排序数组，从后向前遍历，直到插入到有序序列合适的位置*
	时间复杂度：O(N^2)	空间复杂度：O(1)*/
void insert_sort(int *array,int num)
{
	int i,j;
    int temp;
    
	for(i=1;i<num;i++)
	{
		temp = array[i];
		for(j=i;j>0 && array[j-1]>temp;j--) 
		{
			array[j] = array[j-1];
		}		
		array[j] = temp;
	}
	
	printf_array(array,num);	
}

/*2、选择排序：首先在未排序的序列里找到最大或最小的数据，将其放在起始位；
	然后继续查找剩余部分最大或最小的数据，一次加入起始位之后
	时间复杂度：O(N^2)		空间复杂度O(1)*/
void select_sort(int *array,int num)
{
	int i=0,j=0,k = 0;
	int temp=0;
		
	for(k=0;k<num;k++)
	{
		for(i=k;i<num;i++)
		{
			if(array[i]>temp)/*找到最大值并交换位置*/
			{
				temp = array[i];	
				array[i] = array[j];
				array[j] = temp; 
			}
		}		
		j+=1;
		temp = array[j];
	}
	
	printf_array(array,num);
}

/*3、冒泡排序：算法的名字由来是因为越小的元素会经由交换慢慢“浮”到数列的顶端。
	（1)首先相邻数据两两比较，如果前面比后面大，则交换两个数据，经过一轮循环，最后一个为最大的数据
	(2)重复上一步，保证让每一个数据都被比较过，直到没有任何一个数据需要再比较
	时间复杂度：O(N^2)		空间复杂度(1)*/ 
void bubble_sort(int *array,int num)
{
	int i=0,j=0;
	int temp;
	
	for(i=0;i<num-1;i++)
	{
		for(j=0;j<num-1-i;j++)
		{
			if(array[j]>array[j+1])
			{
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}		
		}	
	}
	
	printf_array(array,num);
}

/*4、归并排序：名字含义：先递归后合并
	(1)首先将待排序的数组通过递归的方法分解成两个有序数列
		递归终止条件：将待排序的序列分解成单个有序的子集 
	(2)然后将两个有序序列合并成一个有序序列，合并时，分别用两个指针指向两个有序序列的头，
	比较指针指向的元素大小，将较小的一方直接放到新的数组里，并删除原数组该元素，并向后移动
	指针，直到有一方没有元素，则直接把另一方剩下的数据直接插到合并数组的后面即可*/
void Merge_Sort(int *array,int *temp,int left,int mid,int right)
{
	int *new_array;
	
	
}	

void Merge_Array(int *array,int left,int *temp,int right)
{ 
	int mid;

	if(left<right)
	{
		mid = (left+right)/2;
		Merge_Array(array,left,temp,mid);/*左有序*/	
		Merge_Array(array,mid+1,temp,right);/*右有序*/
		Merge_Sort(array,temp,left,mid,right);/*合并*/
	}
}

/*打印数组*/
void printf_array(int *arr,int num)
{
	int i = 0;
	
	for(i = 0;i<num;i++)
	{
		printf("%d\n",arr[i]);	
	}
	printf("\n\n");
}

//将有二个有序数列a[first...mid]和a[mid...last]合并。
void mergearray(int a[], int first, int mid, int last, int temp[])
{
	int i = first, j = mid + 1;
	int m = mid,   n = last;
	int k = 0;
	
	while (i <= m && j <= n)
	{
		if (a[i] <= a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}
	
	while (i <= m)
		temp[k++] = a[i++];
	
	while (j <= n)
		temp[k++] = a[j++];
	
	for (i = 0; i < k; i++)
		a[first + i] = temp[i];
}
void mergesort(int a[], int first, int last, int temp[])
{
	if (first < last)
	{
		int mid = (first + last) / 2;
		mergesort(a, first, mid, temp);    //左边有序
		mergesort(a, mid + 1, last, temp); //右边有序
		mergearray(a, first, mid, last, temp); //再将二个有序数列合并
	}
}

int main()
{
	int num =0;
	int array[5] = {3,8,1,4,6};
	int *temp;
		
	temp = array;
	num = sizeof(array)/sizeof(int); 
	
	//insert_sort(array,num);
	//select_sort(array,num);
	//bubble_sort(array,num);
	//Merge_Array(array,0,temp,4);
	mergesort(array,0,4,temp);
	printf_array(array,num);
	
	return 0;
}
