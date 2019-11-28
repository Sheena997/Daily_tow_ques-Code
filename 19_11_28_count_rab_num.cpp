/*
链接：https://www.nowcoder.com/practice/1221ec77125d4370833fd3ad5ba72395?tpId=37&&tqId=21260&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
来源：牛客网
有一只兔子，从出生后第3个月起每个月都生一只兔子，小兔子长到第三个月后每个月又生一只兔子，假如兔子都不死，问每个月的兔子总数为多少？
输入描述:
输入int型表示month
输出描述:
输出兔子总数int型
示例1 
输入
9
输出
34
*/
#include <iostream>
using namespace std;
int count_rab_num(int month) 
{
    if(month < 3)    
		return 1;  
	return count_rab_num(month - 1) + count_rab_num(month - 2); 
}
int main()
{
    int month = 0;       
	while(cin >> month)    
	{  
		int rab = 0;             
		rab = count_rab_num(month);       
		cout << rab << endl;  
    }  
	return 0;	
}