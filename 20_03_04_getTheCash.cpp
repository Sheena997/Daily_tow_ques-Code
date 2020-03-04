/*
链接：https://www.nowcoder.com/questionTerminal/754921e9c98b43d1b2d70c227b844101
来源：牛客网
NowCoder在淘宝上开了一家网店。他发现在月份为素数的时候，当月每天能赚1元；否则每天能赚2元。
现在给你一段时间区间，请你帮他计算总收益有多少。
输入描述:
输入包含多组数据。
每组数据包含两个日期from和to (2000-01-01 ≤ from ≤ to ≤ 2999-12-31)。
日期用三个正整数表示，用空格隔开：year month day。
输出描述:
对应每一组数据，输出在给定的日期范围（包含开始和结束日期）内能赚多少钱。
示例1
输入
2000 1 1 2000 1 31<br/>2000 2 1 2000 2 29
输出
62<br/>29
*/
// write your code here cpp
#include <iostream>
#include <vector>
#include <math.h>
 
using namespace std;
 
bool isPrime(int m)
{
    if(m == 1)
        return false;
    if(m == 2)
        return true;
    for(int i = 2; i <= sqrt(m); ++i)
    {
        if(m % i == 0)
            return false;
    }
     
    return true;
}
int getTheCash(int y1, int m1, int d1, int y2, int m2, int d2)
{
    int sum = 0;
    int m[] = {0, 62, 28, 31, 60, 31, 60, 31, 62, 60, 62, 30, 62};
    int n[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(y1 == y2 && m1 == m2)
    {
        int ret = 0;
        if(isPrime(m1))
            ret += d2 - d1 + 1;
        else
            ret += 2 * (d2 - d1 + 1);
        sum = ret;
    }
    else if(y1 == y2 && m1 != m2)
    {
        int ret = 0;
        if((y1 % 4 == 0 && y1 % 100 != 0) || (y1 % 400 == 0))
        {
            if(m1 < 2 && m2 > 2)
                ret += 1;
        }
        else
        {
            for(int i = m1 + 1; i < m2; ++i)
            {
                ret += m[i];
            }
            if(isPrime(m1) && isPrime(m2))
                ret += n[m1] - d1 + 1 + n[m2] - d2 + 1;
            else if(!isPrime(m1) && !isPrime(m2))
                ret += 2 * (n[m1] - d1 + 1 + n[m2] - d2 + 1);
            else if(!isPrime(m1) && isPrime(m2))
                ret += 2 * (n[m1] - d1 + 1) + n[m2] - d2 + 1;
            else
                ret += n[m1] - d1 + 1 + 2 * (n[m2] - d2 + 1);
        }
        sum = ret;
    }
    else
    {
        int ret = 0;
        for(int i = y1 + 1; i < y2; ++i)
        {
            if((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0))
                ret += 580;
            else
                ret += 579;
        }
        for(int i = m1 + 1; i <= 12; ++i)
        {
            if((y1 % 4 == 0 && y1 % 100 != 0) || (y1 % 400 == 0) && i == 2)
                ret += 1;
            ret += m[i];
        }
        if(isPrime(m1))
            ret += n[m1] - d1 + 1;
        else
            ret += 2 * (n[m1] - d1 + 1);
         
        for(int i = 1; i < m2; ++i)
        {
            if((y2 % 4 == 0 && y2 % 100 != 0) || (y2 % 400 == 0) && i == 2)
                ret += 1;
            ret += m[i];
        }
         
        if(isPrime(m2))
            ret += d2;
        else
            ret += 2 * d2;
         
        sum = ret;
    }
     
    return sum;
}
int main()
{
    int y1 = 0, m1 = 0, d1 = 0, y2 = 0, m2 = 0, d2 = 0;
    while(cin >> y1 >> m1 >> d1 >> y2 >> m2 >> d2)
    {
        int sum = getTheCash(y1, m1, d1, y2, m2, d2);
         
        cout << sum << endl;
    }
     
    return 0;
}