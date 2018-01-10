#include<cstring>
#include<iostream>
#include<vector>
using namespace::std;

int ar[10]={12,45,234,64,12,63,23,12,55};
//char* str="Hello World";
void quicksort(vector<int> &v,int left,int right);
int main()
{
	vector<int>vec1(ar,ar+10);
//	vector<char>vec2(str,str+strlen(str));
	cout<<"vec1:"<<endl;
	for(vector<int>::const_iterator iter=vec1.begin();iter!=vec1.end();++iter)
		cout<<*iter<<'\t';
	cout<<endl;
	quicksort(vec1,0,vec1.size()-1);
	for(vector<int>::const_iterator iter=vec1.begin();iter!=vec1.end();++iter)
		cout<<*iter<<'\t';
	cout<<endl;
//	cout<<'\n'<<"vec2:"<<endl;
//	for(vector<char>::const_iterator iter2=vec2.begin();iter2!=vec2.end();++iter2)
//		cout<<*iter2;
//	cout<<'\n';
	
	return 0;
}
void quicksort(vector<int>& v,int left,int right)
{
	if(left<right)
	{
		int key=v[left];
		int low=left;
		int high=right;
		while(low<high)
		{
			while(low<high && v[high]>=key){
				--high;
			}
			v[low] = v[high];
			while(low<high && v[low]<=key){//pay attention to the equal, otherwise it will get into endless loop!
				++low;
			}
			v[high]=v[low];
		}
		v[low]=key;
		quicksort(v,left,low-1);
		quicksort(v,low+1,right);
	}

}
