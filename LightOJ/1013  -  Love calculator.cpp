#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
string a, b;
 
int dp[35][35];
ll foo[35][35][35];
 
int lcs(int i, int j)
{
    if(i==a.size() || j==b.size())  return 0;
 
    if(dp[i][j]!=-1)    return dp[i][j];
 
    int res = 0;
 
    if(a[i]==b[j])  res = 1 + lcs(i+1, j+1);
 
    else res = max(lcs(i+1, j), lcs(i, j+1));
 
    return dp[i][j] = res;
}
 
ll us(int i, int j, int LCS)
{
 
    if(i>=a.size() && j>=b.size() && LCS == 0) return 1;
 
 
    if(foo[i][j][LCS]!=-1)  return  foo[i][j][LCS];
 
    ll x = 0, y = 0, z = 0;
 
    if(a[i]==b[j]&&LCS && i<a.size() && j<b.size()) x = us(i+1, j+1, LCS-1);
    else
    {
        if(i<a.size())  y = us(i+1, j, LCS);
        if(j<b.size())  z = us(i, j+1, LCS);
    }
 
    return foo[i][j][LCS] = x+y+z;
 
}
 
 
int main()
{
    int test, cs = 1;
 
    scanf("%d", &test);
 
    while(test--)
    {
        cin>>a>>b;
 
        memset(dp, -1, sizeof(dp));
 
        memset(foo, -1, sizeof(foo));
 
        int p = lcs(0, 0);
 
        cout<<"Case "<<cs++<<": "<<a.length() + b.length() - p<<" "<<us(0, 0, p)<<endl;
 
    }
 
    return 0;
}