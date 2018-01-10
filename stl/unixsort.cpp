#include<iostream>
#include<algorithm>
#include<vector>
#include<iterator>
using namespace::std;
struct strtab_cmp
{
	typedef vector<char>::iterator strtab_iterator;
	bool operator()(const pair<strtab_iterator,strtab_iterator>& x,
			const pair<strtab_iterator,strtab_iterator>& y)const{
		return lexicographical_compare(x.first,x.second,y.first,y.second);
	}
};

struct strtab_print
{
	ostream& out;
	strtab_print(ostream& os):out(os){}
	typedef vector<char>::iterator strtab_iterator;
	void operator()(const pair<strtab_iterator,strtab_iterator>& s)const{
		copy(s.first,s.second,ostream_iterator<char>(out));
	}
};
int main()
{
	vector<char> strtab;
	char c;
	while(cin.get(c)){
		strtab.push_back(c);
	}
	cout<<endl;
	typedef vector<char>::iterator strtab_iterator;
	vector<pair<strtab_iterator,strtab_iterator> > lines;
	strtab_iterator start=strtab.begin();
	while(start!=strtab.end())
	{
		strtab_iterator next=find(start,strtab.end(),'\n');
		if(next!=strtab.end())
			++next;
		lines.push_back(make_pair(start,next));
		start=next;
	}
	sort(lines.begin(),lines.end(),strtab_cmp());
	for_each(lines.begin(),lines.end(),strtab_print(cout));
	cout<<endl;
}
