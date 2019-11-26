/*
链接：https://www.nowcoder.com/practice/0a92c75f5d6b4db28fcfa3e65e5c9b3f?tpId=49&&tqId=29277&rp=1&ru=/activity/oj&qru=/ta/2016test/question-ranking
来源：牛客网
题目描述
扑克牌游戏大家应该都比较熟悉了，一副牌由54张组成，含3~A，2各4张，小王1张，大王1张。牌面从小到大用如下字符和字符串表示（其中，小写joker表示小王，大写JOKER表示大王）:)
3 4 5 6 7 8 9 10 J Q K A 2 joker JOKER
输入两手牌，两手牌之间用“-”连接，每手牌的每张牌以空格分隔，“-”两边没有空格，如：4 4 4 4-joker JOKER
请比较两手牌大小，输出较大的牌，如果不存在比较关系则输出ERROR

基本规则：
（1）输入每手牌可能是个子，对子，顺子（连续5张），三个，炸弹（四个）和对王中的一种，不存在其他情况，由输入保证两手牌都是合法的，顺子已经从小到大排列；
（2）除了炸弹和对王可以和所有牌比较之外，其他类型的牌只能跟相同类型的存在比较关系（如，对子跟对子比较，三个跟三个比较），不考虑拆牌情况（如：将对子拆分成个子）
（3）大小规则跟大家平时了解的常见规则相同，个子，对子，三个比较牌面大小；顺子比较最小牌大小；炸弹大于前面所有的牌，炸弹之间比较牌面大小；对王是最大的牌；
（4）输入的两手牌不会出现相等的情况。

答案提示：
（1）除了炸弹和对王之外，其他必须同类型比较。
（2）输入已经保证合法性，不用检查输入是否是合法的牌。
（3）输入的顺子已经经过从小到大排序，因此不用再排序了.
输入描述:
输入两手牌，两手牌之间用“-”连接，每手牌的每张牌以空格分隔，“-”两边没有空格，如4 4 4 4-joker JOKER。
输出描述:
输出两手牌中较大的那手，不含连接符，扑克牌顺序不变，仍以空格隔开；如果不存在比较关系则输出ERROR。
示例1
输入
4 4 4 4-joker JOKER
输出
joker JOKER
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void the_winner(string s)
{
    string map = "345678910JQKAjokerJOKER";
    /*
    vector<string> v;
    int i = 0;
    while(i < s.size())
    {
        string str;
        while(i < s.size() && s[i] != '-')
        {
            str += s[i];
            ++i;
        }
        if(s[i] == '-' || i == s.size())
            v.push_back(str);
        ++i;
    }
    
    string s1 = v[0];
    string s2 = v[1];
    */
    int dash = s.find('-');
    string s1 = s.substr(0, dash);
    string s2 = s.substr(dash + 1);
    int len1 = count(s1.begin(), s1.end(), ' ') + 1;
    int len2 = count(s2.begin(), s2.end(), ' ') + 1;
    if(len1 != len2)
    {
        if(s1.size() == 7)
            cout << s1 << endl;
        else if(s2.size() == 7)
            cout << s2 << endl;
        else
            cout << "ERROR" << endl;
    }
    else
    {
        string f1 = s1.substr(0, s1.find(' '));
        string f2 = s2.substr(0, s2.find(' '));
        
        if(map.find(f1) > map.find(f2))
            cout << s1 << endl;
        else if(map.find(f1) < map.find(f2))
            cout << s2 << endl;
        else
            cout << "ERROR" << endl;
    }
}
int main()
{
    string s;
    while(getline(cin, s))
    {
        if(s.find("joker JOKER") != -1)
            cout << "joker JOKER" << endl;
        else
            the_winner(s);
    }
    
    return 0;
}