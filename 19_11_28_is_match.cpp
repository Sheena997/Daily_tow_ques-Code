/*
链接：https://www.nowcoder.com/practice/43072d50a6eb44d2a6c816a283b02036?tpId=37&&tqId=21294&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
来源：牛客网
题目描述
问题描述：在计算机中，通配符一种特殊语法，广泛应用于文件搜索、数据库、正则表达式等领域。现要求各位实现字符串通配符的算法。
要求：
实现如下2个通配符：
*：匹配0个或以上的字符（字符由英文字母和数字0-9组成，不区分大小写。下同）
？：匹配1个字符
输入：
通配符表达式；
一组字符串。
输出：
返回匹配的结果，正确输出true，错误输出false
输入描述:
先输入一个带有通配符的字符串，再输入一个需要匹配的字符串
输出描述:
返回匹配的结果，正确输出true，错误输出false
示例1
输入
te?t*.*
txt12.xls
输出
false
*/
#include <iostream>
#include <string>

using namespace std;

bool is_match(const char* s1, const char* s2)
{
    if(*s1 == '\0' && *s2 == '\0')
        return true;
    if(*s1 == '\0' || *s2 == '\0')
        return false;
    if(*s1 == *s2)
        return is_match(s1 + 1, s2 + 1);
    if(*s1 == '?')
        return is_match(s1 + 1, s2 + 1);
    if(*s1 == '*')
        return is_match(s1, s2 + 1) || is_match(s1 + 1, s2) || is_match(s1 + 1, s2 + 1);
    return false;
}
int main()
{
    string s1, s2;
    
    while(cin >> s1 >> s2)
    {
        if(is_match(s1.c_str(), s2.c_str()))
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }

    return 0;
}