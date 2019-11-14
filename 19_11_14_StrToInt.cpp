/*
链接：https://www.nowcoder.com/practice/1277c681251b4372bdef344468e4f26e?tpId=13&&tqId=11202&rp=6&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking
来源：牛客网
题目描述
将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0
输入描述:
输入一个字符串,包括数字字母符号,可以为空
输出描述:
如果是合法的数值表达则返回该数字，否则返回0
示例1
输入
+2147483647
    1a33
输出
2147483647
    0
*/
class Solution {
public:
    int StrToInt(string str) {
        if(str.empty())
            return 0; 
        long sum = 0;
        int flag = 0;
        int i = 0;
        if(str[0] == '+' || str[0] == '-')
            ++i;
        while(str[i])
        {
            if(str[i] < '0' || str[i] > '9')
            {
                sum = 0;
                break;
            }
            sum = sum * 10 + (str[i] - '0');
            ++i;
        }
        if(str[0] == '-')
            sum = (-sum);
        if(sum > 2147483647 || sum < (-2147483648))
            sum = 0;
        return sum;
    }
};