#include <bits/stdc++.h>
using namespace std;

const int mx = 10005;

int grundy[mx];
bool vis[mx];

void pre_calculate()
{
    // 0, 1, 2 is losing state

    int i, j, k;

    for(i=3; i<=mx; i++)
    {
        memset(vis, 0, sizeof vis);

        for(j=1, k=i-j; j<k; j++, k--)
        {
            int t = grundy[j]^grundy[k];

            if(t<=mx) vis[t] = 1;
        }
        for(j=0; j<mx; j++)
        {
            if(vis[j]==0)
            {
                grundy[i] = j;
                break;
            }
        }
    }


}


int main()
{
    int test, cs = 0;

    pre_calculate();

    scanf("%d", &test);

    while(test--)
    {
            int n, sum = 0, x;

            scanf("%d", &n);

            while(n--)
            {
                scanf("%d", &x);
                sum^=grundy[x];
            }

            printf("Case %d: ", ++cs);
            puts(!sum?"Bob":"Alice");
    }

    return 0;
}


