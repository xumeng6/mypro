#include<iostream>
using namespace::std;
#include <stdio.h>
inline bool isnumber(char ch)
{
	return ((ch>='0')&&(ch<='9'));
}
int main (int argc, char *argv[] )
{
	char c;
	while((c= cin.get())!='q')
	{
		if(isnumber(c)){
			cout<<"you enter a digit"<<endl;}
		else{
			cout<<"you enter a non-dight"<<endl;}
}
	return 0;
}
