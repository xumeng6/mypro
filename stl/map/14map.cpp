#include<map>
#include<iostream>
using namespace::std;
template<class T>
void print(T b,T e)
{
	while(b!=e)
		cout<<*b++<<' ';
	cout<<endl;
}
template<class K,class V>
ostream& operator<<(ostream& o,const pair<K,V> p)
{
	return o<<p.first<<':'<<p.second;
}
int main()
{
	map<int, string> mis;
	mis.insert(map<int,string>::value_type(5,"zhongyulong"));
	mis.insert(pair<int ,string>(8,"wanglong"));
	mis.insert(make_pair(4,"lilin"));
	mis[3]="hejunjun";
	mis[6]="pusiliang";
	mis.insert(make_pair(5,"zhongyulong"));
	mis.insert(make_pair(5,"furong"));
	print(mis.begin(),mis.end());
	mis[6]="pisong";
	print(mis.begin(),mis.end());
	return 0;
}
