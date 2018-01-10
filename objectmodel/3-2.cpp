#include<iostream>
#include<list>
#include<assert.h>
#include<stddef.h>
using namespace::std;
class point3d{
	private:
		float x;
		static list<point3d*> *freelist;
	public:
		float y;
		static const int chunksize= 250;
	public:
		float z;

};
/*template<class class_type,class data_type1,class data_type2>
  char* access_order(data_type1 class_type::*mem1,data_type2 class_type::*mem2){
  assert(mem1!=mem2);
  return mem1<mem2 ? "mem1 occurs first":"mem2 occurs first";
  }*/
int main()
{
	point3d a;
//char* m;
//	m=access_order(&point3d::z,&point3d::y);
//	cout<<m<<endl;
	cout<<&a.z<<endl;
	cout<<&a.y<<endl;
	//	printf("%p",offsetof(point3d,x));
//	printf("%p",offsetof(point3d,y));
//	printf("%p",offsetof(point3d,z));
	return 0;

}
