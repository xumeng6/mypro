#include <iostream>
#include<fstream>
using namespace::std;
int main(int argc, char*argv[]) {
	if (argc != 3) {
		cout << argv[0] << "new file" <<endl;
		return 0;
	}
	ifstream f1(argv[1], ios::in | ios::binary); 
	if(!f1){
		cout << "open" << argv[1] << "failed" << endl;
		return 1;
	}
	ofstream f2(argv[2], ios::out | ios::binary); 
	if(!f2){
		cout << "open" << argv[2] << "failed" << endl;
		return 2;
	}
	char buf[1000];
	while (f1) {
		f1.read(buf, sizeof(buf));
		f2.write(buf,f1.gcount());
	}
}
