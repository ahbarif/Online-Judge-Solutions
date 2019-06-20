#include<bits/stdc++.h>
using namespace std;
 
double dp[105][105];
 
void Warshall(int n)
{
    for(int k = 0; k<n; k++)
    {
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<n; j++)
            {
                dp[i][j] = max(dp[i][j], dp[i][k] * dp[k][j]);
            }
        }
    }
 
 
}
 
int main()
{
    int test, cs = 0;
 
    scanf("%d", &test);
 
    while(test--)
    {
        double k, s, tmp;
 
        int u, v, n, m;
 
        cin>>n>>m>>s>>k;
 
        memset(dp, 0, sizeof(dp));
 
        while(m--)
        {
 
            cin>>u>>v>>tmp;
 
            dp[u][v] = (tmp*1.0)/100;
            dp[v][u] = (tmp*1.0)/100;
 
        }
 
        Warshall(n);
 
        double res = (2.0*k*s)/dp[0][n-1];
 
        printf("Case %d: %.8lf\n", ++cs, res);
 
    }
 
    return 0;
}
 
