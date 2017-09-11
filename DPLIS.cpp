#include<iostream>
using namespace::std;
int main(){
	int seq[10]={4,5,7,8,3,2,6,7,33,5};
	int opt[10]={0};
	int max=0;
	opt[0]=1;
	for(int i=1;i<10;++i){
		opt[i]=1;
		for(int j=0;j<i;++j){
			if(seq[j]<=seq[i]&&opt[j]+1>opt[i])
				opt[i]=opt[j]+1;
		}
	}
	for(int i=0;i<10;++i){
		if(opt[i]>max)
			max=opt[i];
	}
	cout<<max<<endl;
}
