#include <bits/stdc++.h>
using namespace std;

vector<int> g[2005], rev[2005];
bool vis[2005];
stack<int> nodes;

void init(){
    for(int i = 0; i<2005; i++) g[i].clear();
    for(int i = 0; i<2005; i++) rev[i].clear();
    memset(vis, 0, sizeof(vis));

}

void dfs(int u)
{
        vis[u] = 1;

        for(vector<int> ::iterator it = g[u].begin(); it!=g[u].end(); it++)
        {
            if(!vis[*it])   dfs(*it);
        }

        nodes.push(u);

}

void dfs2(int u)
{
        vis[u] = 1;

        for(vector<int> ::iterator it = rev[u].begin(); it!=rev[u].end(); it++)
        {
            if(!vis[*it])   dfs2(*it);
        }

}

int main()
{

    int n, m, u, v, i, p;

    while(scanf("%d %d", &n, &m) && n|m)
    {
        init();

        while(m--)
        {
            scanf("%d %d %d", &u, &v, &p);

            g[u].push_back(v);
            if(p==2)    g[v].push_back(u);

            rev[v].push_back(u);
            if(p==2)    rev[u].push_back(v);
        }

        for(int i = 1; i<=n; i++)
        {
            if(vis[i]==0)    dfs(i);
        }

        memset(vis, 0, sizeof(vis));

        int cmp = 0;

        for(int i = 1; i<=n; i++)
        {
            int top = nodes.top();
            nodes.pop();

            if(vis[top])    continue;
            else
            {
                ++cmp;
                dfs2(top);
            }
        }

        cout<<(cmp==1?1:0)<<endl;

    }



    return 0;

}
