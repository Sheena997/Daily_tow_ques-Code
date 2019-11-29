/*
链接:https://www.nowcoder.com/practice/181a1a71c7574266ad07f9739f791506?tpId=37&&tqId=21288&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
来源：牛客
题目描述
查找两个字符串a,b中的最长公共子串。若有多个，输出在较短串中最先出现的那个。
输入描述:
输入两个字符串
输出描述:
返回重复出现的字符
示例1
输入
abcdefghijklmnop
abcsafjklmnopqrstuvw
输出
jklmnop
*/
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

void the_long_substr(string s1, string s2)
{
    string res;
    for(int i = 0; i < s1.size(); ++i)
    {
        for(int j = i; j < s1.size(); ++j)
        {
            string tmp = s1.substr(i, j - i + 1);
            if(s2.find(tmp) == -1)
                break;
            else if(res.size() < tmp.size())
                res = tmp;
        }
    }
    cout << res << endl;
}
int main()
{
    string s1, s2;
    
    while(cin >> s1 >> s2)
    {
        if(s1.size() > s2.size())
            swap(s1, s2);
        the_long_substr(s1, s2);
    }
    
    return 0;
}