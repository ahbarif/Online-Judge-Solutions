#include <bits/stdc++.h>
using namespace std;

#define     debug(x)    cerr << #x " = " << (x) << endl

int mask, len;

long long dp[33][33][3][3];

long long f(int i, int cnt, int pre, int isEqual)
{
    if(i<0) return cnt;

    if(dp[i][cnt][pre][isEqual] != -1) return dp[i][cnt][pre][isEqual];

    long long res = f(i-1, cnt, 0, isEqual && !(mask&(1<<i)));

    if((mask & (1<<i)) && isEqual)
    {
        res = res + f(i-1, cnt+(pre==1), 1, isEqual && (mask&(1<<i)));
    }

    return dp[i][cnt][pre][isEqual] = res;

}

int main()
{

    int n = 5;

    int test, cs = 0;

    scanf("%d", &test);

    while(test--)
    {
        scanf("%d", &mask);

        for(int i = 31; i>=0; i--)
        {
            if(mask&(1<<i))
            {
                len = i;
                break;
            }
        }

        memset(dp, -1, sizeof(dp));

        printf("Case %d: %lld\n", ++cs, f(len, 0, 0, true));
    }


}
