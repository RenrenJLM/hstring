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
    nextval = nullptr;
}

hstring::hstring(const char* s)
{
    buffer = new char[BUF];
    len = hstrlen(s);
    str = new(buffer) char[len+1];
    memcpy(str, s, len+1);
    buflen = len + 1;
    nextval = new(buffer + buflen) int[len];
    buflen += len * sizeof(int);
    get_nextval(*this);
}

hstring::hstring(const hstring & st)
{
    buffer = new char[BUF];
    len = st.len;
    str = new(buffer) char[len+1];
    memcpy(str, st.str, len+1);
    buflen = len + 1;
    nextval = new(buffer + buflen) int[len];
    buflen += len * sizeof(int);
    get_nextval(*this);
}

hstring::~hstring()
{
    delete [] buffer;
}

// KMP matching algorithm
void get_nextval(const hstring & st)
{
    st.nextval[0] = -1;  // 与经典next数组的区别，nextval[0]总是设为-1
    int j = 0;           // 模式串的指针
    int k = -1;          // 辅助指针，用来记录前缀与后缀相同的最大长度

    while (j < st.len - 1) {
        if (k == -1 || st.str[j] == st.str[k]) {
            j++;
            k++;
            if (st.str[j] != st.str[k]) {
                st.nextval[j] = k;
            } else {
                // 优化：如果当前字符与前一个最长匹配的字符相等
                // 则跳过当前字符，直接使用前一个最长匹配的nextval值
                st.nextval[j] = st.nextval[k];
            }
        } else {
            // 递归寻找最长可匹配前缀
            k = st.nextval[k];
        }
    }
}

int hstring::Index_KMP(const hstring & st)const
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
    nextval = new(buffer + buflen) int[len];
    memcpy(nextval, st.nextval, len);
    buflen += len * sizeof(int);
    return *this;
}

hstring & hstring::operator=(const char* s)
{
    buflen = 0;
    len = hstrlen(s);
    str = new(buffer) char[len+1];
    memcpy(str, s, len+1);
    buflen = len + 1;
    nextval = new(buffer + buflen) int[len];
    get_nextval(*this);
    buflen += len * sizeof(int);
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
// 更新 buflen 和 nextval
    buflen = len + 1;
    nextval = new(buffer + buflen) int[len];
    get_nextval(*this);
    buflen += len * sizeof(int);
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

hstring hstring::operator+(const hstring & st)
{
    buflen = 0;
    str = new(buffer) char[len+st.len+1];
    memcpy(str+len, st.str, st.len+1);
    len += st.len;
    buflen = len + 1;
    nextval = new(buffer + buflen) int[len];
    get_nextval(*this);
    buflen += len * sizeof(int);
    return *this;
}

hstring hstring::operator-(const hstring & st)
{
    Index_KMP(st);
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