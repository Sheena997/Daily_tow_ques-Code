/*
链接：https://www.nowcoder.com/practice/e896d0f82f1246a3aa7b232ce38029d4?tpId=37&&tqId=21282&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
来源：牛客网
题目描述
找出字符串中第一个只出现一次的字符
输入描述:
输入一个非空字符串
输出描述:
输出第一个只出现一次的字符，如果不存在输出-1
示例1
输入
asdfasdfo
输出
o
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int theFirstOnly(string s)
{
    vector<int> count(256, 0);
    for(auto& e : s)
    {
        ++count[e];
    }
    for(int i = 0; i < s.size(); ++i)
    {
        if(count[s[i]] == 1)
            return i;
    }
    return -1;
}
int main()
{
    string s;
    while(cin >> s)
    {
        int res = 0;
        res = theFirstOnly(s);
        
        if(-1 == res)
            cout << "-1" << endl;
        else
            cout << s[res] << endl;
    }
    
    return 0;
}
