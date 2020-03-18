/*
链接：https://www.nowcoder.com/questionTerminal/bb4f1a23dbb84fd7b77be1fbe9eaaf32
来源：牛客网

nowcoder有两盒（A、B）乒乓球，有红双喜的、有亚力亚的……现在他需要判别A盒是否包含了
B盒中所有的种类，并且每种球的数量不少于B盒中的数量，该怎么办呢？
输入描述:
输入有多组数据。
每组数据包含两个字符串A、B，代表A盒与B盒中的乒乓球，每个乒乓球用一个大写字母表示，
即相同类型的乒乓球为相同的大写字母。
字符串长度不大于10000。
输出描述:
每一组输入对应一行输出：如果B盒中所有球的类型在A中都有，并且每种球的数量都不大于A，
则输出“Yes”；否则输出“No”。
示例1
输入
ABCDFYE CDE
ABCDGEAS CDECDE
输出
Yes
No
*/
// write your code here cpp
#include <iostream>
#include <vector>

using namespace std;

bool isIncluded(string A, string B)
{
    vector<int> v1(26, 0), v2(26, 0);
    for(int i = 0; i < A.size(); ++i)
        ++v1[A[i] - 'A'];
    for(int i = 0; i < B.size(); ++i)
        ++v2[B[i] - 'A'];
    
    for(int i = 0; i < v1.size(); ++i)
    {
        if(v1[i] != 0)
        {
            if(v1[i] < v2[i])
                return false;
        }
        else if(v1[i] != 0 || v2[i] != 0)
        {
            return false;
        }
    }
    
    return true;
}
int main()
{
    string A, B;
    while(cin >> A >> B)
    {
        if(isIncluded(A, B))
            cout << "Yes" << endl;
        else 
            cout << "No" << endl;
        
    }
    
    return 0;
}