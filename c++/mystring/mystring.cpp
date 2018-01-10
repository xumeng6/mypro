#include<iostream>
#include<cstring>
#include"mystring.h"
using namespace std;
mystring::mystring(const char* pstr){
	if(NULL==pstr)
	{
		m_buf=new char[1];
		m_buf='\0';
	}else
	{
		m_buf=new char[strlen(pstr)+1];
		strcpy(m_buf,pstr);
	}
}
mystring::mystring(const mystring& str){
	if(NULL==str.m_buf)
	{
		m_buf=0;
	}else
	{
		m_buf=new char[strlen(str.m_buf)+1];
		strcpy(m_buf,str.m_buf);
	}

}
mystring::~mystring(){
	delete[] m_buf;
}
int mystring::Getlength(){
	return strlen(m_buf);
}
void mystring::showstring(){
	cout<<"the string is:"<<m_buf<<endl;
}
void mystring::Add(const mystring& str){
	if(NULL!=str.m_buf){
		char *tmp=m_buf;
		m_buf=new char[strlen(tmp)+strlen(str.m_buf)+1];
		cout<<tmp<<strlen(tmp)<<endl;
		strcpy(m_buf,tmp);
		strcat(m_buf,str.m_buf);
		delete[] tmp;
	}	
}
void mystring::Copy(const mystring& str){
	if(this!=&str){
	delete[] m_buf;
	m_buf=new char[strlen(str.m_buf)+1];
	strcpy(m_buf,str.m_buf);
}
}
