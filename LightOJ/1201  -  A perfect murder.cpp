#include<bits/stdc++.h>
using namespace std;

const int maxn = 1005;

vector <int> adj[maxn];
vector <int> adj2[maxn];
bool vis[maxn];
int Left[maxn], Right[maxn];

bool dfs(int u)
{
    if(vis[u]) return false;
    vis[u] = true;
    int len = adj2[u].size(), i, v;
    for(i=0; i<len; i++)
    {
        v = adj2[u][i];
        if(Right[v]==-1)
        {
            Right[v] = u, Left[u] = v;
            return true;
        }
    }
    for(i=0; i<len; i++)
    {
        v = adj2[u][i];
        if(dfs(Right[v]))
        {
            Right[v] = u, Left[u] = v;
            return true;
        }
    }
    return false;
}

int maxMatch(int n)
{


    int i, ret = 0;
    bool done;

    memset(Left, -1, sizeof(Left));
    memset(Right, -1, sizeof(Right));

    do
    {
        done = true;

        memset(vis, 0, sizeof(vis));

        for(i=0; i<n; i++)
        {
            if(Left[i]==-1 && dfs(i))
            {
                done = false;
            }
        }
    }
    while(!done);

    for(i=0; i<n; i++) ret += (Left[i]!=-1);

    return ret;
}

int color[maxn];

void dfs2(int node, int c){

    color[node] = c;

    for(int i = 0; i<adj[node].size(); i++){
        int v = adj[node][i];
        if(color[v] == -1) dfs2(v, c^1);
    }

}

int main()
{



 //   freopen("in.txt", "r", stdin);

    int test, cs = 0;

    scanf("%d", &test);

    while(test--){

        int n, m;

        scanf("%d %d", &n, &m);

        for(int i = 0; i<m; i++){
            int x, y;
            scanf("%d %d", &x, &y);
            x--;
            y--;
            adj[x].push_back(y);
            adj[y].push_back(x);

        }
        memset(color, -1, sizeof(color));

        for(int i = 0; i<n; i++){
            if(color[i]==-1) dfs2(i, 0);
        }

        for(int i = 0; i<n; i++){
            if(color[i] == 0){

                for(int j = 0; j<adj[i].size(); j++){
                    adj2[i].push_back(adj[i][j]);
                }
            }
        }
        int bpm = maxMatch(n);

        printf("Case %d: %d\n", ++cs, n-bpm);

        for(int i = 0; i<maxn; i++) adj[i].clear();

        for(int i = 0; i<maxn; i++) adj2[i].clear();

    }




}

