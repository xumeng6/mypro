#include<stdio.h>
int main(){
	int b=1;
	int* a;
	*a=b;
	printf("%d,%d",*a,b);
	return 0;
}
