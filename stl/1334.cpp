#include<iostream>
#include<ext/algorithm>
#include<iterator>
#include<assert.h>
using namespace::std;

int main(){
	int a[]={1,4,2,8,5,7};
	const int n=sizeof(a)/sizeof(int);
	assert(!__gnu_cxx::is_heap(a,a+n));
	make_heap(a,a+n);
	copy(a,a+n,ostream_iterator<int>(cout," "));
	cout<<endl;
	
	sort_heap(a,a+n);
	copy(a,a+n,ostream_iterator<int>(cout," "));
	cout<<endl;

}
