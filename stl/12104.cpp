#include<iostream>
#include<iterator>
#include<ext/numeric>
#include<algorithm>
using namespace::std;
int main(){
	int a[]={1,4,9,16,25,36,49,64,81,100};
	const int n=sizeof(a)/sizeof(int);
	int b[n];
	cout<<"a ";
	copy(a,a+n,ostream_iterator<int>(cout," "));
	cout<<endl;
	adjacent_difference(a,a+n,b);
	cout<<"difference: ";
	copy(b,b+n,ostream_iterator<int>(cout," "));
	cout<<endl;
	cout<<"reconstruct: ";
	partial_sum(b,b+n,ostream_iterator<int>(cout," "));
	cout<<endl;

}
