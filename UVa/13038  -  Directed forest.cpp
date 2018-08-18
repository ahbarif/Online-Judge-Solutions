#include<bits/stdc++.h>
using namespace std;

bool vis[100005];
int res;
vector<int> adj[100005];

void dfs(int u, int depth = 1){

    vis[u] = 1;
    res = max(res, depth);
    for(int i = 0; i<adj[u].size(); i++){
        dfs(adj[u][i], depth+1);
    }
}

int main() {

   // freopen("in.txt", "r", stdin);

    int test, cs = 0;

    scanf("%d", &test);

    while(test--){
        int n, m;
        scanf("%d %d", &n, &m);
        for(int i = 0; i<=n; i++){
            adj[i].clear();
            vis[i] = false;
        }
        res = 0;

        while(m--){
            int u, v;
            scanf("%d %d", &u, &v);
            adj[u].push_back(v);
        }

        for(int i = 1; i<=n; i++){
            if(!vis[i]) dfs(i);
        }

        printf("Case %d: %d\n", ++cs, res);
    }
    return 0;
}
