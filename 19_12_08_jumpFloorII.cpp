/*
链接：https://www.nowcoder.com/questionTerminal/22243d016f6b47f2a6928b4313c85387
来源：牛客网
一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。
求该青蛙跳上一个n级的台阶总共有多少种跳法。
*/
class Solution {
public:
    int jumpFloorII(int number) {
        /*return pow(2, (number - 1)); */
        return 1 << (number - 1);
    }
};