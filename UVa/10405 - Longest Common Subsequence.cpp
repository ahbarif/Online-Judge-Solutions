#include<bits/stdc++.h>
using namespace std;

int dp[1009][1009];

string a,b;
int lena, lenb;

int lcs(int i, int j)
{
    if(i==lena || j==lenb) return 0;
    if(dp[i][j]==-1)
    {
        if(a[i]==b[j]) dp[i][j] = 1 + lcs(i+1,j+1);
        else dp[i][j] = max(lcs(i,j+1), lcs(i+1,j));
    }
    return dp[i][j];
}

int main()
{
    while(getline(cin,a))
    {
        getline(cin, b);
        lena = a.length(), lenb = b.length();
        memset(dp,-1,sizeof(dp));
        cout<<lcs(0,0)<<endl;
    }

    return 0;
}
