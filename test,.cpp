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
    stp = 34;
    hstring stl = "abc";
    hstring stu = "999";

    cout << "str1 = " << str1 << endl
         << "str2 = " << str2 << endl
         << "stp = " << stp << endl
         << "stl = " << stl << endl 
         << "stu = " << stu << endl << endl;
    
    cout << "str1.Index(stp) = " << str1.Index(stp) << endl;
    if(str1.Index(stu)!=-1)
          cout << "str1.Index(stu) = " << str1.Index(stu) << endl << endl;
    if(str1.modify(stp, stl))
          cout << "str1.modify(stp, stl) 修改成功！" << endl
               << "str1 = " << str1 << endl;
    cout << "str1 + stl = " << str1 + stl << endl
         << "str2 - stp = " << str2 - stp << endl
         << "str2 + stl = " << str2 + stl << endl;

    return 0;
}
