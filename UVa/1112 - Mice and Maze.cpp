#include<bits/stdc++.h>
using namespace std;

const int inf = 16843009;

int d[105][105];

void warshall(int n)
{

    for(int k = 1; k<=n; k++)
    {
        for(int i = 1; i<=n; i++)
        {
            for(int j = 1; j<=n; j++)
            {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

}
int main()
{

    int test, cs = 0;

    scanf("%d", &test);

    for(int tc = 1; tc<=test; tc++)
    {
        if(tc>1)    puts("");

        int n, T, m, dst;

        cin>>n>>dst>>T>>m;

        memset(d, 1, sizeof(d));

        for(int i = 1; i<=n; i++)   d[i][i] = 0;

        while(m--)
        {
            int u, v, w;
            cin>>u>>v>>w;
            d[u][v] = w;
        }

        warshall(n);

        int res = 0;

        for(int i = 1; i<=n; i++)
        {
      //      cout<<d[i][dst]<<endl;
            if(d[i][dst] <=T) ++res;
        }

        cout<<res<<endl;


    }

}
