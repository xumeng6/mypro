#include<iostream>
using namespace std;
class empty{
};
int main(int argc,char *argv[])
{
	empty e;
	empty e1;
	cout<<sizeof(e)<<" "<<&e<<endl;
	cout<<sizeof(e1)<<" "<<&e1<<endl;
	return 0;
}
