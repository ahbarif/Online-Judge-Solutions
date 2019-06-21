#include <bits/stdc++.h>
using namespace std;

const int maxn = 505;

vector <int> adj[maxn];
bool vis[maxn];
int Left[maxn], Right[maxn];

bool dfs(int u)
{
    if(vis[u]) return false;
    vis[u] = true;
    int len = adj[u].size(), i, v;
    for(i=0; i<len; i++)
    {
        v = adj[u][i];
        if(Right[v]==-1)
        {
            Right[v] = u, Left[u] = v;
            return true;
        }
    }
    for(i=0; i<len; i++)
    {
        v = adj[u][i];
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


int main()
{

        int test, cs = 0;

        cin>>test;

        while(test--){

            vector<int> v1, v2;

            for(int i = 0; i<maxn; i++) adj[i].clear();

            int n, m;

            cin>>n;

            v1.resize(n);

            for(int i = 0; i<n; i++) cin>>v1[i];

            cin>>m;

            v2.resize(m);

            for(int i = 0; i<m; i++) cin>>v2[i];

            for(int i = 0; i<m; i++){
                for(int j = 0; j<n; j++){
                    if(v2[i]%v1[j] == 0){
                        adj[j].push_back(i+n);
                    }
                }
            }

            printf("Case %d: %d\n", ++cs, maxMatch(n+m));

        }

	return 0;
}

