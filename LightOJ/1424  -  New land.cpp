#include<bits/stdc++.h>
using namespace std;

typedef long long i64;
char ar[2005][2005];
int dp[2005][2005];

int getMaxArea(int row, int n)
{

    dp[row][n] = 0;
    n++;
    stack<int> s;

    int res = 0, tp, tmp, i = 0;

    while (i < n)
    {
        if (s.empty() || dp[row][s.top()] <= dp[row][i])    s.push(i++);

        else
        {
            tp = s.top();

            s.pop();

            tmp = dp[row][tp] * (s.empty() ? i : i - s.top() - 1);

            if (res < tmp)  res = tmp;
        }
    }

    while(!s.empty()) s.pop();

    return res;
}

int main()
{
    int test, cs = 0;

    scanf("%d", &test);

    while(test--)
    {
        int n, m;

        scanf("%d %d", &n, &m);

        //  getchar();

        //    memset(dp, 0, sizeof(dp));

        for(int i = 0; i<n; i++) scanf("%s", ar[i]);

        for(int i = 0; i<m; i++)
        {
            if(ar[0][i] == '0') dp[0][i] = 1;
            else dp[0][i] = 0;
        }

        int res = getMaxArea(0, m);


        for(int i = 1; i<n; i++)
        {
            for(int j = 0; j<m; j++)
            {
                if(ar[i][j] == '0') dp[i][j] = 1 + dp[i-1][j];
                else dp[i][j] = 0;

            }
            res = max(res, getMaxArea(i, m));



        }

        cout<<"Case "<<++cs<<": "<<res<<endl;
    }

    return 0;
}

