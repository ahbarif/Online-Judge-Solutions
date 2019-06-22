#include <bits/stdc++.h>
using namespace std;

int dx[] = {-3, -1, -2, -2, -1, +1};
int dy[] = {-1, -3, +1, -1, -2, -2};

const int maxn = 505;

int dp[maxn][maxn];

int grundy(int x, int y)
{
    //cout<<x<<" "<<y<<endl;

    int foo = 0;

    if(dp[x][y] != -1) return dp[x][y];

    bool flag[maxn*20];
    memset(flag, 0, sizeof(flag));

    for(int i = 0; i<6; i++)
    {

        int tx = x + dx[i];
        int ty = y + dy[i];

        if(tx>=0 && tx<maxn && ty>=0 && ty<maxn)  foo++;

    }

    if(foo == 0) return dp[x][y] = 0;

    for(int i = 0; i<6; i++)
    {

        int tx = x + dx[i];
        int ty = y + dy[i];

        if(tx>=0 && tx<maxn && ty>=0 && ty<maxn)
        {
            flag[grundy(tx, ty)] = 1;
        }

    }

    for(int i = 0; i<maxn*20; i++)
    {
        if(flag[i] == 0)
        {
            return dp[x][y] = i;
        }
    }

}

int main(){

    int test, cs = 0;

    scanf("%d", &test);

    memset(dp, -1, sizeof(dp));

    while(test--)
    {
        int n, x, y, state = 0;

        scanf("%d", &n);

        while(n--)
        {

            scanf("%d %d", &x, &y);
            state ^= grundy(x, y);

        }

        if(state) printf("Case %d: Alice\n", ++cs);
        else printf("Case %d: Bob\n", ++cs);
    }

    return 0;
}

