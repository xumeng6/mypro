#ifndef _IOTEK_STRING_H_
#define _IOTEK_STRING_H_
#include<iostream>
namespace iotek{

class String{
public:
	String(const char* = NULL);
	~String();

	String(const String&);

	String& operator=(const String&);
	String& operator=(const char*);
	String& operator+=(const String&);
	String operator+(const String&) const; 
	String& operator+=(const char*);
	String operator+(const char*) const; 

	inline const char* data() const
	{
		return m_data;
	}
private:
	char *m_data;



};

}




#endif
