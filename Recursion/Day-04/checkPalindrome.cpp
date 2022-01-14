//check if a string is Palindrome or not using recursion

#include <bits/stdc++.h>
using namespace std;

bool checkPalindrome(string str, int start, int end)
{
    //base case
    if (start > end)
    {
        return true;
    }
    if (str[start] != str[end])
    {
        return false;
    }
    else
    {
        //recursive call
        return checkPalindrome(str, start + 1, end - 1);
    }
}

int main()
{
    string str;
    cin >> str;
    int start = 0;
    int end = str.length() - 1;
    bool ans = checkPalindrome(str, start, end);
    if (ans)
    {
        cout << "It's a Palindrome" << endl;
    }
    else
    {
        cout << "It's NOT a Palindrome" << endl;
    }
    return 0;
}