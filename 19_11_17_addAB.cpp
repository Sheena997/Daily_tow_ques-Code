/*
链接：https://www.nowcoder.com/practice/e7e0d226f1e84ba7ab8b28efc6e1aebc?tpId=8&&tqId=11065&rp=1&ru=/activity/oj&qru=/ta/cracking-the-coding-interview/question-ranking
来源：牛客网
题目描述
请编写一个函数，将两个数字相加。不得使用+或其他算数运算符。
给定两个int A和B。请返回A＋B的值
测试样例：
1,2
返回：3
*/
class UnusualAdd {
public:
    int addAB(int A, int B) {
        // write code here
        while(B)
        {
            unsigned int sum = A ^ B;
            auto carry = ((unsigned int) (A & B) << 1);
            B = carry;
            A = sum;
        }
        return A;
    }
};