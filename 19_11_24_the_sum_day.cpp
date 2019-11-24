/*
链接：https://www.nowcoder.com/practice/769d45d455fe40b385ba32f97e7bcded?tpId=37&&tqId=21296&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
来源：牛客网
题目描述
根据输入的日期，计算是这一年的第几天。。
详细描述：
输入某年某月某日，判断这一天是这一年的第几天？。
输入描述:
输入三行，分别是年，月，日
输出描述:
成功:返回outDay输出计算后的第几天;
失败:返回-1
示例1
输入
2012
12
31
输出
366
*/
#include <iostream>

using namespace std;

int the_sum_day(int y, int m, int d)
{
    int month_day[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int sum = 0;
    sum += d;
    for(int i = 1; i < m; ++i)
    {
        sum += month_day[i];
    }
    if((m > 2) && ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0))
    {
        sum += 1;
    }
    return sum;
}
int main()
{
    int year = 0, month = 0, day = 0;
    
    while(cin >> year >> month >> day)
    {
        int sum = 0;
        
        sum = the_sum_day(year, month, day);
        
        cout << sum << endl;
    }
    
    return 0;
}


/*
链接：https://www.nowcoder.com/practice/a5190a7c3ec045ce9273beebdfe029ee?tpId=85&&tqId=29839&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking
来源：牛客网
题目描述
一个袋子里面有n个球，每个球上面都有一个号码(拥有相同号码的球是无区别的)。如果一个袋子是幸运的当且仅当所有球的号码的和大于所有球的号码的积。
例如：如果袋子里面的球的号码是{1, 1, 2, 3}，这个袋子就是幸运的，因为1 + 1 + 2 + 3 > 1 * 1 * 2 * 3
你可以适当从袋子里移除一些球(可以移除0个,但是别移除完)，要使移除后的袋子是幸运的。现在让你编程计算一下你可以获得的多少种不同的幸运的袋子。
输入描述:
第一行输入一个正整数n(n ≤ 1000)
第二行为n个数正整数xi(xi ≤ 1000)
输出描述:
输出可以产生的幸运的袋子数
示例1
输入
3
1 1 1
输出
2
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int means = 0;
void the_lucky_bag(vector<int> v, int pos, int sum, int multi)
{
    for(int i = pos; i < v.size(); ++i)
    {
        sum += v[i];
        multi *= v[i];

        if(sum > multi)
        {
            the_lucky_bag(v, i + 1, sum, multi);
            ++means;
        }
        else if(v[i] == 1)
        {
            the_lucky_bag(v, i + 1, sum, multi);
        }
        else
        {
            break;
        }
        sum -= v[i];
        multi /= v[i];
        while(v[i] == v[i + 1] && i + 1 < v.size())
        {
            ++i;
        }
    }
}
int main()
{
    int n = 0;
    cin >> n;
    vector<int> v(n, 0);
    for(int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    
    the_lucky_bag(v, 0, 0, 1);
    
    cout << means << endl;
    
    return 0;
}
