/*
链接：https://www.nowcoder.com/practice/3959837097c7413a961a135d7104c314?tpId=37&&tqId=21275&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
来源：牛客网
题目描述
Levenshtein 距离，又称编辑距离，指的是两个字符串之间，由一个转换成另一个所需的最少编辑操作次数。许可的编辑操作包括将一个字符替换成另一个字符，插入一个字符，删除一个字符。编辑距离的算法是首先由俄国科学家Levenshtein提出的，故又叫Levenshtein Distance。
Ex：
字符串A:abcdefg
字符串B: abcdef
通过增加或是删掉字符”g”的方式达到目的。这两种方案都需要一次操作。把这个操作所需要的次数定义为两个字符串的距离。
要求：
给定任意两个字符串，写出一个算法计算它们的编辑距离。
输入描述:
输入两个字符串
输出描述:
得到计算结果
示例1
输入
abcdefg
abcdef
输出
1
*/
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int theDistance(string s1, string s2)
{
    int len1 = s1.size(), len2 = s2.size();
    vector<vector<int>> d(len1 + 1, vector<int>(len2 + 1, 0));
    
    for(int i = 0; i < len1 + 1; ++i)
        d[i][0] = i;
    for(int j = 0; j < len2 + 1; ++j)
        d[0][j] = j;
    
    for(int i = 1; i < len1 + 1; ++i)
    {
        for(int j = 1; j < len2 + 1; ++j)
        {
            if(s1[i - 1] == s2[j - 1])
                d[i][j] = d[i - 1][j - 1];
            else
                d[i][j] = d[i - 1][j - 1] + 1;

            d[i][j] = min(d[i][j], d[i - 1][j] + 1);
            d[i][j] = min(d[i][j], d[i][j - 1] + 1);
        }
    }
    return d[len1][len2];
}

int main()
{
    string s1, s2;
    
    while(cin >> s1 >> s2)
    {
        cout << theDistance(s1, s2) << endl;
    }
    
    return 0;
}