#include <stdio.h>
#include <conio.h>
int main()
{
	//variable declaration
	int num, i, count=0,limit;
	printf("Enter limit number: ");
	//user enters the limit 
	scanf("%d", &limit);
	num=2;
	//starting the loop until limit is reached
	while(num<limit){
	    /*
	    checking if tge number  is prime or not
	    -- with each contition being true 
	        count is increased
	        
	      ->since prime has only 2 factorials(i.e can be only divided by itself and 1) count will only be 2
	    */
	for (i = 1; i <= num; i++)
	{
		if (num % i ==0)
		{
			count++;
		}
		
	}
//printing the num if it is prime
	if (count ==2){
	printf("%d\n",num);
	}
	num++;
	count=0;
	}
	return 0;
	getch();
}
