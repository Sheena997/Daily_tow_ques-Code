/*
链接：https://www.nowcoder.com/questionTerminal/11cc498832db489786f8a03c3b67d02c
来源：牛客网

输入两个整数 n 和 m，从数列1，2，3.......n 中随意取几个数,使其和等于 m ,要求将其中所有的可能组合列出来
输入描述:
每个测试输入包含2个整数,n和m
输出描述:
按每个组合的字典序排列输出,每行输出一种组合
示例1
输入
5 5
输出
1 4<br/>2 3<br/>5
*/
#include <iostream>
#include <vector>

using namespace std;

void dfs(int n, int m, vector<int>& v, int ret)
{
    if(m == 0)
    {
        for(int i = 0; i < v.size(); ++i)
            cout << v[i] << " ";
        cout << endl;
    }
    for(int i = ret; i <= n && i <= m; ++i)
    {
        v.push_back(i);
        dfs(n, m - i, v, i + 1);
        v.pop_back();
    }
}
int main()
{
    int n = 0, m = 0;
    while(cin >> n >> m)
    {
        vector<int> v;
        dfs(n, m, v, 1);
    }
    
    return 0;
}