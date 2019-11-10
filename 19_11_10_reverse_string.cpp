/*
链接：https://www.nowcoder.com/practice/ee5de2e7c45a46a090c1ced2fdc62355?tpId=85&&tqId=29867&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking
来源：牛客网
题目描述
将一句话的单词进行倒置，标点不倒置。比如 I like beijing. 经过函数后变为：beijing. like I
输入描述:
每个测试输入包含1个测试用例： I like beijing. 输入用例长度不超过100
输出描述:
依次输出倒置之后的字符串,以空格分割
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string s;
    getline(cin, s);
    
    reverse(s.begin(), s.end());
    
    int i = 0;
    int begin = 0;
    int end = 0;
    while(s[i])
    {
        if(s[i] != ' ')
        {
            begin = i;
            while(s[i] && s[i] != ' ')
                ++i;
            --i;
            end = i;
        }
        while(begin < end)
        {
            swap(s[begin], s[end]);
            ++begin;
            --end;
        }
        ++i;
    }
    
    cout << s << endl;
    
    return 0;
}