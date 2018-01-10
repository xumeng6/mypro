#include<iostream>
#include<iterator>
#include<vector>
#include<ext/algorithm>
using namespace std;
int main(){
	vector<int> v;
	copy(istream_iterator<int>(cin),istream_iterator<int>(),back_inserter(v));
	copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));

}
