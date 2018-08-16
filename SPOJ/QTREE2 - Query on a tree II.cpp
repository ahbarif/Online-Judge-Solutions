#include<bits/stdc++.h>
using namespace std;

const int root  = 0;
const int maxn = 10005, maxLog = 15;
vector<int> adj[maxn], costs[maxn];
int level[maxn], P[maxLog][maxn], D[maxn];

void dfs(int u, int par, int depth = 0) {
    P[0][u] = par;
    level[u] = depth;

    for(int i = 0; i<adj[u].size(); i++) {

        int v = adj[u][i];

        if(v!=par)  {
            D[v] = D[u] + costs[u][i];
            dfs(v, u, depth + 1);
        }
    }
}

int LCA(int u, int v) {
    if(level[u] < level[v]) swap(u,v);
    int diff = level[u] - level[v];
    for(int i=0; i<maxLog; i++) if((diff>>i)&1) u = P[i][u];
    if(u == v) return u;
    for(int i=maxLog-1; i>=0; i--) if(P[i][u] != P[i][v]) {
            u = P[i][u];
            v = P[i][v];
        }
    return P[0][u];
}

int dist(int u, int v){
    int l = LCA(u, v);

    return D[u] + D[v] - 2 * D[l];
}

void init(){
    for(int i = 0; i<maxn; i++){
        adj[i].clear();
        costs[i].clear();

    }

    D[root] = 0;
    memset(P, -1, sizeof(P));

}

int find_kth(int u, int k){

    int diff = k;

    for(int i = maxLog-1; i>=0; i--){
        if((1<<i)<=k){
            k -= (1<<i);
            u = P[i][u];

        }
    }

    return u;
}

int query(int u, int v, int k){

    int lca = LCA(u, v);

    int leftSide = level[u] - level[lca] + 1;

    if(k<=leftSide) return find_kth(u, k-1);

    else{
        int diff = level[v] - (level[lca]+(k-leftSide));

        return find_kth(v, diff);
    }
}

int main() {

#ifdef local
    freopen("in.txt", "r", stdin);
#endif

    int test;

    scanf("%d", &test);

    while(test--) {

        int n, q, root = 0;

        scanf("%d", &n);

        init();

        for(int i=1; i<n; i++) {
            int u, v, c;
            scanf("%d %d %d", &u, &v, &c);
            u--;
            v--;
            adj[u].push_back(v);
            costs[u].push_back(c);
            adj[v].push_back(u);
            costs[v].push_back(c);
        }

        dfs(root, -1);

        for(int i=1; i<maxLog; i++)
            for(int j=0; j<n; j++)
                if(P[i-1][j] != -1)
                    P[i][j] = P[i-1][P[i-1][j]];


        char s[10];

        while(true){
            scanf("%s", s);
            if(s[1] == 'O') break;

            if(s[1] == 'I'){
                int u, v;
                scanf("%d %d", &u, &v);
                printf("%d\n", dist(u-1, v-1));
            }
            else{
                int u, v, k;
                scanf("%d %d %d", &u, &v, &k);
                printf("%d\n", 1 + query(u-1, v-1, k));
            }
        }
    }
    return 0;
}
