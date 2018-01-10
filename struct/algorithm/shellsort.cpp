#include<iostream>
#include<vector>
#include<ctime>
#include<cstdlib>
using namespace::std;
void shellsort(vector<int>&a)
{
	int i,j;
	for(int gap=a.size()/2;gap>0;gap /=2)
	{
		for(i=0;i<a.size();i=i+gap)
		{
			int tmp=a[i];
			for(j=i;j>=gap&&a[j-gap]>tmp;j=j-gap)
				a[j]=a[j-gap];
			a[j]=tmp;

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
	shellsort(a);
	for(vector<int>::iterator it=a.begin();it!=a.end();++it)
	{
		cout<<*it<<'-';
	}
	cout<<endl;
	return 0;
}
