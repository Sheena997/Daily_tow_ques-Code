/*
链接：https://www.nowcoder.com/practice/5821836e0ec140c1aa29510fd05f45fc?tpId=37&&tqId=21301&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
来源：牛客网
题目描述
请设计一个算法完成两个超长正整数的加法。
输入描述:
输入两个字符串数字
输出描述:
输出相加后的结果，string型
示例1
输入
99999999999999999999999999999999999999999999999999
1
输出
100000000000000000000000000000000000000000000000000
*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string theLongInteger(string s1, string s2)
{
    int i = 0;
    int len = s1.size();
    if(len < s2.size())
        len = s2.size();
    int ret = 0;
    string res;
    while(i < len)
    {
        int a = 0, b = 0;
        if(i < s1.size())
            a = s1[i] - '0';
        else
            a = 0;
        if(i < s2.size())
            b = s2[i] - '0';
        else
            b = 0;
        int sum = ret + a + b;
        ret = sum / 10;
        sum = sum % 10;
        res += (sum + '0');
        ++i;
    }
    if(ret == 1)
        res += '1';
    reverse(res.begin(), res.end());
    
    return res;
}
int main()
{
    string s1, s2;
    
    while(cin >> s1 >> s2)
    {
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());
        string res = theLongInteger(s1, s2);
        
        cout << res << endl;
    }
    
    return 0;
}


#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string theLongInteger(string s1, string s2)
{
    int i = 0;
    int len = s1.size();
    if(len < s2.size())
        len = s2.size();
    int ret = 0;
    string res;
    while(i < len)
    {
        int a = 0, b = 0;
        a = (i < s1.size()) ? (s1[i] - '0') : 0;
        b = (i < s2.size()) ? (s2[i] - '0') : 0;
        int sum = ret + a + b;
        ret = sum / 10;
        res += (sum % 10 + '0');
        ++i;
    }
    if(ret == 1)
        res += '1';
    reverse(res.begin(), res.end());
    
    return res;
}
int main()
{
    string s1, s2;
    
    while(cin >> s1 >> s2)
    {
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());
        string res = theLongInteger(s1, s2);
        
        cout << res << endl;
    }
    
    return 0;
}