#include<stdio.h>

int main()
{
	__int64 i,j,sum=0,a,b,c;

	a=0;
	b=1;

	while(1)
	{
		c=a+b;
		if(c>4000000)
			break;

		if(c%2==0)
			sum+=c;
		a=b;
		b=c;
	}
	printf("%I64d\n",sum);

	return 0;
}