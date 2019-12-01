/*
链接：https://www.nowcoder.com/practice/e45e078701ab4e4cb49393ae30f1bb04?tpId=37&&tqId=21235&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
来源：牛客网
题目描述
写出一个程序，接受一个字符串，然后输出该字符串反转后的字符串。例如：
输入描述:
输入N个字符
输出描述:
输出该字符串反转后的字符串
示例1
输入
abcd
输出
dcba
*/
#include <iostream>
#include <string>

using namespace std;

void reverseString(string& s)
{
    int left = 0, right = s.size() - 1;
    while(left < right)
    {
        swap(s[left], s[right]);
        ++left;
        --right;
    }
}
int main()
{
    string s;
    while(cin >> s)
    {
        if(s.empty())
		{
			cout << s << endl;
		}
		else
		{
			reverseString(s);
			cout << s << endl;
		}
    }
    
    return 0;
}
/*
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string s;
    while(cin >> s)
    {
        reverse(s.begin(), s.end());
        cout << s << endl; 
    }
    
    return 0;
}
*/

