#include <bits/stdc++.h>
using namespace std;

const int sz = 50005;

vector<int> adj[sz];
bool vis1[sz], vis2[sz];

int dfs(int u)
{

        int res = 0;

        vis2[u] = true;
        vis1[u] = true;

        for(int i = 0; i<adj[u].size(); i++)
        {
            int v = adj[u][i];

            if(vis2[v]==0)
            {
                res++;
                res += dfs(v);
            }
        }

        vis2[u] = false;

        return res;
}

int main()
{

    int test, cs = 0;

    scanf("%d", &test);

    while(test--)
    {
        int n, u, v, res = -1, j = -1;

        for(int i = 0; i<sz; i++)   adj[i].clear();
        memset(vis1, 0, sizeof(vis1));
        memset(vis2, 0, sizeof(vis2));

        scanf("%d", &n);

        for(int i = 0; i<n; i++)
        {
            scanf("%d %d", &u, &v);
            adj[u].push_back(v);
        }

        for(int i = 1; i<=n; i++)
        {
            if(vis1[i]==0)
            {
                int temp = dfs(i);
                if(temp>res)
                {
                    res = temp;
                    j = i;
                }
            }
        }

        printf("Case %d: %d\n", ++cs, j);


    }
    return 0;
}
