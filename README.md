## 实现自己的 string 类—— hstring
<br>

### 实现要求:
1. 存储数据的时候使用缓冲区，使用缓冲区的目的是为了尽量减少频繁的 NEW/DEL 内存带来的资源损耗  

2. 重载 `+` 增加数据，增加数据要实现的形态: “123456789” + “abc”  得到 “123456789abc” （最多new一次）new 之前判断是否超过缓冲区，超过了才 new  

3. 重载 `-` 删除数据，增加数据要实现的形态: “123456789” - “456”  得到 “123789” （函数中不使用new）  

4. 改数据，要求将 “123456789” 中的 “34” 修改为 “abc” 得到 “12abc56789” （最多new一次）原理同上  

5. 查，“123456” 查 “34” 得到 “34” 的位置 `2` （不使用new）  

6. 重载 `=` 实现 `int` 转 `hstring` 字符串 （最多new一次）  

7. 不能使用库函数（memcpy可使用）  

8. 对每个功能进行测试（注意：在查找、删除、修改的时找不到字符串要给出错误提示）  

- **运行 `test.cpp` 可进行功能测试**  