#include<iterator>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
int main(){
	istream_iterator<double> first(cin);
	istream_iterator<double> end_of_file;
	vector<double> buf(first,end_of_file);
	nth_element(buf.begin(),buf.begin()+buf.size()/2,buf.end());
	cout<<"median:"<<buf[buf.size()/2]<<endl;
}
