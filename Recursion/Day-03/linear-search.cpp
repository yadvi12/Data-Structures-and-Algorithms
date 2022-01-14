#include <bits/stdc++.h>
using namespace std;

int index = -1;

int linearSearch(int arr[], int size, int key)
{
    //base case
    if (size == 0)
        return -1;

    if (arr[0] == key)
        return index + 1;

    else
    {
        index++;
        //recurrence relation
        linearSearch(arr + 1, size - 1, key);
    }
}

int main()
{
    int arr[6] = {3, 5, 1, 2, 6, 56};
    int size = 6;
    int key;
    cin >> key;

    int position = linearSearch(arr, size, key);
    cout << position << endl;
    return 0;
}