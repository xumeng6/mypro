#include<iostream>
using namespace::std;

int main(int argc,char * argv[] )
{
	int intOne = 0;
	int& r_int_one = intOne;
	intOne = 5;
	cout<<intOne<<endl;
	cout<<r_int_one<<endl;
	
	r_int_one = 7;
	cout<< intOne<<endl;
	cout<< r_int_one<<endl;	
	cout<<&(intOne)<<endl;
	cout<<&(r_int_one)<<endl;
}

