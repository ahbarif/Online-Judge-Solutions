#include <bits/stdc++.h>
using namespace std;

int dp[105][105], x1, x2;

string a, b;

void tryAll(char p, int lcs)
{
    int x = -1, y = -1;

    for(int i=x1+1; i<a.length(); i++)
    {
        if(a[i]==p)
        {
            x = i;
            break;
        }
    }

    for(int i=x2+1; i<b.length(); i++)
    {
        if(b[i]==p)
        {
            y = i;
            break;
        }
    }

    if(x!=-1 && y!=-1 && dp[x][y]==lcs)
    {
         printf("%c", p);
         x1 = x;
         x2 = y;
    }
}

int fun(int i, int j)
{
    if(i==a.size() || j==b.size())  return 0;

    if(dp[i][j]!=-1)    return dp[i][j];

    int res = 0;

    if(a[i]==b[j])  res = 1 + fun(i+1, j+1);
    else
    {
        int x, y;
        x = fun(i+1, j);
        y = fun(i, j+1);

        res = max(x, y);
    }

    return dp[i][j] = res;

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
        x1 = -1;
        x2 = -1;

        int lcs = fun(0, 0);

        printf("Case %d: ", ++caseno);

        if(lcs==0)  printf(":(");

        while(lcs>0)
        {
            for(int i='a'; i<='z'; i++)
            {
                tryAll(i, lcs);
            }
            lcs--;
        }

        puts("");
    }

    return 0;
}
