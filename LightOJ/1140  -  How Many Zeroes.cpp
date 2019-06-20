#include<bits/stdc++.h>
using namespace std;
 
string ToString (long long n)
{
    ostringstream ss;
    ss << n;
    return ss.str();
}
 
string s;
 
long long dp[15][15][3][3];
 
long long f(int i, int cnt, int isequal, int isStart)
{
 
    if(i>=s.length())   return cnt;
 
    if(dp[i][cnt][isequal][isStart] != -1)  return dp[i][cnt][isequal][isStart];
 
    long long res = 0;
 
    int j = (isequal?s[i]-48:9);
 
    for(int k = 0; k<=j; k++)
    {
 
        res += f(i+1, cnt + (k==0 && isStart), isequal&(k==j), isStart|k>0);
 
    }
 
    return dp[i][cnt][isequal][isStart] = res;
 
 
}
 
int main()
{
 
    int test, cs = 0;
 
    scanf("%d", &test);
 
    while(test--)
    {
        long long a, b;
 
        memset(dp, -1, sizeof(dp));
 
        scanf("%lld %lld", &a, &b);
 
        s = ToString(a-1);
 
        long long res1 = f(0, 0, 1, 0);
 
        s = ToString(b);
 
        memset(dp, -1, sizeof(dp));
 
        long long res2 = f(0, 0, 1, 0);
 
        if(a==0)    ++res2, res1 = 0;
 
        printf("Case %d: %lld\n", ++cs,  res2 - res1);
    }
 
    return 0;
 
}
 