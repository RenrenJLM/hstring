#include <iostream>
#include <cstring>
#include "hstring.h"
size_t hstrlen(const char* s);
void hstrmemmove(char* dest, size_t len, int n);

size_t hstrlen(const char* s)
{
    size_t len = 0;
    while(*s++)
        len++;
    return len;
}

void hstrmemmove(char* dest, size_t len, int n)
{
    if(n>0)
        for(int i=len-1; i>=0; i--){dest[i+n]=dest[i];};
    if(n<0)
        for(int i=0; i<=len-1; i++){dest[n+i]=dest[i];};
}

// constructors
hstring::hstring():buffer(nullptr),capacity(0),length(0){}

hstring::hstring(const char* s)
{
    length = hstrlen(s);
    capacity = length+1;
    buffer = new char[capacity];
    memcpy(buffer, s, length+1);
}

hstring::hstring(const hstring & st)
{
    length = st.length;
    capacity = length+1;
    buffer = new char[capacity];
    memcpy(buffer, st.buffer, length+1);
}

hstring::~hstring()
{
    delete [] buffer;
}

// Simple Pattern Matching Algorithm
int hstring::Index(const hstring & st)const
{
    int i=0, j=0;
    while(i<=length-1 && j<=st.length-1)
    {
        if(buffer[i]==st.buffer[j])
        {
            ++i; ++j;
        }
        else
        {
            i=i-j+1;
            j=0;
        }
    }
    if(j==st.length)
        return i-st.length;
    else 
    {
        std::cout << "没有匹配的字符串，查找失败！" << std::endl;
        return -1;
    }
}

// Method of modifying hstring
bool hstring::modify(const hstring & stp, const hstring & stl)
{
    int pos = Index(stp);
    if(pos==-1)
    {
        std::cout << "没有匹配的字符串，修改失败！" << std::endl;
        return false;
    }

    if(capacity < length-stp.length+stl.length+1)
        expend(length-stp.length+stl.length+1);

    hstrmemmove(buffer+pos+stp.length, length-pos-stp.length+1, stl.length-stp.length);
    memcpy(buffer+pos, stl.buffer, stl.length);
    length = length-stp.length+stl.length;
    return true;
    // if(capacity >= length-stp.length+stl.length+1)
    // {
    //     hstrmemmove(buffer+pos+stp.length, length-pos-stp.length+1, stl.length-stp.length);
    //     memcpy(buffer+pos, stl.buffer, stl.length);
    //     length = length-stp.length+stl.length;
    //     return true;
    // }
    // else
    // {
    //     expend(length-stp.length+stl.length+1);
    //     hstrmemmove(buffer+pos+stp.length, length-pos-stp.length+1, stl.length-stp.length);
    //     memcpy(buffer+pos, stl.buffer, stl.length);
    //     length = length-stp.length+stl.length;
    //     return true;
    // }
}

// overloaded operator methods
hstring & hstring::operator=(const hstring & st)
{
    if (this == &st)
        return *this;

    if(capacity < st.length+1)
        expend(st.length+1);
    
    memcpy(buffer, st.buffer, st.length+1);
    length = st.length;
    return *this;
    // if(capacity>=st.length+1)
    // {
    //     memcpy(buffer, st.buffer, st.length+1);
    //     length = st.length;
    //     return *this;
    // }
    // else
    // {
    //     expend(st.length+1);
    //     memcpy(buffer, st.buffer, st.length+1);
    //     length = st.length;
    //     return *this;
    // }
}

hstring & hstring::operator=(const char* s)
{
    int s_len = hstrlen(s);
    if(capacity < s_len+1)
        expend(s_len+1);
        
    memcpy(buffer, s, s_len+1);
    length = s_len;
    return *this;
    // if(capacity>=s_len+1)
    // {
    //     memcpy(buffer, s, s_len+1);
    //     length = s_len;
    //     return *this;
    // }
    // else
    // {
    //     expend(s_len+1);
    //     memcpy(buffer, s, s_len+1);
    //     length = s_len;
    //     return *this;
    // }
}

hstring & hstring::operator=(const int n)
{
// 计算 nlen
    int nlen = 1;
    int l = n/10;
    while(l)
    {
        nlen++;
        l = l/10;
    }

    if(capacity<nlen+1)
        expend(nlen+1);
// 将数据填入 buffer 为起点的内存中
    l = n;
    for(int i=nlen-1; i>=0; i--)
    {
        buffer[i] = '0' + l%10;     // 将数字转换为对应字符
        l = l/10;
    }
    buffer[nlen] = '\0';
    length = nlen;
    return *this;
}

char & hstring::operator[](int i)
{
    return buffer[i];
}

const char & hstring::operator[](int i)const        // 对于 const 对象的 [] 重载
{
    return buffer[i];
}

hstring hstring::operator+(const hstring & st)
{
    hstring temp;
    temp.expend(length+st.length+1);
    memcpy(temp.buffer, buffer, length);
    memcpy(temp.buffer+length, st.buffer, st.length+1);
    temp.length = length+st.length;
    return temp;
}

hstring hstring::operator-(const hstring & st)
{
    int pos = Index(st);
    if(pos==-1)
    {
        std::cout << "没有匹配的字符串，删除失败！" << std::endl;
        return *this;
    }
    hstring temp = *this;
    hstrmemmove(temp.buffer+pos+st.length, temp.length-pos-st.length+1, -st.length);
    temp.length = temp.length-st.length;
    return temp;
}

hstring & hstring::operator+=(const hstring & st)
{
    *this = *this + st;
    return *this;
}

hstring & hstring::operator-=(const hstring & st)
{
    *this = *this - st;
    return *this;
}

// overloaded operator friends
std::ostream & operator<<(std::ostream & os, const hstring & st)
{
    os << st.buffer;
    return os;
}

// other method
const int hstring::get_len()const
{
    return this->length;
}