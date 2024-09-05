#include <iostream>
#include "hstring.h"
using std::cout;
using std::cin;
using std::endl;

int main()
{
// 测试 hstring 对象初始化
    cout << "初始化 hstring 对象：" << endl;
    hstring str1;
    hstring str2 = "123456789";     // 用来进行 + 的示例，和 modify 的示例
    hstring str3 = str2;            // 用来进行 - 的示例，和 Index 的示例
    cout << "初始化 str, str1, str2 :" << endl
         << "'hstring str1;'" << endl
         << "'hstring str2 = \"123456789\";'" << endl
         << "'hstring str3 = str2;'" << endl;
    cout << "初始化结果: " << endl
         << "str1.length = " << str1.get_len() << endl
         << "str2 = " << str2 << ", str2.length = " << str2.get_len() << endl
         << "str3 = " << str3 << ", str3.length = " << str3.get_len() << endl << endl;

// 测试重载 '='
    hstring pattern_st1;
    pattern_st1 = 34;
    hstring pattern_st2 = "abc";
    hstring pattern_st3 = "456";
    cout << "重载 '=', 实现 int 转 hstring 字符串：" << endl
         << "'hstring pattern_st1; pattern_st1 = 34;' " << endl
         << "pattern_st1 = " << pattern_st1 << ", pattern_st1.length = " << pattern_st1.get_len() << endl
         << "'hstring pattern_st2 = \"abc\";'" << endl
         << "'hstring pattern_st3 = \"456\";'" << endl << endl;

// 测试重载 '+'
    cout << "重载 '+' 运算符：" << endl
         << "str2 + pattern_st2 = " << str2+pattern_st2 << endl << endl;

// 测试重载 '-'
    cout << "重载 '-' 运算符：" << endl
         << "str3 - pattern_st3 = " << str3-pattern_st3 << endl
         << "'str3 - \"aa\"'" << endl;
    str3 - "aa";
    cout << endl;

// 测试改数据
    cout << "利用 modify() 方法改数据：" << endl
         << "str2 = " << str2 << ", str2.length = " << str2.get_len() << endl;
    if(str2.modify(pattern_st1, pattern_st2))
         cout << "str2.modify(pattern_st1, pattern_st2) 修改成功，str2 = " << str2 << ", str2.length = " << str2.get_len() << endl;
    cout << "修改失败的情况：再次调用 str2.modify(pattern_st1, pattern_st2) " << endl
         << "'str2.modify(pattern_st1, pattern_st2);'" << endl;
    str2.modify(pattern_st1, pattern_st2);
    cout << "此时，str2 = " << str2 << ", str2.length = " << str2.get_len() << endl << endl;

// 测试查数据
    cout << "利用 Index() 方法查数据：" << endl
         << "str3 = " << str3 << ", str3.length = " << str3.get_len() << endl;
    if(str3.Index("78")!=-1)
         cout << "str3.Index(\"78\") 查询成功，str3.Index(\"78\") = "  << str3.Index("78") << endl;
    cout << "查询失败的情况：str3.Index(\"33\") " << endl
         << "'str3..Index(\"33\");'" << endl;
    str3.Index("33");
    cout << endl;

// 测试 += 与 -=
   hstring str4 = "123456789", str5 = "abc", str6 = "345";
   cout << "str4 = " << str4 << endl
        << "str5 = " << str5 << endl
        << "str6 = " << str6 << endl;
   str4 += str5;
   cout << "'str4 += str5'" << endl
        << "str4 = " << str4 << endl;
   str4 -= str6;
   cout << "'str4 -= str6'" << endl
        << "str4 = " << str4 << endl << endl;

    return 0;
}
