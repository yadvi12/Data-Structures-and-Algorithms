// Question Link - https://www.codingninjas.com/codestudio/contests/love-babbar-contest-l/problems/14463

int findMaxX(int n, vector<vector<int>> &arr, int B)
{
   int maximum = 0;
   for (int i = 0 ; i < n ; i++)
    {
        for (int j = 1 ; j <= arr[i][0] ; j++)
        {
            maximum = max(maximum, arr[i][j]);
        }
    }
    
    int start = 0;
    int end = maximum;
    int ans = 0;
    while(start <= end)
    {
       int mid = start + (end - start)/2;
       int totalCandies = 0;
       for(int i = 0; i < n; i++)
       {
           for(int j = 1; j <= arr[i][0]; j++)
           {
               if(arr[i][j] <= mid){
                   totalCandies += arr[i][j];
               }
           }
       }
       if(totalCandies <= B){
           ans = mid;
           start = mid + 1;
       }
       else
       {
           end = mid - 1;
       }
    }
    return ans;
}
