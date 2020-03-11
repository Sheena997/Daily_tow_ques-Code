/*
链接：https://www.nowcoder.com/questionTerminal/ed9bc679ea1248f9a3d86d0a55c0be10
来源：牛客网

现在有两个好友A和B，住在一片长有蘑菇的由n＊m个方格组成的草地，A在(1,1),B在(n,m)。现在A想要拜访B，由于她
只想去B的家，所以每次她只会走(i,j+1)或(i+1,j)这样的路线，在草地上有k个蘑菇种在格子里(多个蘑菇可能在同一
方格),问：A如果每一步随机选择的话(若她在边界上，则只有一种选择)，那么她不碰到蘑菇走到B的家的概率是多少？
输入描述:
第一行N，M，K(1 ≤ N,M ≤ 20, k ≤ 100),N,M为草地大小，接下来K行，每行两个整数x，y，代表(x,y)处有一个蘑菇。
输出描述:
输出一行，代表所求概率(保留到2位小数)
示例1
输入
2 2 1<br/>2 1<br/>
输出
0.50
*/
#include <iostream>
#include <vector>

using namespace std;

void mushroom(vector<vector<float>>& ret, int n, int m)
{
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {
            if(i == 1 && j == 1)
            {
                ret[i][j] = 1;
            }
            else if(ret[i][j] != -1)
            {
                if(i != n && j != m)
                    ret[i][j] = ret[i - 1][j] * 0.5 + ret[i][j - 1] * 0.5;
                if(i == n && j != m)
                    ret[i][j] = ret[i - 1][j] * 0.5 + ret[i][j - 1];
                if(i != n && j == m)
                    ret[i][j] = ret[i - 1][j] + ret[i][j - 1] * 0.5;
                if(i == n && j == m) 
                    ret[i][j] = ret[i - 1][j] + ret[i][j - 1];
            }
            else
            {
                ret[i][j] = 0;
            }
        }
    }
}
int main()
{
    int n = 0, m = 0, k = 0;
    while(cin >> n >> m >> k)
    {
        vector<vector<float>> ret(n + 1, vector<float>(m+ 1, 0));
        int x = 0, y = 0;
        for(int i = 0; i < k; ++i)
        {
            cin >> x >> y;
            ret[x][y] = -1;
        }
        
        mushroom(ret, n, m);
        
        printf("%.2f\n", ret[n][m]);
    }
    
    return 0;
}