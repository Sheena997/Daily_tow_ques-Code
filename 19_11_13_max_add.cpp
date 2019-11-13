/*
链接：https://www.nowcoder.com/practice/5a304c109a544aef9b583dce23f5f5db?tpId=85&&tqId=29858&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking
来源：牛客网
题目描述
一个数组有 N 个元素，求连续子数组的最大和。 例如：[-1,2,1]，和最大的连续子数组为[2,1]，其和为 3
输入描述:
输入为两行。 第一行一个整数n(1 <= n <= 100000)，表示一共有n个元素 第二行为n个数，即每个元素,每个整数都在32位int范围内。以空格分隔。
输出描述:
所有连续子数组中和最大的值。
示例1
输入
3 -1 2 1
输出
3
*/
#include <iostream>
#include <vector>

using namespace std;

int max_add(vector<int>& v)
{
    int max = v[0];
    int sum = 0;
    for(int i = 0; i < v.size(); ++i)
    {
        sum += v[i];
        if(sum > max)
            max = sum;
        if(sum < 0)
            sum = 0;
    }
    return max;
}
int main()
{
    int n = 0;
    cin >> n;
    vector<int> v(n, 0);
    for(int i = 0; i < v.size(); ++i)
    {
        cin >> v[i];
    }
    
    int sum = max_add(v);
    
    cout << sum << endl;
    
    return 0;
}