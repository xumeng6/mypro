#include<iostream>
#include<vector>
#include<functional>
#include<iterator>
#include<algorithm>
using namespace::std;
class a:public vector<int>{
	public:
		void f(){
			iterator it = begin();
			iterator it_end = end();
			while(it != it_end)
			{
				cout << *it++ << endl;
			}
			cout<<"aasd"<<endl;
		}
		a(int n):vector<int>(n){}

};
int main(){

	vector<a> v;
	v.push_back(a(2));
	v.push_back(a(7));
	v.push_back(a(3));
//	transform(v.begin(),v.end(),ostream_iterator<int>(cout," "),mem_fun_ref(&a::f));
	for_each(v.begin(),v.end(),mem_fun_ref(&a::f));
	cout<<endl;
}
