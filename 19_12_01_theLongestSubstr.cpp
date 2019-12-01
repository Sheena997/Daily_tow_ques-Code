/*
链接：https://www.nowcoder.com/practice/98dc82c094e043ccb7e0570e5342dd1b?tpId=37&&tqId=21298&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
来源：牛客网
题目描述
题目标题：
计算两个字符串的最大公共字串的长度，字符不区分大小写
输入描述:
输入两个字符串
输出描述:
输出一个整数
示例1
输入
asdfas werasdfaswer
输出
6
*/
#include <iostream>
#include <string>

using namespace std;

int theLongestSubstr(string s1, string s2)
{
    int max = 0;
    for(int i = 0; i < s1.size(); ++i)
    {
        for(int j = i; j < s1.size(); ++j)
        {
            string tmp = s1.substr(i, j - i);
            int ret = s2.find(tmp);
            if(ret != -1 && max < tmp.size())
                max = tmp.size();
        }
    }
    return max;
}
int main()
{
    string s1, s2;
    while(cin >> s1 >> s2)
    {
        cout << theLongestSubstr(s1, s2) << endl;
    }
    
    return 0;
}