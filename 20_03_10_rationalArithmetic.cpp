/*
链接：https://www.nowcoder.com/questionTerminal/b388bdee5e3e4b1c86a79ad1877a3aa4
来源：牛客网

For two rational numbers, your task is to implement the basic arithmetics, that is, to calculate their sum, difference,
product and quotient.

输入描述:
Each input file contains one test case, which gives in one line the two rational numbers in the format "a1/b1 a2/b2". 
The numerators and the denominators are all in the range of long int. If there is a negative sign, it must appear only in 
front of the numerator. The denominators are guaranteed to be non-zero numbers.

输出描述:
For each test case, print in 4 lines the sum, difference, product and quotient of the two rational numbers, respectively. The format of each 
line is "number1 operator number2 = result". Notice that all the rational numbers must be in their simplest form "k a/b", where k is 
the integer part, and a/b is the simplest fraction part. If the number is negative, it must be included in a pair of parentheses. If the 
denominator in the division is zero, output "Inf" as the result. It is guaranteed that all the output integers are in the range of long int.
示例1
输入
5/3 0/6
输出
1 2/3 + 0 = 1 2/3<br/>1 2/3 - 0 = 1 2/3<br/>1 2/3 * 0 = 0<br/>1 2/3 / 0 = Inf
*/
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int gcd(int mol, int den)
{
    int ret = 0;
    while(den)
    {
        ret = mol % den;
        mol = den;
        den = ret;
    }
    
    return mol;
}
void Print(int mol, int den)
{
    int ret = gcd(mol, den);
    mol = mol / ret;
    den = den / ret;
    long long p = mol * den;
    
    mol = abs(mol);
    den = abs(den);
    
    if(p < 0)
        cout << "(-";
    if(mol == 0)
    {
        cout << "0";
    }
    else if(den == 0)
    {
        cout << "Inf";
    }
    else
    {
        int res = mol / den;
        if(res)
            cout << res;
        int res2 = mol % den;
        if(res2)
        {
            if(res)
                cout << " ";
            printf("%d/%d", res2, den);
        }
    }
    if(p < 0)
        cout << ")";
}
void add(int mol1, int den1, int mol2, int den2)
{
    int sum = mol1 * den2 + mol2 * den1;
    int den = den1 * den2;
    
    Print(mol1, den1);
    cout << " + ";
    Print(mol2, den2);
    cout << " = ";
    Print(sum, den);
    printf("\n");
}
void sub(int mol1, int den1, int mol2, int den2)
{
    int sum = mol1 * den2 - mol2 * den1;
    int den = den1 * den2;
    
    Print(mol1, den1);
    cout << " - ";
    Print(mol2, den2);
    cout << " = ";
    Print(sum, den);
    printf("\n");
}
void mul(int mol1, int den1, int mol2, int den2)
{
    int mol = mol1 * mol2;
    int den = den1 * den2;
    
    Print(mol1, den1);
    cout << " * ";
    Print(mol2, den2);
    cout << " = ";
    Print(mol, den);
    printf("\n");;
}
void div(int mol1, int den1, int mol2, int den2)
{
    int mol = mol1 * den2;
    int den = mol2 * den1;
    
    Print(mol1, den1);
    cout << " / ";
    Print(mol2, den2);
    cout << " = ";
    Print(mol, den);
    printf("\n");
}
int main()
{
    int mol1 = 0, mol2 = 0, den1 = 0, den2 = 0;
    scanf("%d/%d %d/%d", &mol1, &den1, &mol2, &den2);
    
    add(mol1, den1, mol2, den2);
    sub(mol1, den1, mol2, den2);
    mul(mol1, den1, mol2, den2);
    div(mol1, den1, mol2, den2);
    
    return 0;
}