#include<bits/stdc++.h>
using namespace std;

const int maxn = 1005;
vector<int> adj[maxn], rev[maxn], dag[maxn], G[maxn], top;
bool vis[maxn];
int comp[maxn], Left[maxn], Right[maxn], nnodes;

void BFS(int src){

    memset(vis, 0, sizeof(vis));

    queue<int> q;

    q.push(src);
    vis[src] = true;
    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int i = 0; i<G[u].size(); i++){
            int v = G[u][i];

            if(vis[v] == false){
                q.push(v);
                vis[v] = true;
                adj[src].push_back(v);
                rev[v].push_back(src);
            }
        }
    }
}


void SCC_DFS(int u)
{
    vis[u] = 1;

    for(int i = 0; i<adj[u].size(); i++)
    {
        int v = adj[u][i];

        if(vis[v]==false) SCC_DFS(v);
    }

    top.push_back(u);
}


void SCC_DFS2(int u, int cmp_no)
{
    comp[u] = cmp_no;

    vis[u] = true;

    for(int i = 0; i<rev[u].size(); i++)
    {
        int v = rev[u][i];

        if(vis[v] == false) SCC_DFS2(v, cmp_no);
    }
}

void shrink(int node)
{
    for(int i = 0; i<node; i++){
        for(int j = 0; j<adj[i].size(); j++)
        {
            int v = adj[i][j];

            if(comp[i] != comp[v]){
                dag[comp[i]].push_back(comp[v]);
            }
        }
    }

}

void createDag(int n)
{

    int cmp = 0;

    memset(vis, 0, sizeof(vis));

    for(int i = 0; i<n; i++)
    {
        if(vis[i]==0)   SCC_DFS(i);
    }

    memset(vis, 0, sizeof(vis));

    while(top.size()>0)
    {
        int topa = top.back();

        top.pop_back();

        if(vis[topa]==0)
        {
            SCC_DFS2(topa, cmp++);
        }
    }

    nnodes = cmp;

    shrink(n);
}

void init()
{
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i<maxn; i++){
        adj[i].clear();
        dag[i].clear();
        rev[i].clear();
        G[i].clear();
    }
}

bool dfs(int u)
{
    if(vis[u]) return false;
    vis[u] = true;
    int len = dag[u].size(), i, v;
    for(i=0; i<len; i++)
    {
        v = dag[u][i];
        if(Right[v]==-1)
        {
            Right[v] = u, Left[u] = v;
            return true;
        }
    }
    for(i=0; i<len; i++)
    {
        v = dag[u][i];
        if(dfs(Right[v]))
        {
            Right[v] = u, Left[u] = v;
            return true;
        }
    }
    return false;
}

int maximumMatching(int n)
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



int main()
{
#ifdef local
    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
#endif

    int test, cs = 0;

    cin>>test;

    while(test--)
    {

        int n, m, u, v;

        init();

        scanf("%d %d", &n, &m);
        for(int i = 0; i<m; i++){
            scanf("%d %d", &u, &v);
            --u;
            --v;
            G[u].push_back(v);
        }

        for(int i = 0; i<n; i++) BFS(i);

        createDag(n);

        int ret = maximumMatching(nnodes);

        printf("Case %d: %d\n", ++cs, nnodes - ret);
    }


#ifdef local
    cerr<<"\n\n__time elapsed = "<<clock()*1000/CLOCKS_PER_SEC<<" ms__"<<endl;
#endif

}

