#include <bits/stdc++.h>
using namespace std;

bool isSorted(int arr[], int size)
{
    if (size == 0 | size == 1)
    {
        return true;
    }

    if (arr[0] > arr[1])
    {
        return false;
    }
    else
    {
        bool remaining = isSorted(arr + 1, size - 1);
        return remaining;
    }
}

int main()
{
    int arr[] = {2, 4, 6, 8, 7};
    int size = 5;

    bool ans = isSorted(arr, size);

    if (ans)
    {
        cout << "Array is sorted";
    }
    else
    {
        cout << "Array is NOT sorted";
    }

    return 0;
}