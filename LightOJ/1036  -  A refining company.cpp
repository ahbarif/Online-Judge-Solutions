#include<bits/stdc++.h>
using namespace std;
 
const int sz = 505;
 
int dp[sz][sz], a[sz][sz], b[sz][sz];
 
int f(int i, int j)
{
    if(i<0 || j<0)  return 0;
 
    int &ret = dp[i][j];
 
    if(ret != -1) return ret;
 
    int x = a[i][j] + f(i-1, j);
    int y = b[i][j] + f(i, j-1);
 
    ret = max(x, y);
 
    return ret;
 
}
 
int main()
{
 
    int test, cs = 0;
 
    scanf("%d", &test);
 
    while(test--)
    {
        int n, m;
 
        memset(dp, -1, sizeof(dp));
 
        scanf("%d %d", &n, &m);
 
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<m; j++)
            {
                scanf("%d", &a[i][j]);
 
                if(j)   a[i][j] += a[i][j-1];
 
            }
        }
 
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<m; j++)
            {
                scanf("%d", &b[i][j]);
 
                if(i)   b[i][j] += b[i-1][j];
 
            }
        }
 
        int res = f(n-1, m-1);
 
        printf("Case %d: %d\n", ++cs, res);
 
    }
    return 0;
}
 
