/*
链接：https://www.nowcoder.com/questionTerminal/5017fd2fc5c84f78bbaed4777996213a
来源：牛客网

有一间长方形的房子，地上铺了红色、黑色两种颜色的正方形瓷砖。你站在其中一块黑色的瓷砖上，只能向相邻的（上下左右四个方向）
黑色瓷砖移动。请写一个程序，计算你总共能够到达多少块黑色的瓷砖。
输入描述:
输入包含多组数据。
每组数据第一行是两个整数 m 和 n（1≤m, n≤20）。紧接着 m 行，每行包括 n 个字符。每个字符表示一块瓷砖的颜色，规则如下：
1. “.”：黑色的瓷砖；
2. “#”：白色的瓷砖；
3. “@”：黑色的瓷砖，并且你站在这块瓷砖上。该字符在每个数据集合中唯一出现一次。
输出描述:
对应每组数据，输出总共能够到达多少块黑色的瓷砖。
示例1
输入
9 6<br/>....#.<br/>.....#<br/>......<br/>......<br/>......<br/>......<br/>......<br/>#@...#<br/>.#..#.
输出
45
*/
// write your code here cpp
#include <iostream>
#include <vector>

using namespace std;

void redAndBlack(vector<vector<char>>& v, int x, int y, int m, int n, int& res)
{
    if(x < 0 || y < 0 || x >= m || y >= n || v[x][y] == '1' || v[x][y] == '#')
        return;
    ++res;
    v[x][y] = '1';
    
    redAndBlack(v, x - 1, y, m, n, res);
    redAndBlack(v, x, y - 1, m, n, res);
    redAndBlack(v, x + 1, y, m, n, res);
    redAndBlack(v, x, y + 1, m, n, res);
}
int main()
{
    int m = 0, n = 0;
    while(cin >> m >> n)
    {
        vector<vector<char>> v(m, vector<char>(n));
        int x = 0, y = 0, res = 0;
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                cin >> v[i][j];
                if(v[i][j] == '@')
                {
                    x = i;
                    y = j;
                }
            }
        }
        redAndBlack(v, x, y, m, n, res);
        
        cout << res << endl;
    }
    
    return 0;
}