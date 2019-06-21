#include<bits/stdc++.h>
using namespace std;

int dp[10005][105];
int a[10005], n, k;

int f(int pos, int sum)
{
    bool flag = false;

    sum = ((sum%k) + k)%k;

    if(pos>=n)
    {
        return (sum == 0);
    }

    if(dp[pos][sum] != -1) return dp[pos][sum];

    flag = flag | f(pos+1, sum+a[pos]);
    flag = flag | f(pos+1, sum-a[pos]);

    return dp[pos][sum] = flag;
}

int main()
{

    int test;

    scanf("%d", &test);

    while(test--)
    {

        scanf("%d %d", &n, &k);

        for(int i = 0; i<n; i++) scanf("%d", &a[i]);

        memset(dp, -1, sizeof(dp));

        if(f(1, a[0])) puts("Divisible");
        else puts("Not divisible");

    }

	return 0;
}
