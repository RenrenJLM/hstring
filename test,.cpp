#include <iostream>
// #include "hstring.h"
using namespace std;

size_t hstrlen(const char* s)
{
    size_t len = 0;
    while(*s++)
        len++;
    return len;
}

int main()
{
    char s[10] = "0123456";
    cout << "The address of s = " << (void*)s << endl;
    cout << "The length of s = " <<  hstrlen(s) << endl;
    cout << "The address of s = " <<  (void*)s << endl;
    cout << "The value of *s = " <<  *s << endl;
    cout << "The ASCII value of *s = " <<  int(*s) << endl;
    return 0;
}
