/*
链接：https://www.nowcoder.com/questionTerminal/f72adfe389b84da7a4986bde2a886ec3
来源：牛客网

求字典序在s1和s2之间的，长度在len1到len2的字符串的个数，结果mod 1000007。
输入描述:
每组数据包涵s1（长度小于100），s2（长度小于100），len1（小于100000），len2（大于len1，小于100000）
输出描述:
输出答案。
示例1
输入
ab ce 1 2
输出
56
*/
#include <iostream>
#include <string>
#include <math.h>
#include <vector>

using namespace std;

int main()
{
    string s1, s2;
    int len1 = 0, len2 = 0;
    while(cin >> s1 >> s2 >> len1 >> len2)
    {
        vector<int> v;
        if(s1.size() < len2)
            s1.append(len2 - s1.size(), 'a');
        if(s2.size() < len2)
            s2.append(len2 - s2.size(), 'z' + 1);
        
        for(int i = 0; i < len2; ++i)
            v.push_back(s2[i] - s1[i]);
        int res = 0;
        for(int i = len1; i <= len2; ++i)
        {
            for(int j = 0; j < i; ++j)
                res += v[j] * pow(26, i - j - 1);
        }
        
        cout << (res - 1) % 1000007 << endl;
    }
    
    return 0;
}