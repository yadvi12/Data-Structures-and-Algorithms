// Question Link - https://bit.ly/3GiCqY0

bool isPossible(vector<int> time, long long n, long long m, long long mid)
{
    long long daysCount = 1;
    long long totaltime = 0;
    for(long long i = 0; i < m; i++)
    {
        if(totaltime + time[i] <= mid)
        {
            totaltime += time[i];
        }
        else
        {
            daysCount++;
            if(daysCount > n || time[i] > mid)
            {
                return false;
            }
            totaltime = time[i];
        }
    }
    return true;
}
long long ayushGivesNinjatest(long long n, long long m, vector<int> time) 
{	
    long long sum = 0;
	for(long long i = 0; i < m; i++)
    {
        sum += time[i];
    }
    long long start = 0;
    long long end = sum;
    long long ans = -1;
    while(start <= end)
    {
        long long mid = start + (end - start)/2;
        if(isPossible(time, n, m, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}
