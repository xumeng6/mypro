#include<iostream>
#include<vector>
#include<ctime>
#include<cstdlib>
using namespace::std;
void bubblesort(vector<int>&a)
{
	int i,j;
	bool flag=true;
	for(i=0;i < a.size() && flag;i++)
	{
		flag=false;
		for(j=a.size()-1;j>=i;j--)
		{
			if(a[j-1]>a[j])
			{
				int tmp=a[j-1];
				a[j-1]=a[j];
				a[j]=tmp;
				flag=true;
			}
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
	bubblesort(a);
	for(vector<int>::iterator it=a.begin();it!=a.end();++it)
	{	
		cout<<*it<<'-';
	}
	cout<<endl;
	return 0;
}
