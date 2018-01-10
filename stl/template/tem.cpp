#include<iostream>
#include<string>
#include<algorithm>
using namespace::std;
class person{
private:
	int age;
	string name;
public:
	person(const string& nam,int ag):name(nam),age(ag){}
	friend ostream& operator<<(ostream&o,const person& p)
	{
		return o<<p.name<<':'<<p.age;
	}
	friend bool operator<(const person& a,const person& b)
	{
		return a.age<b.age;
	}
};
template<class T>
void print(T b, T e)
{
	while(b!=e)
		cout<<*b++<<'-'; 
	cout<<endl;
}
int main()
{
	int a[6]={8,1,44,3,24,56};
	person b[3]={person("aasd",21),person("asdaf",1),person("sada",54)};
	print(b,b+3);
	print(a,a+6);
	sort(a,a+6);
	sort(b,b+3);
	print(a,a+6);
	print(b,b+3);
}
