/*
链接：https://www.nowcoder.com/questionTerminal/5973a31d58234b068fa1fe34f7290855
来源：牛客网

NowCoder每天要给许多客户写电子邮件。正如你所知，如果一封邮件中包含多个收件人，收件人姓名之间会用一个逗号和空格隔开；如果收件人姓名也包含空格或逗号，则姓名需要用双引号包含。
现在给你一组收件人姓名，请你帮他生成相应的收件人列表。
输入描述:
输入包含多组数据。
每组数据的第一行是一个整数n (1≤n≤128)，表示后面有n个姓名。
紧接着n行，每一行包含一个收件人的姓名。姓名长度不超过16个字符。
输出描述:
对应每一组输入，输出一行收件人列表。
示例1
输入
3<br/>Joe<br/>Quan, William<br/>Letendre,Bruce<br/>2<br/>Leon<br/>Kewell
输出
Joe, "Quan, William", "Letendre,Bruce"<br/>Leon, Kewell
*/
// write your code here cpp
#include <iostream>

using namespace std;

void getNames(string ret, int n)
{
    for(int i = 0; i < n; ++i)
    {
        int flag = 0;
        getline(cin, ret);
        if(ret.find(',') != string::npos
        || ret.find(' ') != string::npos)
            flag = 1;
        if(flag == 1)
            cout << "\"";
        cout << ret;
        if(flag == 1)
            cout << "\"";
        if(i == n - 1)
            cout << endl;
        else
            cout << ", ";
    }
    
}
int main()
{
    int n = 0;
    while(cin >> n)
    {
        cin.get();
        string ret;
        getNames(ret, n);
        
    }
    
    return 0;
}