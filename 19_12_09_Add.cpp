/*
链接：https://www.nowcoder.com/questionTerminal/59ac416b4b944300b617d4f7f111b215
来源：牛客网
写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号.
*/
class Solution {
public:
    int Add(int num1, int num2)
    {
        while(num2)
        {
            int sum = num1 ^ num2;
            int seat = (num1 & num2) << 1;
            num1 = sum;
            num2 = seat;
        }
        
        return num1;
    }
};