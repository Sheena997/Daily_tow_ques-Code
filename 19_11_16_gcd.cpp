/*
链接：https://www.nowcoder.com/practice/22948c2cad484e0291350abad86136c3?tpId=37&&tqId=21331&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
来源：牛客网
题目描述
正整数A和正整数B 的最小公倍数是指 能被A和B整除的最小的正整数值，设计一个算法，求输入A和B的最小公倍数。
输入描述:
输入两个正整数A和B。
输出描述:
输出A和B的最小公倍数。
示例1
输入
5 7
输出
35
*/
#include <iostream>
#include <algorithm>

using namespace std;
/*方法一：穷举法
int main()
{
    int a = 0, b = 0;
    cin >> a >> b;
    if(a < b)
        swap(a, b);
    int i = a;
    while(i >= a)
    {
        if(i % a == 0 && i % b == 0)
            break;
        ++i;
    }
    
    cout << i << endl;
    
    return 0;
}
*/
int gcd(int a, int b)
{
    //该函数是求的为最大公约数为b
    int ret = 0;//穷举法
    while(ret = a % b)
    {
        a = b;
        b = ret;
    }
    return b;
}
int main()
{
    int a = 0, b = 0; 
    while(cin >> a >> b)
    
    cout << (a * b) / gcd(a, b) << endl;
    
    return 0;
}