#include<iostream>
#include<algorithm>
#include<vector> 
using namespace::std;
class inte{
	private:
		int num;
	public:
		inte(int p=1):num(p){}
		~inte(){}
		bool operator()(int x) const{
			if(x%num)
				return false;
			else
				return true;
		}

};
int main(){
	vector<int> a{1,2,4,6,5,11,12,33};
	for(vector<int>::iterator iter=a.begin();iter!=a.end();++iter){
		cout<<*find_if(iter,a.end(),inte(2))<<endl;
	}
	return 0;
}
