#include<iostream>
#include"mystring.h"
using namespace std;
int main(int argc,char* argv[]){
	mystring s1("first");
	mystring s2(s1);
	s2.showstring();
	mystring s3("second");
	mystring s4;
	s4.Copy(s1);
	s4.showstring();
	s4.Getlength();
	s4.Add(s3);	
	s4.showstring();
	return 0;
}
