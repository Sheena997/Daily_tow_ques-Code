/*
链接：https://www.nowcoder.com/questionTerminal/a811535fed784ea492b63622c28c75c5
来源：牛客网

NowCoder最近爱上了五子棋，现在给你一个棋局，请你帮忙判断其中有没有五子连珠（超过五颗也算）。
输入描述:
输入有多组数据，每组数据为一张20x20的棋盘。
其中黑子用“*”表示，白子用“+”表示，空白位置用“.”表示。
输出描述:
如果棋盘上存在五子连珠（无论哪种颜色的棋子），输入“Yes”，否则输出“No”。
示例1
输入
....................<br/>....................<br/>....................<br/>....................<br/>......*.............<br/>.......*............<br/>........*...........<br/>....++++.*..........<br/>..........*.........<br/>....................<br/>....................<br/>....................<br/>....................<br/>....................<br/>....................<br/>....................<br/>....................<br/>....................<br/>....................<br/>....................<br/>....................<br/>....................<br/>....................<br/>.......*............<br/>......+*+++.........<br/>.......*............<br/>.......*............<br/>....................<br/>....................<br/>....................<br/>....................<br/>....................<br/>....................<br/>....................<br/>....................<br/>....................<br/>....................<br/>....................<br/>....................<br/>....................
输出
Yes<br/>No
*/
#include <iostream>
#include <string>

using namespace std;

bool theGobang(string str[])
{
    for(int i = 0; i < 20; ++i)
    {
        for(int j = 0; j < 20; ++j)
        {
            if(str[i][j] == '.')
                continue;
            int right = 1, down = 1, right_down = 1, left_down = 1;
            for(int k = 1; k < 5; ++k)
            {
                if(j < 16 && str[i][j] == str[i][j + k])
                    ++right;
                if(i < 16 && str[i][j] == str[i + k][j])
                    ++down;
                if(i < 16 && j > 3 && str[i][j] == str[i + k][j -k])
                    ++left_down;
                if(i < 16 && j < 16 && str[i][j] == str[i + k][j + k])
                    ++right_down;
            }
            if(right == 5 || down == 5 || right_down == 5 || left_down == 5)
                return true;
        }
    }
    
    return false;
}
int main()
{
    string str[20];
    while(cin >> str[0])
    {
        for(int i = 1; i < 20; ++i)
            cin >> str[i];
        
        cout << (theGobang(str) ? "Yes" : "No") << endl;
    }
    
    return 0;
}


