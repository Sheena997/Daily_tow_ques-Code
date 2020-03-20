/*
链接：https://www.nowcoder.com/questionTerminal/2baa6aba39214d6ea91a2e03dff3fbeb
来源：牛客网

开发一个简单错误记录功能小模块，能够记录出错的代码所在的文件名称和行号。
处理：
1、 记录最多8条错误记录，循环记录（或者说最后只输出最后出现的八条错误记录），对相同的错误记录（净文件名称和行号完全匹配）只记录一条，错误计数增加；
2、 超过16个字符的文件名称，只记录文件的最后有效16个字符；
3、 输入的文件可能带路径，记录文件名称不能带路径。
输入描述:
一行或多行字符串。每行包括带路径文件名称，行号，以空格隔开。
输出描述:
将所有的记录统计并将结果输出，格式：文件名 代码行数 数目，一个空格隔开，如：
示例1
输入
E:\V1R2\product\fpgadrive.c   1325
输出
fpgadrive.c 1325 1
*/
#include <iostream>
#include <string>
#include <vector>
 
using namespace std;

string copy(string str, int begin, int end)
{
    string s;
    for(int i = begin; i <= end; ++i)
        s += str[i];
    return s;
}
int main()
{
    string str, row;
    vector<string> note;
    vector<int> count;
    while(cin >> str >> row)
    {
        int index = 0;
        for(int i = 0; i < str.size(); ++i)
            if(str[i] == '\\')
                index = i + 1;
        if(str.size() - index > 16)
            index = str.size() - 16;
        string tmp = copy(str, index, str.size() - 1);
        tmp = tmp + ' ' + row;
        
        int notesize = note.size(), flag = 1;
        for(int i = 0; i < notesize; ++i)
        {
            if(tmp == note[i])
            {
                ++count[i];
                flag = 0;
                break;
            }
        }
        if(flag)
        {
            note.push_back(tmp);
            count.push_back(1);
        }
    }
    
    int l = note.size(), start = 0;
    if(l > 8)
        start = l - 8;
    for(int i = start; i < l; ++i)
        cout << note[i] << ' ' << count[i] << endl;
    
    return 0;
}