#include<iostream>
using namespace::std;
template<int n>
class Fact{
public:
	int val=Fact<n-1>::val*n;
};
template<>
class Fact<0>{
public:
	int val=1;
};
int main()
{
	cout<<Fact<5>::val<<endl;
	return 0;
}
