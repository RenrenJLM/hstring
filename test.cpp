#include <iostream>
#include "hstring.h"
using std::cout;
using std::cin;
using std::endl;

int main()
{
    cout << "hstring 类的缓冲区大小 BUF = 10, 接下来测试 hstring 类对象的增删改查等功能。" << endl << endl;
// 测试 hstring 对象初始化
    cout << "初始化 hstring 对象： (默认长度不超过 BUF-1, 即 len<=9) " << endl;
    hstring str1;
    hstring str2 = "123456789";     // 用来进行 + 的示例，和 modify 的示例
    hstring str3 = str2;            // 用来进行 - 的示例，和 Index 的示例
    cout << "初始化 str, str1, str2 :" << endl
         << "'hstring str1;'" << endl
         << "'hstring str2 = \"123456789\";'" << endl
         << "'hstring str3 = str2;'" << endl;
    cout << "初始化结果: " << endl
         << "str1.len = " << str1.get_len() << endl
         << "str2 = " << str2 << ", str2.len = " << str2.get_len() << endl
         << "str3 = " << str3 << ", str3.len = " << str3.get_len() << endl << endl;

// 测试重载 '='
    hstring pattern_st1;
    pattern_st1 = 34;
    hstring pattern_st2 = "abc";
    hstring pattern_st3 = "456";
    cout << "重载 '=', 实现 int 转 hstring 字符串：" << endl
         << "'hstring pattern_st1; pattern_st1 = 34;' " << endl
         << "pattern_st1 = " << pattern_st1 << ", pattern_st1.len = " << pattern_st1.get_len() << endl
         << "'hstring pattern_st2 = \"abc\";'" << endl
         << "'hstring pattern_st3 = \"456\";'" << endl << endl;

// 测试重载 '+'
    cout << "重载 '+' 运算符：" << endl
         << "str2 + pattern_st2 = " << str2+pattern_st2 << ", str2.len = " << str2.get_len() << endl << endl;

// 测试重载 '-'
    cout << "重载 '-' 运算符：" << endl
         << "str3 - pattern_st3 = " << str3-pattern_st3 << ", str3.len = " << str3.get_len() << endl;
    cout << "删除失败的情况：再次执行 str3 - pattern_st3 " << endl
         << "'str3 - pattern_st3;'" << endl;
    str3-pattern_st3;
    cout << "此时，str3 = " << str3 << ", str3.len = " << str3.get_len() << endl << endl;

// 测试改数据
    cout << "利用 modify() 方法改数据：" << endl
         << "str2 = " << str2 << ", str2.len = " << str2.get_len() << endl;
    if(str2.modify(pattern_st1, pattern_st2))
         cout << "str2.modify(pattern_st1, pattern_st2) 修改成功，str2 = " << str2 << ", str2.len = " << str2.get_len() << endl;
    cout << "修改失败的情况：再次调用 str2.modify(pattern_st1, pattern_st2) " << endl
         << "'str2.modify(pattern_st1, pattern_st2);'" << endl;
    str2.modify(pattern_st1, pattern_st2);
    cout << "此时，str2 = " << str2 << ", str2.len = " << str2.get_len() << endl << endl;

// 测试查数据
    cout << "利用 Index() 方法查数据：" << endl
         << "str3 = " << str3 << ", str3.len = " << str3.get_len() << endl;
    if(str3.Index("78")!=-1)
         cout << "str3.Index(\"78\") 查询成功，str3.Index(\"78\") = "  << str3.Index("78") << endl;
    cout << "查询失败的情况：str3.Index(\"34\") " << endl
         << "'str3..Index(\"34\");'" << endl;
    str3.Index("34");
    cout << endl;

// 测试从 cin 输入 hstring 对象
    hstring str_cin1, str_cin2;
    cout << "测试从 cin 输入 hstring 对象" << endl
         << "'hstring str_cin1;'" << endl
         << "请输入一个 hstring 对象给 str_cin1 ：(最多读取 BUF-1 个字符)" << endl;
    cin >> str_cin1;
    cout << "str_cin1 = " << str_cin1 << ", str_cin1.len = " << str_cin1.get_len() << endl << endl;

    cout << "'hstring str_cin2;'" << endl
         << "请输入一个 hstring 对象给 str_cin2 ：(最多读取 BUF-1 个字符)" << endl;
    cin >> str_cin2;
    cout << "str_cin2 = " << str_cin2 << ", str_cin2.len = " << str_cin2.get_len() << endl;

    return 0;
}
