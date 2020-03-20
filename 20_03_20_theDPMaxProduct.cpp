/*
链接：https://www.nowcoder.com/questionTerminal/661c49118ca241909add3a11c96408c8
来源：牛客网

有 n 个学生站成一排，每个学生有一个能力值，牛牛想从这 n 个学生中按照顺序选取 k 名学生，
要求相邻两个学生的位置编号的差不超过 d，使得这 k 个学生的能力值的乘积最大，你能返回最大的乘积吗？

输入描述:
每个输入包含 1 个测试用例。每个测试数据的第一行包含一个整数 n (1 <= n <= 50)，
表示学生的个数，接下来的一行，包含 n 个整数，按顺序表示每个学生的能力值 ai（-50 <= ai <= 50）。
接下来的一行包含两个整数，k 和 d (1 <= k <= 10, 1 <= d <= 50)。
输出描述:
输出一行表示最大的乘积。
示例1
输入
3
7 4 7
2 50
输出
49
*/
#include <iostream>
#include <vector>

using namespace std;

long long theMaxProduct(vector<int> stu, int k, int d)
{
    vector<vector<long long>> dp_max(stu.size(), vector<long long>(k + 1, 0));
    vector<vector<long long>> dp_min(stu.size(), vector<long long>(k + 1, 0));
    
    for(int i = 0; i < stu.size(); ++i)
    {
        dp_max[i][1] = stu[i];
        dp_min[i][1] = stu[i];
    }
    
    for(int i = 0; i < stu.size(); ++i)
    {
        for(int j = 2; j <= k; ++j)
        {
            for(int m = max(0, i - d); m <= i - 1; ++m)
            {
                dp_max[i][j] = max(dp_max[i][j], max(dp_max[m][j - 1] * stu[i], dp_min[m][j - 1] * stu[i]));
                dp_min[i][j] = min(dp_min[i][j], min(dp_min[m][j - 1] * stu[i], dp_max[m][j - 1] * stu[i]));
            }
        }
    }
    
    long long res = dp_max[k - 1][k];
    for(int i = k; i < stu.size(); ++i)
        res = max(res, dp_max[i][k]);
    
    return res;
}
int main()
{
    int n = 0;
    while(cin >> n)
    {
        vector<int> stu(n, 0);
        for(int i = 0; i < n; ++i)
            cin >> stu[i];
        int k = 0, d = 0;
        cin >> k >> d;
        
        long long res = theMaxProduct(stu, k, d);
        
        cout << res << endl;
    }
    
    return 0;
}