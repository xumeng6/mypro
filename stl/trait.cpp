#include<algorithm>
#include<iostream>
#include<vector>
using namespace::std;
class tmp:public iterator_traits<int*>{
	public:
		tmp(int p=0):num(p){}
		~tmp(){}
		int operator*(){
			return num;
		}
	private:
		int num;
};
template<class ty>
typename iterator_traits<ty>::value_type func1(ty iter){
	return *iter;
}

template<class I>
typename iterator_traits<I>::value_type func(const I &a,const I &b){
	
	typename iterator_traits<I>::value_type tmp;
	for(I p=a;p!=b;p++){
		tmp=*p;
		cout<<tmp<<' ';	
	}
	cout<<endl;
	
}
int main(){
	vector<int> a{1,2,3,6,78,999};
	tmp b(8);
	cout<<func1(b)<<endl;
	func<vector<int>::iterator>(a.begin(),a.end());
}
