#include <bits/stdc++.h>
using namespace std;

int m[1005], n, sum = 0, visited = 0, flag;
vector<int> g[1007];
bool vis[1007];

void init()
{
    for(int i=0; i<1007; i++)   g[i].clear();
    memset(m, 0, sizeof m);
    memset(vis, 0, sizeof vis);
    sum = 0, visited = 0;
    flag = 1;
}

void dfs(int v)
{
    vis[v] = 1;
    ++visited;
    sum+=m[v];

    int i, u, sz = g[v].size();

    for(i=0; i<sz; i++)
    {
        u = g[v][i];
        if(vis[u])  continue;
        else dfs(u);
    }
}

int main()
{
    int test, cs = 0;

    scanf("%d", &test);

    while(test--)
    {
        init();

        int edge, i, avg, total = 0, x, y;

        scanf("%d %d", &n, &edge);

        for(i=1; i<=n; i++)
        {
            scanf("%d", &m[i]);
            total+=m[i];
        }

        while(edge--)
        {
            scanf("%d %d", &x, &y);
            g[x].push_back(y);
            g[y].push_back(x);
        }

        if(total%n) flag = 0;

        else
        {
            avg = total/n;

            for(i=1; i<=n; i++)
            {
                if(vis[i]==0)
                {
                    dfs(i);
                    if(sum != visited*avg)  flag = 0;
                }

                visited = 0;
                sum = 0;

            }



        }

        char lol[2][10] = {"No", "Yes"};
        printf("Case %d: %s\n", ++cs, lol[flag]);

    }

    return 0;

}
