#ifndef HSTRING_H_
#define HSTRING_H_
#include <iostream>

class hstring
{
private:
    char* buffer;
    int capacity;
    int length;
// 扩展缓冲区 buffer, 并将原数据复制到新缓冲区中，不改变 length
    void expend(size_t new_capacity)
    {
        char* new_buffer = new char[new_capacity];
        if (buffer) {
            memcpy(new_buffer, buffer, length);
            delete[] buffer;
        }
        buffer = new_buffer;
        capacity = new_capacity;
    };
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
    hstring operator+(const hstring & st);
    hstring operator-(const hstring & st);
    hstring & operator+=(const hstring & st);
    hstring & operator-=(const hstring & st);
// overloaded operator friends
    friend std::ostream & operator<<(std::ostream & os, const hstring & st);
// other method
    const int get_len()const;
};

#endif