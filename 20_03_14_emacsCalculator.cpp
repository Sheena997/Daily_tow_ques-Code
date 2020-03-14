/*
链接：https://www.nowcoder.com/questionTerminal/1a92fbc771a54feb9eb5bd9b3ff2d0a9
来源：牛客网

Emacs号称神的编辑器，它自带了一个计算器。与其他计算器不同，它是基于后缀表达式的，即运算符在操作数的后面。例如“2 3 +”等价于中缀表达式的“2 + 3”。
请你实现一个后缀表达式的计算器。
输入描述:
输入包含多组数据。
每组数据包括两行：第一行是一个正整数n (3≤n≤50)；紧接着第二行包含n个由数值和运算符组成的列表。
“+-*//*分别为加减乘除四则运算，其中除法为整除，即“5/3=1”。
输出描述:
对应每一组数据，输出它们的运算结果。
示例1
输入
3<br/>2 3 +<br/>5<br/>2 2 + 3 *<br/>5<br/>2 2 3 + *
输出
5<br/>12<br/>10
*/

// write your code here cpp
#include <iostream>
#include <stack>

using namespace std;

void emacsCalculator(string s, stack<int>& st)
{
    if(s[0] >= '0' && s[0] <= '9')
    {
        int num = 0;
        for(int i = 0; i < s.size(); ++i)
        {
            num = num * 10 + (s[i] - '0');
        }
        st.push(num);
    }
    else
    {
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();
        if(s == "+")
            st.push(b + a);
        else if(s == "-")
            st.push(b - a);
        else if(s == "*")
            st.push(b * a);
        else if(s == "/")
            st.push(b / a);
    }

}
int main()
{
    int n = 0;
    stack<int> st;
    while(cin >> n)
    {
        int res = 0;
        for(int i = 0; i < n; ++i)
        {
            string s;
            cin >> s;
            emacsCalculator(s, st);
        }
        
        cout << st.top() << endl;
    }
    
    return 0;
}



