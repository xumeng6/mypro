#include<stdio.h>
#include<unistd.h>
main()
{
	int *p=sbrk(4);
	*p=8888;
	printf("%d\n",*p);
}

