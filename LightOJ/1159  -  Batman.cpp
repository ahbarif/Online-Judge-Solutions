#include <bits/stdc++.h>
using namespace std;
 
int dp[60][60][60];
 
string a, b, c;
 
int fun(int i, int j, int k)
{
    if(i==a.size() || j==b.size() || k==c.size())  return 0;
 
    if(dp[i][j][k]!=-1)    return dp[i][j][k];
 
    int res = 0;
 
    if(a[i]==b[j] && b[j]==c[k])  res = 1 + fun(i+1, j+1, k+1);
    else
    {
        int x, y, z;
        x = fun(i+1, j, k);
        y = fun(i, j+1, k);
        z = fun(i, j, k+1);
        res = max(x, max(y, z));
    }
 
    return dp[i][j][k] = res;
 
}
 
int main()
{
 
    int test,  caseno = 0;
 
    scanf("%d", &test);
 
    while(test--)
    {
        memset(dp, -1, sizeof dp);
        cin>>a;
        cin>>b;
        cin>>c;
        cout<<"Case "<<++caseno<<": "<<fun(0, 0, 0)<<endl;
    }
 
    return 0;
}