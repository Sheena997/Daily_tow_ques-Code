/*
链接：https://www.nowcoder.com/practice/52d382c2a7164767bca2064c1c9d5361?tpId=37&&tqId=21310&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
来源：牛客网
题目描述
密码按如下规则进行计分，并根据不同的得分为密码进行安全等级划分。
       一、密码长度:
       5 分: 小于等于4 个字符
       10 分: 5 到7 字符
       25 分: 大于等于8 个字符
       二、字母:
       0 分: 没有字母
       10 分: 全都是小（大）写字母
       20 分: 大小写混合字母
       三、数字:
       0 分: 没有数字
       10 分: 1 个数字
       20 分: 大于1 个数字
       四、符号:
       0 分: 没有符号
       10 分: 1 个符号
       25 分: 大于1 个符号
       五、奖励:
       2 分: 字母和数字
       3 分: 字母、数字和符号
       5 分: 大小写字母、数字和符号
       最后的评分标准:
       >= 90: 非常安全
       >= 80: 安全（Secure）
       >= 70: 非常强
       >= 60: 强（Strong）
       >= 50: 一般（Average）
       >= 25: 弱（Weak）
       >= 0:  非常弱
 
对应输出为：
  VERY_WEAK,
   WEAK,    
   AVERAGE,    
   STRONG,     
   VERY_STRONG,
   SECURE,     
   VERY_SECURE 


       请根据输入的密码字符串，进行安全评定。
       注：
       字母：a-z, A-Z
       数字：-9
       符号包含如下： (ASCII码表可以在UltraEdit的菜单view->ASCII Table查看)
       !"#$%&'()*+,-./     (ASCII码：x21~0x2F)
       :;<=>?@             (ASCII<=><=><=><=><=>码：x3A~0x40)
       [\]^_`              (ASCII码：x5B~0x60)
  {|}~                (ASCII码：x7B~0x7E)
 
输入描述:
输入一个string的密码
输出描述:
输出密码等级
示例1 
输入
38$@NoNoNo
输出
VERY_SECURE

*/

#include <iostream>
#include <string>

using namespace std;

int sum_length(string& s) 
{
    if(s.size() <= 4)   
        return 5; 
    else if(s.size() > 5 && s.size() < 7)       
        return 10;    
    else if(s.size() >= 8)    
        return 25; 
} 
int sum_words(string& s) 
{
    int sum_b = 0;  
    int sum_s = 0; 
    for(int i = 0; i < s.size(); ++i)
    {    
        if(s[i] >= 'a' && s[i] <= 'z')    
            ++sum_b;  
        else if(s[i] >= 'A' && s[i] <= 'Z')     
            ++sum_s;
    } 
    if(sum_b == 0 && sum_s == 0)    
        return 0; 
    else if(sum_b == s.size() || sum_s == s.size())     
        return 10; 
    else if(sum_b + sum_s == s.size()) 
        return 20; 
}
int sum_number(string& s)
{    
    int sum = 0; 
    for(int i = 0; i < s.size(); ++i)  
    {        
        if(s[i] >= '0' && s[i] <= '9')    
            ++sum;
    }   
    if(sum == 0)     
        return 0;   
    else if(sum == 1) 
        return 10;  
    else if(sum > 1)    
        return 20;
}
int sum_signal(string& s) 
{
    int sum = 0;    
    for(int i = 0; i < s.size(); ++i) 
    {
        if(!(s[i] >= 'a' && s[i] <= 'z')   
           && !(s[i] >= 'A' && s[i] <= 'Z')    
           && !(s[i] >= '0' && s[i] <= '9'))    
            ++sum;   
    }
    if(sum == 0)     
        return 0;   
    else if(sum == 1)        
        return 10;  
    else if(sum > 1) 
        return 25;
} 

int main() 
{
    string passw;
    while(cin >> passw)    
    { 
        int sum_len = 0, sum_word = 0, sum_num = 0, sum_sig = 0, sum_ex = 0, sum = 0;
        sum_len = sum_length(passw);   
        sum_word = sum_words(passw);   
        sum_num = sum_number(passw);      
        sum_sig = sum_signal(passw);
        if(sum_word == 20 && sum_num > 0 && sum_sig > 0)      
            sum_ex = 5;   
        else if(sum_word > 0 && sum_num > 0 && sum_sig > 0)     
            sum_ex = 3;  
        else if(sum_word > 0 && sum_num > 0)      
            sum_ex = 2;
        sum = sum_len + sum_word + sum_num + sum_sig + sum_ex;     
        if(sum >= 90)
            cout << "VERY_SECURE" << endl;      
        else if(sum >= 80)          
            cout << "SECURE" << endl;    
        else if(sum >= 70)       
            cout << "VERY_STRONG" << endl;    
        else if(sum >= 60)      
            cout << "STRONG" << endl;     
        else if(sum >= 50)
            cout << "AVERAGE" << endl;  
        else if(sum >= 25)  
            cout << "WEAK" << endl;     
        else if(sum >=0)        
            cout << "VERY_WEAK" << endl;
    }

    return 0; 
}