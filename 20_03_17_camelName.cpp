/*
来源：牛客网
链接：
https://www.nowcoder.com/practice/aed1c7bbc2604e7c9661a2348b0541b8?tpId=3&tqId=10928&rp=1&ru=/activity/oj&qru=/ta/hackathon/question-ranking

题目描述
从C/C++转到Java的程序员，一开始最不习惯的就是变量命名方式的改变。
C语言风格使用下划线分隔多个单词，例如“hello_world”；而Java则采用
一种叫骆驼命名法的规则：除首个单词以外，所有单词的首字母大写，例
如“helloWorld”。
请你帮可怜的程序员们自动转换变量名。
输入描述:
输入包含多组数据。
每组数据一行，包含一个C语言风格的变量名。每个变量名长度不超过100。
输出描述:
对应每一组数据，输出变量名相应的骆驼命名法。
示例1
输入
复制
hello_world<br/>nice_to_meet_you
输出
复制
helloWorld<br/>niceToMeetYou
*/
// write your code here cpp
#include <iostream>

using namespace std;

string camelName(string str)
{
    string res = "";
    for(int i = 0; i < str.size(); ++i)
    {
        if(str[i] == '_')
        {
            res += (str[i + 1] - 32);
            ++i;
        }
        else 
        {
            res += str[i];
        }
    }
    
    return res;
}
int main()
{
    string str;
    while(cin >> str)
    {
        string res = "";
        
        res = camelName(str);
        
        cout << res << endl;
    }
    
    return 0;
}