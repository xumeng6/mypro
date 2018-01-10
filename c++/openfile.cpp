#include<fstream>
int main(int argc,char* argv[]){
	std::ofstream ex("example.txt",std::ios::out|std::ios::app);
	if(ex.is_open()){
		ex<<"aaaaaaaa";
		ex<<"bbbbbbb"<<std::endl;
		ex.close();
	}
return 0;
}
