/*
链接；https://www.nowcoder.com/practice/18ecd0ecf5ef4fe9ba3f17f8d00d2d66?tpId=85&&tqId=29846&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking
来源：牛客网
题目描述
Fibonacci数列是这样定义的：
F[0] = 0
F[1] = 1
for each i ≥ 2: F[i] = F[i-1] + F[i-2]
因此，Fibonacci数列就形如：0, 1, 1, 2, 3, 5, 8, 13, ...，在Fibonacci数列中的数我们称为Fibonacci数。给你一个N，你想让其变为一个Fibonacci数，每一步你可以把当前数字X变为X-1或者X+1，现在给你一个数N求最少需要多少步可以变为Fibonacci数。
输入描述:
输入为一个正整数N(1 ≤ N ≤ 1,000,000)
输出描述:
输出一个最小的步数变为Fibonacci数"
示例1
输入
15
输出
2
*/
#include <iostream>

using namespace std;

int the_least_steps(int n)
{
    int f1 = 0;
    int f2 = 0;
    int f3 = 1;
    while(n > f3)
    {
        f1 = f2;
        f2 = f3;
        f3 = f1 + f2;
    }
    return (n - f2) < (f3 - n) ? (n - f2) : (f3 - n);
}
int main()
{
    int n = 0;
    cin >> n;
    int step = 0;
    
    step = the_least_steps(n);
    
    cout << step << endl;
    
    return 0;
}
