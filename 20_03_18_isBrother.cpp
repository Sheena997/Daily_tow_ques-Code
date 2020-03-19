/*
链接：https://www.nowcoder.com/questionTerminal/03ba8aeeef73400ca7a37a5f3370fe68
来源：牛客网

输入描述:
先输入字典中单词的个数，再输入n个单词作为字典单词。
输入一个单词，查找其在字典中兄弟单词的个数
再输入数字n
输出描述:
根据输入，输出查找到的兄弟单词的个数
示例1
输入
3 
abc bca cab abc 
1
输出
2
bca
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isBrother(string str, string s)
{
    if(str.size() == s.size())
    {
        if(str == s)
            return false;
        sort(str.begin(), str.end());
        sort(s.begin(), s.end());
        if(str == s)
            return true;
    }
    
    return false;
}
int main()
{
    int n = 0;
    while(cin >> n)
    {
        string str, word, s;
        int index = 0;
        vector<string> v;
        for(int i = 0; i < n; ++i)
        {
            cin >> str;
            v.push_back(str);
        }
        
        sort(v.begin(), v.end());
        cin >> word;
        cin >> index;
        int count = 0;
        
        for(int i = 0; i < n; ++i)
        {
            if(isBrother(word, v[i]))
            {
                ++count;
                if(count == index)
                    s = v[i];
            }
        }
        if(!v.empty())
            cout << count << endl;
        if(count >= index)
            cout << s << endl;
    }
    
    
    return 0;
}