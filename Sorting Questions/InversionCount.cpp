#include <bits/stdc++.h>
using namespace std;

long long merge(int *arr, int start, int end)
{
    long long inv = 0;
    int mid = start + (end - start) / 2;
    int len1 = mid - start + 1;
    int len2 = end - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    int mainArrayIndex = start;
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[mainArrayIndex++];
    }
    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[mainArrayIndex++];
    }

    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = start;

    while (index1 < len1 && index2 < len2)
    {
        if (first[index1] < second[index2])
        {
            arr[mainArrayIndex++] = first[index1++];
        }
        else
        {
            arr[mainArrayIndex++] = second[index2++];
            inv += len1 - index1;
        }
    }

    while (index1 < len1)
    {
        arr[mainArrayIndex++] = first[index1++];
    }
    while (index2 < len2)
    {
        arr[mainArrayIndex++] = second[index2++];
    }

    delete[] first;
    delete[] second;
    return inv;
}

long long mergeSort(int arr[], int start, int end)
{
    long long inv = 0;
    if (start >= end)
    {
        return inv;
    }
    int mid = start + (end - start) / 2;
    inv += mergeSort(arr, start, mid);
    inv += mergeSort(arr, mid + 1, end);
    inv += merge(arr, start, end);
    return inv;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int start = 0;
    int end = n - 1;

    long long ans = mergeSort(arr, start, end);

    cout << endl;
    cout << ans << endl;
    return 0;
}
