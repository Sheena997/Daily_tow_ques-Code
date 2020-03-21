/*
链接：https://www.nowcoder.com/questionTerminal/f5805cc389394cf69d89b29c0430ff27
来源：牛客网

给定一个长度为N(N>1)的整型数组A，可以将A划分成左右两个部分，左部分A[0..K]，
右部分A[K+1..N-1]，K可以取值的范围是[0,N-2]。求这么多划分方案中，左部分中的
最大值减去右部分最大值的绝对值，最大是多少？
给定整数数组A和数组的大小n，请返回题目所求的答案。
测试样例：
[2,7,3,1,1],5
返回：6
*/
class MaxGap {
public:
    int findMaxGap(vector<int> A, int n) {
        // write code here
        int max = A[0], pos = 0;
        for(int i = 1; i < n; ++i)
        {
            if(max < A[i])
            {
                max = A[i];
                pos = i;
            }
        }
        if(pos == n - 1)
            return A[n - 1] - A[0];
        if(pos == 0)
            return A[0] - A[n - 1];
        return (A[pos] - A[n - 1]) > (A[pos] - A[0]) ? (A[pos] - A[n - 1]) : (A[pos] - A[0]);
    }
};