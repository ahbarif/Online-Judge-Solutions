#include<bits/stdc++.h>
using namespace std;

const int mod = 1000007;
int dp[1005][1005];
int ways[1005][1005];
int nxtA[26][1005];
int nxtB[26][1005];

string a, b;

int lcs(int i, int j)
{

    if(i == a.size() || j == b.size()) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int res = 0;

    if(a[i] == b[j]) res = 1 + lcs(i+1, j+1);

    else
    {
        res = max(lcs(i+1, j), lcs(i, j+1));
    }

    return dp[i][j] = res;
}

int foo(int i, int j)
{

    if(i == a.size() || j == b.size()) return 1;

    if(ways[i][j] != -1) return ways[i][j];

    int res = 0;

    int lcss = dp[i][j];

    if(lcss == 0) return ways[i][j] = 1;

    for(int k = 0; k<26; k++)
    {

        int xx = nxtA[k][i];
        int yy = nxtB[k][j];

        if(dp[xx][yy] == lcss)
        {
            res = res + (foo(xx+1, yy+1));
            res %= mod;
        }
    }

    return ways[i][j] = res;

}

int main()
{

    int test, cs = 0;

    cin>>test;

    while(test--)
    {

        cin>>a>>b;

        memset(dp, -1, sizeof(dp));
        memset(ways, -1, sizeof(ways));

        int LCS = lcs(0, 0);

        for(int i = 0; i<26; i++)
        {
            nxtA[i][a.size()] = a.size();
            for(int j = a.size()-1; j>=0; j--)
            {
                if(a[j]-'a' == i)
                {
                    nxtA[i][j] = j;
                }
                else nxtA[i][j] = nxtA[i][j+1];
            }
        }


        for(int i = 0; i<26; i++)
        {
            nxtB[i][b.size()] = b.size();
            for(int j = b.size()-1; j>=0; j--)
            {
                if(b[j]-'a' == i)
                {
                    nxtB[i][j] = j;
                }
                else nxtB[i][j] = nxtB[i][j+1];
            }
        }


        printf("Case %d: %d\n", ++cs, foo(0, 0));

    }
    return 0;
}

