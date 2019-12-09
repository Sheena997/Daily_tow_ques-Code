/*
链接：https://www.nowcoder.com/questionTerminal/c67a09062c0f4a5b964eef0945d3dd06
来源：牛客网
给定三条边，请你判断一下能不能组成一个三角形。
输入描述:
输入包含多组数据，每组数据包含三个正整数a、b、c（1≤a, b, c≤10^100）。
输出描述:
对应每一组数据，如果它们能组成一个三角形，则输出“Yes”；否则，输出“No”。
示例1
输入
1 2 3
2 2 2
输出
No
Yes
*/
#include <iostream>

using namespace std;

int main()
{
    double a, b, c;
    while(cin >> a >> b >> c)
    {
        if(a + b > c && a + c > b && b + c > a)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}

//更好的方法：
#include <iostream>

using namespace std;

#define ADD(x, y) ((x) + (y))
#define CMP(x, y) ((x) > (y))

int main()
{
    double a, b, c;
    while(cin >> a >> b >> c)
    {
        if(CMP(ADD(a,b), c) && CMP(ADD(b, c), a) && CMP(ADD(a, c), b))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}