#include<bits/stdc++.h>
using namespace std;

vector<int> graph[205];
int color[205];

int DFS(int u, int c)
{
        color[u]=c;
        int i, v;
        for(i=0; i<graph[u].size(); i++)
        {
            v=graph[u][i];
            if(color[v]==c)     return 0;
            if(color[v]==-1)    DFS(v, 1-c);
        }
    return 1;
}

int main()
{
        int n, edge, x, y;

        while(scanf("%d", &n) && n>0)
        {
                memset(color, -1, sizeof color);
                for(int i=0; i<205; i++)    graph[i].clear();
                int flag = 1;

                scanf("%d", &edge);
                while(edge--)
                {
                    scanf("%d %d", &x, &y);
                    graph[x].push_back(y);
                    graph[y].push_back(x);
                }

                flag = DFS(0, 0);

                puts(flag?"BICOLORABLE.":"NOT BICOLORABLE.");

        }

    return 0;
}
