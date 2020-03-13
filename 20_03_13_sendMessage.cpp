/*
链接：https://www.nowcoder.com/questionTerminal/95e35e7f6ad34821bc2958e37c08918b
来源：牛客网

NowCoder每天要给很多人发邮件。有一天他发现发错了邮件，把发给A的邮件发给了B，把发给B的邮件发给了A。于是他就思考，要给n个人发邮件，在每个人仅收到1封邮件的情况下，有多少种情况是所有人都收到了错误的邮件？
即没有人收到属于自己的邮件。
输入描述:
输入包含多组数据，每组数据包含一个正整数n（2≤n≤20）。
输出描述:
对应每一组数据，输出一个正整数，表示无人收到自己邮件的种数。
示例1
输入
2<br/>3
输出
1<br/>2
*/
// write your code here cpp
#include <iostream>

using namespace std; 

long long sendMessage(int n)
{
    if(n < 2)
        return 0;
    if(n == 2)
        return 1;
    if(n == 3)
        return 2;
    
    return (n - 1) * (sendMessage(n - 1) + sendMessage(n - 2));
}
int main()
{
    int n = 0;
    while(cin >> n)
    {
        long long res = 0;
        res = sendMessage(n);
        
        cout << res << endl;
    }
    
    return 0;
}