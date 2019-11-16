/*
链接：https://www.nowcoder.com/practice/839f681bf36c486fbcc5fcb977ffe432?tpId=85&&tqId=29844&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking
来源：牛客网
题目描述
考拉有n个字符串字符串，任意两个字符串长度都是不同的。考拉最近学习到有两种字符串的排序方法： 1.根据字符串的字典序排序。例如：
"car" < "carriage" < "cats" < "doggies < "koala"
2.根据字符串的长度排序。例如：
"car" < "cats" < "koala" < "doggies" < "carriage"
考拉想知道自己的这些字符串排列顺序是否满足这两种排序方法，考拉要忙着吃树叶，所以需要你来帮忙验证。
输入描述:
输入第一行为字符串个数n(n ≤ 100)
接下来的n行,每行一个字符串,字符串长度均小于100，均由小写字母组成
输出描述:
如果这些字符串是根据字典序排列而不是根据长度排列输出"lexicographically",
如果根据长度排列而不是字典序排列输出"lengths",
如果两种方式都符合输出"both"，否则输出"none"
示例1
输入
3
a
aa
bbb
输出
both
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool is_lengths(vector<string>& s)
{
    for(int i = 0; i < s.size() - 1; ++i)
    {
        if(s[i].size() > s[i + 1].size())
            return false;
    }
    return true;
}
bool is_lexicographically(vector<string>& s)
{
    for(int i = 0; i < s.size() - 1; ++i)
    {
        if(s[i] > s[i + 1])
            return false;
    }
    return true;
}
int main()
{
    int n = 0;
    cin >> n;
    vector<string> s;
    /*
    //方法一：
    s.resize(n);
    for(int i = 0; i < n; ++i)
    {
        cin >>s[i];
    }
    */
    s.resize(n);
    getchar();//吸收cin输入之和的在内存中的一个‘\n’
    for(int i = 0; i < n; ++i)
    {
        getline(cin, s[i]);//如果不吸收‘\n’,getline接收的第一个v[0]就是‘\0’，getline遇到'\n'结束。
    }
    
    if(is_lengths(s) && is_lexicographically(s))
        cout << "both" << endl;
    else if(is_lexicographically(s))
        cout << "lexicographically" << endl;
    else if(is_lengths(s))
        cout << "lengths" << endl;
    else 
        cout << "none" << endl;
    
    return 0;
}