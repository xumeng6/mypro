#include<map>
#include<string>
#include<iostream>
using namespace std;
int main(){
	map<string,int> m;
	m.insert(make_pair("a",17));
	m.insert(make_pair("b",74));
	pair<map<string,int>::iterator, bool> p=m.insert(make_pair("c",4));
	p=m.insert(make_pair("b",11));
	cout<<p.first->second<<endl;
}
