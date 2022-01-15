#include <bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int start, int end)
{
    int minimum = INT_MAX;
    int minIndex = -1;

    // BASE CASE
    if (start == end)
    {
        return;
    }

    // PROCESSING
    for (int i = start; i <= end; i++)
    {
        if (arr[i] < minimum)
        {
            minimum = arr[i];
            minIndex = i;
        }
    }
    swap(arr[minIndex], arr[start]);
    start++;

    //RECURRENCE RELATION
    selectionSort(arr, start, end);
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
    selectionSort(arr, start, end);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}