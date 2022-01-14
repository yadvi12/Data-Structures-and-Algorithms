//the task is to reverse the string given in the input using recursion
#include <bits/stdc++.h>
using namespace std;

void reverseString(string &str, int start, int end)
{
    //base case
    if (start > end)
    {
        return;
    }
    else
    {
        swap(str[start], str[end]);
        start++;
        end--;
        //recursive call
        reverseString(str, start, end);
    }
}

int main()
{
    string str;
    cin >> str;
    int start = 0;
    int end = str.size() - 1;
    reverseString(str, start, end);
    cout << str;
    return 0;
}