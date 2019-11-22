/*
链接:https://www.nowcoder.com/practice/4284c8f466814870bae7799a07d49ec8?tpId=85&&tqId=29852&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking
来源：牛客网
题目描述
小易来到了一条石板路前，每块石板上从1挨着编号为：1、2、3.......
这条石板路要根据特殊的规则才能前进：对于小易当前所在的编号为K的 石板，小易单次只能往前跳K的一个约数(不含1和K)步，即跳到K+X(X为K的一个非1和本身的约数)的位置。 小易当前处在编号为N的石板，他想跳到编号恰好为M的石板去，小易想知道最少需要跳跃几次可以到达。
例如：
N = 4，M = 24：
4->6->8->12->18->24
于是小易最少需要跳跃5次，就可以从4号石板跳到24号石板
输入描述:
输入为一行，有两个整数N，M，以空格隔开。 (4 ≤ N ≤ 100000) (N ≤ M ≤ 100000)
输出描述:
输出小易最少需要跳跃的步数,如果不能到达输出-1
示例1
输入
4 24
输出
5
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> get_factor(int n)
{
    vector<int> f;
    for(int i = 2; i <= sqrt(n); ++i)
    {
        if(n % i == 0)
        {
            f.push_back(i);
            if(n / i != i)
                f.push_back(n / i);
        }
    }
    
    return f;
}
int count_step(int n, int m)
{
    vector<int> res(m + 1, 0);
    res[n] = 1;
    for(int i = n; i <= m; ++i)
    {
        if(res[i] == 0)
            continue;
        vector<int> fac;
        fac = get_factor(i);
        for(int j = 0; j < fac.size(); ++j)
        {
            if(fac[j] + i <= m && res[fac[j] + i] != 0)
                res[fac[j] + i] = min(res[fac[j] + i], res[i] + 1);
            else if(fac[j] + i <= m)
                res[fac[j] + i] = res[i] + 1;
        }
    }
    if(res[m] == 0)
        return -1;
    else
        return (res[m] - 1);
}
int main()
{
    int n = 0, m = 0;
    while(cin >> n >> m)
    {
        int sum = 0;
        sum = count_step(n ,m);
        
        cout << sum << endl;
    }
    
    return 0;
}

