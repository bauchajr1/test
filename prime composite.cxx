#include <stdio.h>
#include <conio.h>
int main()
{
	int num, i, count=0,limit;
	printf("Enter limit number: ");
	scanf("%d", &limit);
	num=2;
	while(num<limit){
	for (i = 1; i <= num; i++)
	{
		if (num % i ==0)
		{
			count++;
		}
		
	}
	if (count ==2){
	printf("%d\n",num);
	}
	num++;
	count=0;
	}
	return 0;
	getch();
}
