#include<iostream>
#include<vector>
#include<ctime>
#include<cstdlib>
using namespace::std;
int qsort(vector<int>&a,int left,int right)
{
	if(left<right)
	{
		int key=a[left];
		int low=left;
		int high=right;
		while(low<high)
		{
			while(low<high&&a[high]>=key)
				--high;
			a[low]=a[high];
			while(low<high&&a[low]<=key)
				++low;
			a[high]=a[low];
		}
		a[low]=key;
		qsort(a,left,low-1);
		qsort(a,low+1,right);
	}
}
void quicksort(vector<int>&a)
{
	qsort(a,0,a.size()-1);
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
	quicksort(a);
	for(vector<int>::iterator it=a.begin();it!=a.end();++it)
	{
		cout<<*it<<'-';
	}
	cout<<endl;
	return 0;
}
