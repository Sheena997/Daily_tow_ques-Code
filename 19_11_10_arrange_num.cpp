/*
链接：https://www.nowcoder.com/questionTerminal/2d3f6ddd82da445d804c95db22dcc471?orderByHotValue=1&page=1&onlyReference=false
来源：牛客网

牛牛定义排序子序列为一个数组中一段连续的子序列,并且这段子序列是非递增或者非递减排序的。牛牛有一个长度为n的整数数组A,他现在有一个任务是把数组A分为若干段排序子序列,牛牛想知道他最少可以把这个数组分为几段排序子序列.
如样例所示,牛牛可以把数组A划分为[1,2,3]和[2,2,1]两个排序子序列,至少需要划分为2个排序子序列,所以输出2
输入描述:
输入的第一行为一个正整数n(1 ≤ n ≤ 10^5)
第二行包括n个整数A_i(1 ≤ A_i ≤ 10^9),表示数组A的每个数字。
输出描述:
输出一个整数表示牛牛可以将A最少划分为多少段排序子序列
*/
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    vector<int> v(n, 0);
    for(int i = 0; i < v.size(); ++i)
    {
        cin >> v[i];
    }
    
    int i = 0;
    int count = 0;
    while(i < n)
    {
        if(v[i] < v[i + 1])
        {
            while(i < n && v[i] < v[i + 1])
            {
                ++i;
            }
            ++count;
            ++i;
        }
        else if(v[i] == v[i + 1])
        {
            ++i;
        }
        else
        {
            while(i < n && v[i] > v[i + 1])
            {
                ++i; 
            }
            ++count;
            ++i;
        }
    }
    cout << count << endl;
    return 0;
}