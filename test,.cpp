#include <iostream>
#include "hstring.h"
using std::cout;
using std::cin;
using std::endl;

int main()
{
    hstring str1 = "123456789";
    hstring str2 = str1;
    hstring stp = hstring();
    stp = "34";
    hstring stl = "abc";
    hstring stu = "999";

    cout << "str1 = " << str1 << endl
         << "str2 = " << str2 << endl
         << "stp = " << stp << endl
         << "stl = " << stl << endl 
         << "stu = " << stu << endl << endl;
    
    cout << "str1.Index(stp) = " << str1.Index(stp) << endl
         << "str1.Index(stu) = " << str1.Index(stu) << endl
         << "str1.modify(stp, stl) = " << str1.modify(stp, stl) << endl
         << "str2 - stp = " << str1 + stl << endl
         << "str2 + stl = " << str1 + stl << endl;

    return 0;
}
