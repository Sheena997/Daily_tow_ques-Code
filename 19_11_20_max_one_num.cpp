/*
链接：https://www.nowcoder.com/practice/4b1658fd8ffb4217bc3b7e85a38cfaf2?tpId=37&&tqId=21309&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
来源：牛客网
题目描述
功能: 求一个byte数字对应的二进制数字中1的最大连续数，例如3的二进制为00000011，最大连续2个1
输入: 一个byte型的数字
输出: 无
返回: 对应的二进制数字中1的最大连续数
输入描述:
输入一个byte数字
输出描述:
输出转成二进制之后连续1的个数
示例1
输入
3
输出
2
*/
#include <iostream>

using namespace std;

int max_one_num(int n)
{
    int sum = 0;
    int max = 0;
   /* while(n)
    {
        if(n & 1 == 1)
        {
            ++sum;
            if(max < sum)
                max = sum;
        }
        else
        {
            sum = 0;
        }
        n = n >> 1;
    }
    */
    while(n)
    {
        sum = 0;
        while(n && (n & 1 == 1))
        {
            ++sum;
            n >>= 1;
        }
        if(max < sum)
            max = sum;
        n >>= 1;
    }
    return max;
}
int main()
{
    int n = 0;
    int max = 0;
    
    while(cin >> n)
    {
        max = max_one_num(n);
        cout << max << endl;
    }
    
    return 0;
}