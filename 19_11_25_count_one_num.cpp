/*
链接：nowcoder.com/practice/1b46eb4cf3fa49b9965ac3c2c1caf5ad?tpId=37&&tqId=21285&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
来源：牛客网
输入描述:
输入一个整数
输出描述:
计算整数二进制中1的个数
示例1
输入
5
输出
2
*/
#include <iostream>

using namespace std;

int count_one_num(int n)
{
    int count = 0;
    while(n)
    {
        if(n & 1 == 1)
            ++count;
        n = n >> 1;
    }
    return count;
}
int main()
{
    int n = 0;
    
    while(cin >> n)
    {
        int sum = 0;
        sum = count_one_num(n);
        cout << sum << endl;
    }
    
    return 0;
}
