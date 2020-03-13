/*
链接：https://www.nowcoder.com/questionTerminal/d83721575bd4418eae76c916483493de
来源：牛客网

广场上站着一支队伍，她们是来自全国各地的扭秧歌代表队，现在有她们的身高数据，请你
帮忙找出身高依次递增的子序列。 例如队伍的身高数据是（1、7、3、5、9、4、8），其中
  依次递增的子序列有（1、7），（1、3、5、9），（1、3、4、8）等，其中最长的长度为4。
输入描述:
输入包含多组数据，每组数据第一行包含一个正整数n（1≤n≤1000）。
紧接着第二行包含n个正整数m（1≤n≤10000），代表队伍中每位队员的身高。
输出描述:
对应每一组数据，输出最长递增子序列的长度。
示例1
输入
7<br/>1 7 3 5 9 4 8<br/>6<br/>1 3 5 2 4 6
输出
4<br/>4
*/
// write your code here cpp
#include <iostream>
#include <vector>

using namespace std;

int theLongestSubString(vector<int> v)
{
    int res = 1;
    vector<int> le(v.size(), 1);
    for(int i = 1; i < v.size() ; ++i)
    {
        for(int j = 0; j < i; ++j)
        {
            if(v[i] > v[j])
                le[i] = max(le[i], le[j] + 1);
        }
        
        res = max(res, le[i]);
    }
    
    return res;
}
int main()
{
    int n = 0;
    while(cin >> n)
    {
        vector<int> v(n, 0);
        for(int i = 0; i < n; ++i)
            cin >> v[i];
        
        int res = 0;
        res = theLongestSubString(v);
        
        cout << res << endl;
    }
    
    return 0;
}