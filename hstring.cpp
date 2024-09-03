#include <iostream>
#include <cstring>
#include <new>
#include "hstring.h"
using std::cin;
using std::cout;
size_t hstrlen(const char* s);

size_t hstrlen(const char* s)
{
    size_t len = 0;
    while(*s++)
        len++;
    return len;
}

// constructors
hstring::hstring()
{
    str = nullptr;
    len = 0;
    buffer = nullptr;
    buflen = 0;
}

hstring::hstring(const char* s)
{
    buffer = new char[BUF];
    len = hstrlen(s);
    str = new(buffer) char[len+1];
    memcpy(str, s, len+1);
    buflen = len + 1;
}

hstring::hstring(const hstring & st)
{
    buffer = new char[BUF];
    len = st.len;
    str = new(buffer) char[len+1];
    memcpy(str, st.str, len+1);
    buflen = len + 1;
}

hstring::~hstring()
{
    delete [] buffer;
}

// Simple Pattern Matching Algorithm
int Index(const hstring & st)
{

}

// overloaded operator methods
hstring & hstring::operator=(const hstring & st)
{
    if (this == &st)
        return *this;
    buflen = 0;
    len = st.len;
    str = new(buffer) char[len+1];
    memcpy(str, st.str, len+1);
    buflen = len + 1;
    return *this;
}

hstring & hstring::operator=(const char* s)
{
    buflen = 0;
    len = hstrlen(s);
    str = new(buffer) char[len+1];
    memcpy(str, s, len+1);
    buflen = len + 1;
    return *this;
}

hstring & hstring::operator=(const int n)
{
    buflen = 0;
// 计算 len
    len = 1;
    int l = n/10;
    while(l)
    {
        len++;
        l = l/10;
    }
// 存入 str 中
    str = new(buffer) char[len+1];
    l = n;
    for(int i=len-1; i>=0; i--)
    {
        str[i] = l%10;
        l = l/10;
    }
    str[len] = '\0';
// 更新 buflen
    buflen = len + 1;
    return *this;
}

char & hstring::operator[](int i)
{
    return str[i];
}

const char & hstring::operator[](int i)const
{
    return str[i];
}

hstring & hstring::operator+(const hstring & st)
{
    buflen = 0;
    str = new(buffer) char[len+st.len+1];
    memcpy(str+len, st.str, st.len+1);
    len += st.len;
    buflen = len + 1;
    return *this;
}

hstring & hstring::operator-(const hstring & st)
{
    if(Index(st)==-1)
    {
        cout << "没有匹配的字符串，删除失败！" << std::endl;
        return *this;
    }
}

// overloaded operator friends
ostream & operator<<(ostream & os, const hstring & st)
{
    os << st.str;
    return os;
}

istream & operator>>(istream & is, hstring & st)
{
    char temp[hstring::BUF];
    is.get(temp, hstring::BUF);
    if(is)
        st = temp;
    while(is && is.get()!='\0')
        continue;
    return is;
}