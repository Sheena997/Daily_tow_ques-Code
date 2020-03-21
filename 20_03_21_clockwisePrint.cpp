/*
链接：https://www.nowcoder.com/questionTerminal/97e7a475d2a84eacb60ee545597a8407
来源：牛客网

对于一个矩阵，请设计一个算法从左上角(mat[0][0])开始，顺时针打印矩阵元素。
给定int矩阵mat,以及它的维数nxm，请返回一个数组，数组中的元素为矩阵元素的顺时针输出。
测试样例：
[[1,2],[3,4]],2,2
返回：[1,2,4,3]
*/
class Printer {
public:
    vector<int> clockwisePrint(vector<vector<int> > mat, int n, int m) {
        // write code heret
        vector<int> res;
        int x1 = 0, y1 = 0, x2 = n - 1, y2 = m - 1;
        while(x1 <= x2 && y1 <= y2)
        {
            for(int i = y1; i <= y2; ++i)
                res.push_back(mat[x1][i]);
            for(int i = x1 + 1; i < x2; ++i)
                res.push_back(mat[i][y2]);
            for(int i = y2; i >= y1 && x1 < x2; --i)
                res.push_back(mat[x2][i]);
            for(int i = x2 - 1; i > x1 && y1 < y2; --i)
                res.push_back(mat[i][y1]);
            ++x1;
            ++y1;
            --x2;
            --y2;
        }
        
        return res;
    }
};