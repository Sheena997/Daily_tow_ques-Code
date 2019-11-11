/*
链接：https://www.nowcoder.com/practice/bd891093881d4ddf9e56e7cc8416562d?tpId=85&&tqId=29864&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking
来源：牛客网
题目描述
读入一个字符串str，输出字符串str中的连续最长的数字串
输入描述:
个测试输入包含1个测试用例，一个字符串str，长度不超过255。
输出描述:
在一行内输出str中里连续最长的数字串。
示例1
输入
复制
abcd12345ed125ss123456789
输出
复制
123456789
*/
#include <iostream>
#include <string>

using namespace std;

string the_long_string(string& s)
{
    string res;
    int max = 0;
    int i = 0;
    while(i < s.size())
    {
        string ret;
        int sum = 0;
        while(i < s.size() && s[i] >= '0' && s[i] <= '9')
        {
            ret += s[i];
            ++sum;
            ++i;
        }
        if(max < sum)
        {
            max = sum;
            res = ret;
        } 
        else
            ret.clear();
        ++i;
    }
    return res;
}
int main()
{
    string str;
    getline(cin, str);
    string res;
    
    res = the_long_string(str);
    
    cout << res;
    
    return 0;
}