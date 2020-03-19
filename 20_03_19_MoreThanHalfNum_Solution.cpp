/*
链接：https://www.nowcoder.com/questionTerminal/e8a1b01a2df14cb2b228b30ee6a92163
来源：牛客网

[编程题]数组中出现次数超过一半的数字

数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9
的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输
出2。如果不存在则输出0。
*/
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
       if(numbers.empty())
           return 0;
        int count = 0, mid = numbers.size() / 2;
        sort(numbers.begin(), numbers.end());
        
        for(int i = 0; i < numbers.size(); ++i)
        {
            if(numbers[mid] == numbers[i])
                ++count;
        }
        
        return (count > mid) ? numbers[mid] : 0;
    }
};