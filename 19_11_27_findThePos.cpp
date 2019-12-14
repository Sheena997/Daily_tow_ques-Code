/*
链接：https://www.nowcoder.com/practice/8ef655edf42d4e08b44be4d777edbf43?tpId=37&&tqId=21276&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
来源：牛客网
题目描述
            1
         1  1  1
      1  2  3  2  1
   1  3  6  7  6  3  1
1  4  10 16 19  16 10  4  1
以上三角形的数阵，第一行只有一个数1，以下每行的每个数，是恰好是它上面的数，左上角数到右上角的数，3个数之和（如果不存在某个数，认为该数就是0）。
求第n行第一个偶数出现的位置。如果没有偶数，则输出-1。例如输入3,则输出2，输入4则输出3。
输入n(n <= 1000000000)
输入描述:
输入一个int整数
输出描述:
输出返回的int值
示例1
输入
4
输出
3
*/
#include <iostream>

using namespace std;

int count_the_num(int n)
{
    if(n < 3)
        return -1;
    if(n % 4 == 0)
        return 3;
    else if(n % 4 == 2)
        return 4;
    else 
        return 2;
}
int main()
{
    int n = 0;
    while(cin >> n)
    {
        int sum = 0;
        sum = count_the_num(n);
        cout << sum << endl;
    }
    
    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n = 0;
    
    while(cin >> n)
    {
        int m = 2*n - 1;
        vector<vector<int>> vv(n, vector<int>(m, 0));
        vv[0][0] = 1;
        for(int i = 1; i < n; ++i)
        {
            vv[i][0] = vv[i][2 * i] = 1;
            for(int j = 1; j < 2 * i; ++j)
            {
                if(1 == j)
                    vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];
                else
                    vv[i][j] = vv[i - 1][j - 2] + vv[i - 1][j - 1] + vv[i - 1][j];
            }
        }
        
        int count = 0;
        int j = 0;
        for(j = 0; j < 2 * n - 1; ++j)
        {
            if(vv[n - 1][j] % 2 == 0 && vv[n - 1][j] != 0)
            {
                count = j + 1;
                break;
            }
        }
        if(j == (2 * n - 1))
            count = -1;
        
        cout << count << endl;
    }
    
    return 0;
}

