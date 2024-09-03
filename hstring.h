#ifndef HSTRING_H_
#define HSTRING_H_
#include <iostream>
using std::ostream;
using std::istream;

class hstring
{
private:
    char* str;
    int len;
    static const int BUF = 512;
    char* buffer;
    int buflen;
    int* nextval;
public:
// constructors
    hstring();
    hstring(const char* s);
    hstring(const hstring & st);
    ~hstring();
// KMP matching algorithm
    friend void get_nextval(const hstring & st);
    int Index_KMP(const hstring & st)const;
// overloaded operator methods
    hstring & operator=(const hstring & st);
    hstring & operator=(const char* s);
    hstring & operator=(const int n);
    char & operator[](int i);
    const char & operator[](int i)const;
    hstring operator+(const hstring & st);
    hstring operator-(const hstring & st);
// overloaded operator friends
    friend ostream & operator<<(ostream & os, const hstring & st);
    friend istream & operator>>(istream & is, hstring & st);
};

#endif