#include<iostream>
#include<vector>
#include<ctime>
#include<cstdlib>
using namespace::std;
void strinsort(vector<int>&a)
{
	int i,j;
	for(i=1;i<a.size();++i)
	{
		if(a[i]<a[i-1])
		{
			int tmp=a[i];
			for(j=i-1;j>=0&&a[j]>tmp;--j)
				a[j+1]=a[j];
			a[j+1]=tmp;
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
	strinsort(a);
	for(vector<int>::iterator it=a.begin();it!=a.end();++it)
	{	
		cout<<*it<<'-';
	}
	cout<<endl;
	return 0;
}
