#include <bits/stdc++.h>
using namespace std;

// INSERTION SORT ALGORITHM USING RECURSION
void insertionSort(int arr[], int n, int start)
{
    // BASE CASE
    if (start == n)
    {
        return;
    }

    // PROCESSING
    int j = start - 1;
    int key = arr[start];
    while (j >= 0 && arr[j] > key)
    {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = key;

    // RECURSIVE CALL
    insertionSort(arr, n, start + 1);
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
    int start = 1;
    insertionSort(arr, n, start);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}