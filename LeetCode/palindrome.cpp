#include <iostream>
using namespace std;

bool check_palindrome(int num)
{
    int re_num = 0;
    if(num/10 == 0)
        return true;
    while(num != 0)
    {
        if(re_num == num)
            return true;
        re_num = re_num*10 + num%10;
        if(re_num == num)
            return true;
        num = num/10; 
    }
    return false;
}


int main()
{
    int num;
    cout<<"enter a number"<<endl;
    cin>>num;
    if(check_palindrome(num))
        cout<<"The number is A Palindrome"<<endl;
    else
        cout<<"The number is NOT Palindrome"<<endl;
    return 0;
}