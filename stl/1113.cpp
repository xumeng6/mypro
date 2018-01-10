#include<iostream>
#include<algorithm>
#include<ext/functional>
using namespace::std;
int main(){
	int a[]={1,2,3,5,4,6,7,8};
	const int N=sizeof(a)/sizeof(int);
	const int* p= adjacent_find(a,a+N,greater<int>());
	if(p==a+N)
		cout<<"the range is sorted"<<endl;
	else
		cout<<"element"<<p-a<<"is out of order:"<<*p<<" > "<<*(p+1)<<" ."<<endl;
}

