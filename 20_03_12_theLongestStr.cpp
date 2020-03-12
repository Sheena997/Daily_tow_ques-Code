/*
链接：https://www.nowcoder.com/questionTerminal/9ae56e5bdf4f480387df781671db5172
来源：牛客网

我们有两个字符串m和n，如果它们的子串a和b内容相同，则称a和b是m和n的公共子序列。子串中的字符不一定在原字符串中连续。
例如字符串“abcfbc”和“abfcab”，其中“abc”同时出现在两个字符串中，因此“abc”是它们的公共子序列。此外，“ab”、“af”等都是它们的字串。
现在给你两个任意字符串（不包含空格），请帮忙计算它们的最长公共子序列的长度。
输入描述:
输入包含多组数据。
每组数据包含两个字符串m和n，它们仅包含字母，并且长度不超过1024。
输出描述:
对应每组输入，输出最长公共子序列的长度。
示例1
输入
abcfbc abfcab<br/>programming contest<br/>abcd mnp
输出
4<br/>2<br/>0
*/
// write your code here cpp
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int theLongestStr(string m, string n)
{
    vector<vector<int>> ret(m.size() + 1, vector<int>(n.size() + 1, 0));
    for(int i = 0; i < m.size(); ++i)
    {
        for(int j = 0; j < n.size(); ++j)
        {
            if(m[i] == n[j])
                ret[i + 1][j + 1] = ret[i][j] + 1;
            else
                ret[i + 1][j + 1] = max(ret[i][j + 1], ret[i + 1][j]);
        }
    }
    
    return ret[m.size()][n.size()];
}
int main()
{
    string m, n;
    while(cin >> m >> n)
    {
        int res = 0;
        res = theLongestStr(m, n);
        
        cout << res << endl;
    }
    
    return 0;
}