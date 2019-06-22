// HLD with node update - Aladdin and the return journey
#include<bits/stdc++.h>
using namespace std;

const int maxn = 30002, maxLog = 16;
vector<int> adj[maxn];
int baseArray[maxn], ptr;
int chainNo, chainInd[maxn], chainHead[maxn], posInBase[maxn];
int level[maxn], P[maxLog][maxn], subSize[maxn], costs[maxn];
int tree[maxn*4];

void dfs(int u, int par, int depth = 0) {
    P[0][u] = par;
    level[u] = depth;
    subSize[u] = 1;

    for(int i = 0; i<adj[u].size(); i++) {
        int v = adj[u][i];
        if(v!=par) {
            dfs(v, u, depth+1);
            subSize[u] += subSize[v];
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

void make_tree(int node, int st, int en) {
    if(st == en) {
        tree[node] = baseArray[st];
        return;
    }
    int l = 2*node, r = l|1, mid = (st+en)/2;
    make_tree(l, st, mid);
    make_tree(r, mid+1, en);
    tree[node] = tree[l]+tree[r];
}

void update_tree(int node, int st, int en, int i, int val) {

    if(i>en || i<st)    return;
    if(st==en) {
        tree[node] = val;
        return;
    }

    int l = 2*node, r = l|1, mid = (st+en)/2;
    update_tree(l, st, mid, i, val);
    update_tree(r, mid+1, en, i, val);

    tree[node] = tree[l]+tree[r];

}

int tree_query(int node, int lo, int hi, int i, int j) {
    if(i>hi || j<lo)    return 0;

    if(i<=lo && j>=hi)  return tree[node];

    int l = 2*node, r = l|1, mid = (lo+hi)/2;

    int x = tree_query(l, lo, mid, i, j);
    int y = tree_query(r, mid+1, hi, i, j);

    return x+y;
}

int query_up(int u, int v) {
    if(u==v) return costs[u];

    int uChain, vChain = chainInd[v], ret = 0;

    while(true) {
        uChain = chainInd[u];

        if(uChain == vChain) {
            int x = tree_query(1, 0, ptr-1, posInBase[v], posInBase[u]);
            ret += x;
            break;
        }

        int x = tree_query(1, 0, ptr-1, posInBase[chainHead[uChain]], posInBase[u]);
        ret +=x;
        u = chainHead[uChain];
        u = P[0][u];
    }

    return ret;
}

void query(int u, int v) {
    int lca = LCA(u, v);
    int ret1 = query_up(u, lca);
    int ret2 = query_up(v, lca);
    int ret = ret1 + ret2 - costs[lca];
    printf("%d\n", ret);
}

void update(int u, int val) {
    costs[u] = val;
    int idx = posInBase[u];
    update_tree(1, 0, ptr-1, idx, val);
}

void HLD(int curNode, int par) {

    if(chainHead[chainNo] == -1) chainHead[chainNo] = curNode;

    chainInd[curNode] = chainNo;
    posInBase[curNode] = ptr;

    baseArray[ptr++] = costs[curNode];

    int heavyChild = -1;

    for(int i = 0; i<adj[curNode].size(); i++) {
        int v = adj[curNode][i];
        if(v!=par) {
            if(heavyChild == -1 || subSize[heavyChild] < subSize[v]) {
                heavyChild = v;
            }
        }
    }

    if(heavyChild != -1) {
        HLD(heavyChild, curNode);
    }

    for(int i = 0; i<adj[curNode].size(); i++) {
        int v = adj[curNode][i];
        if(v!=par && v!= heavyChild) {
            ++chainNo;
            HLD(v, curNode);
        }
    }

}

void init(int n) {
    for(int i = 0; i<=n; i++) {
        adj[i].clear();
        chainHead[i] = -1;
        for(int j = 0; j<maxLog; j++) P[j][i] = -1;
    }
}


int main() {

#ifdef local
       freopen("in.txt", "r", stdin);
#endif

    int test, cs = 0;

    scanf("%d", &test);

    while(test--) {

        ptr = 0;

        int n, q, root = 0;

        scanf("%d", &n);

        init(n);

        for(int i = 0; i<n; i++) scanf("%d", &costs[i]);

        for(int i=1; i<n; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        chainNo = 0;
        dfs(root, -1);
        HLD(root, -1);

        make_tree(1, 0, ptr-1);


        for(int i=1; i<maxLog; i++)
            for(int j=0; j<n; j++)
                if(P[i-1][j] != -1)
                    P[i][j] = P[i-1][P[i-1][j]];

        scanf("%d", &q);

        printf("Case %d:\n", ++cs);

        while(q--){
            int t, u, v;
            scanf("%d %d %d", &t, &u, &v);
            if(t == 0) query(u, v);
            else update(u, v);
        }

    }



    return 0;
}

