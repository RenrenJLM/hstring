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
    static const int BUF = 10;
    char* buffer;
    int buflen;
public:
// constructors
    hstring();
    hstring(const char* s);
    hstring(const hstring & st);
    ~hstring();
// Simple Pattern Matching Algorithm
    int Index(const hstring & st)const;
// Method of modifying hstring
    bool modify(const hstring & stp, const hstring & stl);
// overloaded operator methods
    hstring & operator=(const hstring & st);
    hstring & operator=(const char* s);
    hstring & operator=(const int n);
    char & operator[](int i);
    const char & operator[](int i)const;
    hstring & operator+(const hstring & st);
    hstring & operator-(const hstring & st);
// overloaded operator friends
    friend ostream & operator<<(ostream & os, const hstring & st);
    friend istream & operator>>(istream & is, hstring & st);
// other method
    const int get_len()const;
};

#endif