#include<bits/stdc++.h>
using namespace std;

const int sz = 20005;

vector<int> adj[sz], rev[sz];
int component[sz];
stack<int> nodes;
bool vis[sz], in[sz], out[sz];

void init()
{
    memset(vis, 0, sizeof(vis));
    memset(component, 0, sizeof(component));
    for(int i = 0; i<sz; i++)
    {
        adj[i].clear();
        rev[i].clear();
    }

    memset(in, 0, sizeof(in));
    memset(out, 0, sizeof(out));

}

void dfs(int u)
{
    vis[u] = 1;

    for(vector<int> ::iterator it = adj[u].begin(); it!=adj[u].end(); it++)
    {
        if(vis[*it]==false) dfs(*it);
    }

    nodes.push(u);
}


void dfs2(int u, int cmp)
{
    component[u] = cmp;

    for(vector<int> ::iterator it = rev[u].begin(); it!=rev[u].end(); it++)
    {
        if(component[*it] == 0 ) dfs2(*it, cmp);
    }

}




int main ()
{

    int test, cs = 0;

    scanf("%d", &test);

    while(test--)
    {

        init();

        int n, m, u, v, cnt = 0;

        scanf("%d %d", &n, &m);

        while(m--)
        {
            scanf("%d %d", &u, &v);
            adj[u].push_back(v);
            rev[v].push_back(u);
        }

        for(int i = 1; i<=n; i++)
        {
            if(vis[i]==false)   dfs(i);
        }

        while(nodes.size()>0)
        {
            int top = nodes.top();
            nodes.pop();

            if(component[top]==0)
            {
                dfs2(top, ++cnt);
            }
        }

        for(int i = 1; i<=n; i++)
        {
            for(vector<int> :: iterator it = adj[i].begin(); it!=adj[i].end(); it++)
            {
                if(component[i] != component[*it])
                {
                    in[component[*it]] = true;
                    out[component[i]] = true;
                }
            }
        }

        int res, inc = 0, outc = 0;

        for(int i = 1; i<=cnt; i++)
        {
            if(in[i] == false) ++inc;
            if(out[i] == false) ++outc;
        }

        res = max(inc, outc);
        if(cnt == 1)    res = 0;

        printf("Case %d: %d\n", ++cs, res);

    }

    return 0;
}

