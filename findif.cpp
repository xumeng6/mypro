#include<iostream>
#include<vector>
#include<ext/functional>
#include<algorithm>
//using namespace::std;
//using namespace::__gnu_cxx;
int main(){
	typedef std::pair<int,char*> Pair;
	std::vector<Pair> v;
	v.push_back(Pair(3,"a"));
	v.push_back(Pair(7,"b"));
	v.push_back(Pair(2,"c"));
	v.push_back(Pair(0,"d"));
	v.push_back(Pair(6,"e"));
	std::vector<Pair>::iterator p= std::find_if(v.begin(),v.end(), __gnu_cxx::compose1(bind2nd(std::equal_to<int>(),2), __gnu_cxx::select1st<Pair> () ));
	std::cout<<"found::"<<p->first<<' '<<p->second<<std::endl;
}
