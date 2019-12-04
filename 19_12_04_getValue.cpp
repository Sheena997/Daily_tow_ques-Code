/*
链接：https://www.nowcoder.com/practice/fbcf95ed620f42a88be24eb2cd57ec54?tpId=49&&tqId=29311&rp=1&ru=/activity/oj&qru=/ta/2016test/question-ranking
来源：牛客网
题目描述
春节期间小明使用微信收到很多个红包，非常开心。在查看领取红包记录时发现，某个红包金额出现的次数超过了红包总数的一半。请帮小明找到该红包金额。写出具体算法思路和代码实现，要求算法尽可能高效。
给定一个红包的金额数组gifts及它的大小n，请返回所求红包的金额。
若没有金额超过总数的一半，返回0。
测试样例：
[1,2,3,2,2],5
返回：2
*/
class Gift {
public:
    int getValue(vector<int> gifts, int n) {
        // write code here
        map<int, int> count;
        for(auto e : gifts)
        {
            ++count[e];
            if(count[e] > n / 2)
                return e;
        }
        return 0;
    }
};