/*
来源牛客
链接：https://www.nowcoder.com/practice/f0db4c36573d459cae44ac90b90c6212?tpId=85&&tqId=29868&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking
输入两个字符串，从第一字符串中删除第二个字符串中所有的字符。例如，输入”They are students.”和”aeiou”，则删除之后的第一个字符串变成”Thy r stdnts.”
输入描述:
每个测试输入包含2个字符串
输出描述:
输出删除后的字符串
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string delete_the_same(string &s1, string &s2)
{
    string res = "";
    vector<int> hash(256, 0);
    for(int i = 0; i < s2.size(); ++i)
    {
        ++hash[s2[i]];
    }
    for(int i = 0; i < s1.size(); ++i)
    {
        if(hash[s1[i]] == 0)
            res += s1[i];
    }
    return res;
}
int main()
{
    string s1 = "";
    string s2 = "";
    
    getline(cin, s1);
    getline(cin, s2);
    
    cout << delete_the_same(s1, s2) << endl;
    return 0;
}