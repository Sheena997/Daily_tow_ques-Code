/*
链接：https://www.nowcoder.com/questionTerminal/71d3849a19f04a1591c415964ac148f1
来源：牛客网

一只成熟的兔子每天能产下一胎兔子。每只小兔子的成熟期是一天。 某人领养了一只小兔子，
请问第N天以后，他将会得到多少只兔子。
输入描述:
测试数据包括多组，每组一行，为整数n(1≤n≤90)。
输出描述:
对应输出第n天有几只兔子(假设没有兔子死亡现象)。
示例1
输入
1<br/>2
输出
1<br/>2
*/
// write your code here cpp
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n = 0;
    vector<long> v(90);
    v[1] = 1;
    v[2] = 2;
    for(int i = 3; i <= 90; ++i)
        v[i] = v[i - 1] + v[i - 2];
    while(cin >> n)
    {
        cout << v[n] << endl;
    }
    
    return 0;
}