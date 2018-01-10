#include<iostream>

int abc(int a,int b,int c){
	if(a<=0||b<=0||c<0)
		throw "all parameters should be >0";
	return a+b/c;
}
int main(){
	int a,b,c,d;
//	std::cin>>a>>b>>c;
	try{std::cout<<abc(2,1,0)<<std::endl;}
	catch(char* e){
		std::cout<<e
		<<"ian"
		<<std::endl;
		return 1;
}
return 0;
}
