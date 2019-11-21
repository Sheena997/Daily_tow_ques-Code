/*
链接：https://www.nowcoder.com/practice/f8538f9ae3f1484fb137789dec6eedb9?tpId=37&&tqId=21283&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
来源：牛客网
题目描述
任意一个偶数（大于2）都可以由2个素数组成，组成偶数的2个素数有很多种情况，本题目要求输出组成指定偶数的两个素数差值最小的素数对
输入描述:
输入一个偶数
输出描述:
输出两个素数
示例1
输入
20
输出
7
13
*/
#include <iostream>
#include <math.h>

using namespace std;

bool is_prime(int n)
{
    for(int i = 2; i < n; ++i)
    {
        if(n % i == 0)
            return false;
    }
    return true;
}
int main()
{
    int n = 0;
    while(cin >> n)
    {
        int min1 = 0;
        int min2 = 0;
        int min = 0;
        for(int i = 1; i < n; i += 2)
        {
            int ret = 0;
            for(int j = i; j < n; j += 2)
            {
                if(is_prime(i) && is_prime(j) && (i + j) == n)
                { 
                    ret = abs(i - j);
                    if(min == 0 || min > ret)
                    {
                         min = ret;
                         min1 = i;
                         min2 = j;
                    }
                }
            }
        }
        cout << min1 << endl;
        cout << min2 << endl;
    }

    return 0;
}

//方法二 ：通过循环遍历来判断一个数 是否为素数。
//最近的两个素数应该从最中间的位置开始向两边查找
#include <iostream>
#include <math.h>

using namespace std;

bool is_prime(int n)
{
    int tmp = sqrt(n);
    for(int i = 2; i <= tmp; ++i)
    {
        if(n % i == 0)
            return false;
    }
    return true;
}
int main()
{
    int n = 0;
    while(cin >> n)
    {
        int i = 0;
        int half = n / 2;
        for(i = half; i > 0; --i)
        {
            if(is_prime(i) && is_prime(n - i))
                break;
        }
        cout << i << endl << n - i << endl;
    }

    return 0;
}