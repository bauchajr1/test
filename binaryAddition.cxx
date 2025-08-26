#include<stdio.h>
#include<math.h>
int main(int argc, char *argv[])
{
	int a,i,c=0,binN[100],deciN=0;
	scanf("%d",&a);
	for(i=a;i!=0;i/=10){
	    c++;
	}
	for(i=c-1;i>=0;i--){
	    binN[i]=a%10;
	    a/=10;
	}
	for(i=0;i<c;i++){
	    deciN=deciN+(binN[i]*pow(2,c-(i+1)));
	}
	printf("%d",deciN);
	return 0;
}