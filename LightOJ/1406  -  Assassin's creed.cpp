#include<bits/stdc++.h>
using namespace std;

const int maxn = 16;

vector<int> adj[maxn], bitmasks[maxn];
bool vis[maxn][1<<maxn];
int dp[1<<maxn], n, m;

void init(){
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i<maxn; ++i){
        adj[i].clear();
        bitmasks[i].clear();
    }
    memset(vis, 0, sizeof(vis));
}

void dfs(int u, int mask){

    vis[u][mask] = 1;

    for(int i = 0; i<adj[u].size(); i++){
        int v = adj[u][i];
        int nMask = mask|(1<<v);

        if(!vis[v][nMask]) dfs(v, nMask);
    }

    for(int i = 0; i<n; i++){
        if((mask&(1<<i))){
            bitmasks[i].push_back(mask);
        }
    }

}

int func(int mask){

    if(__builtin_popcount(mask) == n) return 0;

    if(dp[mask] != -1) return dp[mask];

    int ret = 20, u;

    for(u = 0; mask&(1<<u); u++){}

    for(int j = 0; j<bitmasks[u].size(); j++){
        int nMask = bitmasks[u][j];
        if((nMask & mask) == 0){
            ret = min(ret, 1 + func(mask|nMask));
        }
    }

    return dp[mask] = ret;
}

int main()
{
   // freopen("in.txt", "r", stdin);

    int test, cs = 0;

    scanf("%d", &test);

    while(test--){

        init();
        scanf("%d %d", &n, &m);

        while(m--){
            int u, v;
            scanf("%d %d", &u, &v);
            adj[u-1].push_back(v-1);
        }

        for(int i = 0; i<n; i++){
            dfs(i, 1<<i);
        }

        int ret = func(0);

        printf("Case %d: %d\n", ++cs, ret);


    }


}


