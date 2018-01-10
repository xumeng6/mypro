#include<iostream>
#include<vector>
#include<ctime>
#include<cstdlib>
using namespace::std;
void selectsort(vector<int>&a)
{
	for(int i=0;i<a.size();++i)
	{
		int min=i;
		for(int j=i+1;j<a.size();++j)
		{
			if(a[min]>a[j])
				min=j;
		}
		if(min!=i)
		{
			swap(a[min],a[i]);
		}
	}
}
int random(int begin,int end)
{
	return(begin+rand()%end);
}
int main()
{
	vector<int> a;
	srand( time(0));
	for(int i =0;i<random(10,20);++i)
	{
		a.push_back(random(0,100));
	}
	for(vector<int>::iterator it=a.begin();it!=a.end();++it)
	{
		cout<<*it<<'-';
	}
	cout<<endl;
	selectsort(a);
	for(vector<int>::iterator it=a.begin();it!=a.end();++it)
	{
		cout<<*it<<'-';
	}
	cout<<endl;
	return 0;
}
