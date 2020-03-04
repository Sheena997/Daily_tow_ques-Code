/*
链接：https://www.nowcoder.com/questionTerminal/c0a4b917a15f40a49ca10532ab9019fb
来源：牛客网
NowCoder号称自己已经记住了1-100000之间所有的斐波那契数。
为了考验他，我们随便出一个数n，让他说出第n个斐波那契数。
当然，斐波那契数会很大。因此，如果第n个斐波那契数不到6位，则说出该数；否则只说出最后6位。
输入描述:
输入有多组数据。
每组数据一行，包含一个整数n (1≤n≤100000)。
输出描述:
对应每一组输入，输出第n个斐波那契数的最后6位。
示例1
输入
1<br/>2<br/>3<br/>4<br/>100000
输出
1<br/>2<br/>3<br/>5<br/>537501

setfill和setw的使用
*/
// write your code here cpp
#include <iostream>
#include <vector>
#include <iomanip>
 
using namespace std;
 
int main()
{
    int n = 0;
    vector<int> v(100001);
    v[0] = 1;
    v[1] = 1;
    for(int i = 2; i < 100002; ++i)
    {
        v[i] = v[i - 1] + v[i - 2];
        if(v[i] / 1000000 > 0)
            v[i] %= 1000000;
    }
    while(cin >> n)
    {
        int res = 0;
        res = v[n];
        if(n >= 31)
            cout << setfill('0') << setw(6) << res << endl;
        else
            cout << res << endl;
    }
     
    return 0;
}