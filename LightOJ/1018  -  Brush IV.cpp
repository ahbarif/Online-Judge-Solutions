#include<bits/stdc++.h>
using namespace std;

int n, adj[18][18], dp[1<<18];

struct point
{
    int x, y;

} a[18];

bool isOn(int n, int pos)
{
    return (bool)(n&(1<<pos));
}

int Set(int n, int pos)
{
    return (n|(1<<pos));
}

//bool collinear(int i, int j, int k)
//{
//    return a[i].x*a[j].y + a[j].x*a[k].y + a[k].x * a[i].y == a[i].y*a[j].x + a[j].y*a[k].x + a[k].y * a[i].x;
//}

bool collinear(int i, int j, int k)
{

    int x1;
    int y1;
    int x2;
    int y2;
    int x3;
    int y3;

    x1 = a[i].x;
    y1 = a[i].y;

    x2 = a[j].x;
    y2 = a[j].y;

    x3 = a[k].x;
    y3 = a[k].y;

    return (y2 - y1) * (x3 - x2) == (x2 - x1) * (y3 - y2);

}

void pre_cal() // calculating mask of collinear points
{
    memset(adj, 0, sizeof(adj));

    for(int i = 1; i<=n; i++)
    {
        for(int j = i+1; j<=n; j++)
        {
            for(int k = 1; k<=n; k++)
            {
                if(i!=k && j!=k && collinear(i, j, k))
                {
                    adj[i][j] |= (1<<k);
                    adj[j][i] |= (1<<k);
                }
            }
        }
    }
}



int f(int mask)
{
   // cout<<mask<<endl;

    if(dp[mask] != -1)  return dp[mask];

    int res = 1000, done = 0, temp;

    for (int i = 1; i <= n; i++)
    {
        if(isOn(mask, i))   ++done;
    }

    if(done==n-1)   return 1;

    if(done==n) return 0;

    for(int i = 1; i<=n; i++)
    {
        if(!isOn(mask, i))
        {

            for(int j = i+1; j<=n; j++)
            {
                if(!isOn(mask, j))
                {

                    temp = mask | (1<<i);

                    temp |= (1<<j);
                    temp = temp | adj[i][j];
                    res = min(res, f(temp));

                }
            }
            break;
        }
    }

    return dp[mask] = 1 + res;
}


int main()
{

    int test, cs = 0;

    scanf("%d", &test);

    while(test--)
    {

        scanf("%d", &n);

        memset(dp, -1, sizeof(dp));

        for(int i = 1; i<=n; i++) scanf("%d %d", &a[i].x, &a[i].y);

        pre_cal();

        printf("Case %d: %d\n", ++cs, f(0));
    }
}
