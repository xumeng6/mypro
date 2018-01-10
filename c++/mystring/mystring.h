#ifndef _MYSTRING_H_
#define _MYSTRING_H_
#include<iostream>
class mystring{
public:
	mystring(const char*pstr="");
	mystring(const mystring& str);
	~mystring();
	
	void showstring();
	void Add(const mystring& str);
	void Copy(const mystring& str);
	int Getlength();
private:
	char* m_buf;
};
#endif
