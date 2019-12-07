/*
链接：https://www.nowcoder.com/questionTerminal/e2422543519249f292d8435394ab82fe
来源：牛客网
数根可以通过把一个数的各个位上的数字加起来得到。如果得到的数是一位数，那么这个数就是数根；如果结果是两位数或者包括更多位的数字，那么再把这些数字加起来。如此进行下去，直到得到是一位数为止。
比如，对于24 来说，把2 和4 相加得到6，由于6 是一位数，因此6 是24 的数根。
再比如39，把3 和9 加起来得到12，由于12 不是一位数，因此还得把1 和2 加起来，最后得到3，这是一个一位数，因此3 是39 的数根。
现在给你一个正整数，输出它的数根。
输入描述:
输入包含多组数据。
每组数据数据包含一个正整数n（1≤n≤10E1000）。
输出描述:
对应每一组数据，输出该正整数的数根。
示例1
输入
24
39
输出
6
3
*/
// write your code here cpp
#include <iostream>

using namespace std;

int theNumRoot(int n)
{
    /*//递归
    int sum = 0;
    while(n)
    {
        sum += n % 10;
        n /= 10;
    }
    if(sum < 10)
        return sum;
    return theNumRoot(sum);
    */
    //非递归
    int sum = n;
    while(sum > 9)
    {
        n = sum;
        sum = 0;
        while(n)
        {
            sum += n % 10;
            n /= 10;
        }
    }
    return sum;
}
int main()
{
    string n;
    while(cin >> n)
    {
        int ret = 0;
        for(auto& e : n)
            ret += e - '0';
        if(ret < 10)
            cout << ret << endl;
        else
            cout << theNumRoot(ret) << endl;
    }
    
    return 0;
}