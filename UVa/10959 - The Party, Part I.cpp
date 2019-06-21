#include<bits/stdc++.h>
using namespace std;

vector<int> graph[1005];

int d[1005];

void bfs(int s, int n)
{
    d[s] = 0;

    queue<int> q;

    q.push(s);

    while(!q.empty())
    {
        int v = q.front();
        q.pop();

        for(int i = 0; i<graph[v].size(); i++)
        {
            int u = graph[v][i];
            if(d[u]==-1)
            {
                d[u] = 1 + d[v];
                q.push(u);
            }
        }
    }

    for(int i = 1; i<n; i++)   cout<<d[i]<<endl;
}


int main()
{

    int test, sp = 0;

    scanf("%d", &test);

    while(test--)
    {

        int n, edge, x, y;


        memset(d, -1, sizeof d);
        for(int i=0; i<1005; i++)    graph[i].clear();
        int flag = 1;

        scanf("%d %d", &n, &edge);
        while(edge--)
        {
            scanf("%d %d", &x, &y);
            graph[x].push_back(y);
            graph[y].push_back(x);
        }

        if(sp) puts("");

        bfs(0, n);

        sp = 1;

    }

    return 0;
}
