/*
链接：https://www.nowcoder.com/questionTerminal/81544a4989df4109b33c2d65037c5836
来源：牛客网

对字符串中的所有单词进行倒排。
说明：
1、每个单词是以26个大写或小写英文字母构成；
2、非构成单词的字符均视为单词间隔符；
3、要求倒排后的单词间隔符以一个空格表示；如果原字符串中相邻单词间有多个间隔符时，倒排转换后也只允许出现一个空格间隔符；
4、每个单词最长20个字母；

输入描述:
输入一行以空格来分隔的句子
输出描述:
输出句子的逆序
示例1
输入
I am a student
输出
student a am I
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> reverseString(string str)
{
	int i = 0;
	vector<string> res;
    res.clear();
	while (i < str.size())
	{
		string ret = "";
		while (i < str.size() && str[i] != ' ' && isalpha(str[i]))
		{
			ret += str[i];
			++i;
        }
		if (ret.size() > 0)
		{
			reverse(ret.begin(), ret.end());
			res.push_back(ret);
			ret = "";
		}
		++i;
	}

	return res;
}
int main()
{
	string str = "";
    while(getline(cin, str))
    {
        reverse(str.begin(), str.end());
		vector<string> res = reverseString(str);

		for(int i = 0; i <= res.size() - 2; ++i)
            cout << res[i] << ' ';
        cout << res[res.size() - 1] << endl;
    }
	return 0;
}