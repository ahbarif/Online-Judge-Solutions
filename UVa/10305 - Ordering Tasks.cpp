#include <bits/stdc++.h>
using namespace std;

vector<int> g[105];
bool vis[105];
int in[105];
vector<int> res;

void init()
{
    for(int i = 0; i<105; i++)  g[i].clear();
    memset(vis, 0, sizeof(vis));
    memset(in, 0, sizeof(in));
    res.clear();
}

void print()
{
    reverse(res.begin(), res.end());

    for(int i = 0; i<res.size()-1; i++)   cout<<res[i]<<" ";
    cout<<res.back()<<endl;
}

void dfs(int u)
{
        vis[u] = 1;

        for(vector<int> ::iterator it = g[u].begin(); it!=g[u].end(); it++)
        {
            if(!vis[*it])   dfs(*it);
        }

        res.push_back(u);


}

int main()
{

    int n, m, u, v, i;

    while(scanf("%d %d", &n, &m) && n|m)
    {
        init();

        while(m--)
        {
            scanf("%d %d", &u, &v);

            g[u].push_back(v);
            in[v]++;
        }

        for(int i = 1; i<=n; i++)
        {
            if(in[i]==0)    dfs(i);
        }

        print();
    }



    return 0;

}
