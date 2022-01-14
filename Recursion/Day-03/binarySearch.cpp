#include <bits/stdc++.h>
using namespace std;

int binarySearch(int *arr, int s, int e, int k)
{
    if (s > e)
    {
        return -1;
    }

    int mid = s + (e - s) / 2;
    if (arr[mid] == k)
    {
        return mid;
    }
    if (arr[mid] < k)
    {
        return binarySearch(arr, mid + 1, e, k);
    }
    else
    {
        return binarySearch(arr, s, mid - 1, k);
    }
}

int main()
{
    int arr[5] = {1, 3, 5, 6, 7};
    int size = 5;
    int key = 9;

    cout << binarySearch(arr, 0, 4, key);

    return 0;
}
