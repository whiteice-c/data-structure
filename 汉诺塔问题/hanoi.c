#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**********文件说明：汉诺塔问题 
***********作者：baibing
***********时间：2018.3.14	*********/

/*递归的个人理解使用：使用递归是为了能更容易的解决实际问题，他总是可以把一个
大问题分解成无数个可以用相同解决办法解决的小问题，从个人角度以这样的思想去理解
递归感觉很难在实际中运用得当。所以，目前觉得可以采取数学归纳法的思想，将复杂
问题用类似数学表达式的方式表达出来，满足以下条件：1、有终止条件 2、对于问题
对应n的范围内可以用相同的表达式表达。就可以采用递归算法*/
void hanoi(int n,char a,char b,char c)
{
	if(n == 1)
		printf("%c -> %c\n",a,c);
	else
	{
		hanoi(n-1,a,c,b);
		printf("%c -> %c\n",a,c);
		hanoi(n-1,b,a,c);
	}
}

int main()
{
	char a='A',b='B',c='C';
	int n =5;
	hanoi(n,a,b,c);
}
