/*
链接：https://www.nowcoder.com/practice/e2a22f0305eb4f2f9846e7d644dba09b?tpId=37&&tqId=21314&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
来源：牛客网
题目描述
请编写一个函数（允许增加子函数），计算n x m的棋盘格子（n为横向的格子数，m为竖向的格子数）沿着各自边缘线从左上角走到右下角，总共有多少种走法，要求不能走回头路，即：只能往右和往下走，不能往左和往上走。
输入描述:
输入两个正整数
输出描述:
返回结果
示例1
输入
2
2
输出
6
*/
#include <iostream>

using namespace std;

int sum_step(int n, int m)
{
    if(m == 0 || n == 0)
        return 0;
    else if((n >= 1 && m == 1) || (n == 1 && m >= 1))
        return m + n;
    else 
        return sum_step(n - 1, m) + sum_step(n, m - 1);
}
int main()
{
    int m = 0, n = 0;
    while(cin >> n >> m)
    {
        int step = 0;
        step = sum_step(n , m);

        cout << step << endl;
    }
    return 0;
}