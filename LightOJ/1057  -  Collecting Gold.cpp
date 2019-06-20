#include<bits/stdc++.h>
using namespace std;

int distancE(pair<int, int> a, pair<int, int> b)
{
    return max(abs(a.first-b.first), abs(a.second-b.second));
}

int n, m, cnt;

char grid[22][22];

int dp[5 + (1<<16)][17];

vector<pair<int, int> > v;

int f(int mask, int cur)
{
    if(__builtin_popcount(mask)>=cnt)
    {
        return distancE(v[0], v[cur]);
    }

    if(dp[mask][cur] != -1 ) return dp[mask][cur];

    int res = INT_MAX, tmp;

    for(int i = 1; i<=cnt; i++)
    {
        if(!(mask&(1<<i))) // ith bit is off
        {
          //  puts("#");
            tmp = distancE(v[i], v[cur]) + f(mask|(1<<i), i);
            res = min(res, tmp);
        }
    }

    return dp[mask][cur] = res;
}

int main()
{

        int test, cs = 0;

        scanf("%d", &test);

        while(test--)
        {
            scanf("%d %d", &n, &m);

            cnt = 0;

            memset(dp, -1, sizeof(dp));

            v.clear();

            for(int i = 0; i<n; i++)    scanf("%s", &grid[i]);

            for(int i = 0; i<n; i++)
            {
                for(int j = 0; j<m; j++)
                {
                    if(grid[i][j]=='x') v.push_back(make_pair(i, j));
                    else if(grid[i][j]=='g')
                    {
                        v.push_back(make_pair(i, j));
                        cnt++;
                    }
                }
            }

            int res = f(0, 0);

            printf("Case %d: %d\n", ++cs, res);
        }


}
