#include<bits/stdc++.h>
using namespace std;

const int maxn = 100005, maxLog = 18;
vector<int> adj[maxn];
int chainNo, chainInd[maxn], chainHead[maxn], posInBase[maxn];
int level[maxn], subSize[maxn], mp[maxn], P[maxn];
int tree[4*maxn];
int ptr, inf = 1e7;
bool state[maxn];

void dfs(int u, int par, int depth = 0) {
    level[u] = depth;
    subSize[u] = 1;
    P[u] = par;

    for(int i = 0; i<adj[u].size(); i++) {
        int v = adj[u][i];
        if(v!=par) {
            dfs(v, u, depth+1);
            subSize[u] += subSize[v];
        }
    }
}

void update_tree(int node, int st, int en, int i) {

    if(i>en || i<st)    return;
    if(st==en) {
        tree[node] ^= 1;
        return;
    }

    int l = 2*node, r = l|1, mid = (st+en)/2;
    update_tree(l, st, mid, i);
    update_tree(r, mid+1, en, i);

    tree[node] = tree[l]+tree[r];

}

int query(int node, int st, int en, int ql, int qr){

        if(st>en || ql > en || qr < st || tree[node] == 0) return inf;

        if(st == en) return st;

        int l = 2*node, r = l|1, mid = (st+en)/2;

        int ret = query(l, st, mid, ql, qr);

        if(ret != inf) return ret;

        return query(r, mid+1, en, ql, qr);
}

void query(int u) {


    int ret = inf;

    while(true){

            if(u == -1) break;

            int x = query(1, 1, ptr, posInBase[chainHead[chainInd[u]]], posInBase[u]);

            if(x<ret) ret = x;

            u = P[chainHead[chainInd[u]]];
    }

    if(ret == inf) puts("-1");

    else printf("%d\n", mp[ret]);

}
void HLD(int curNode, int par) {

    if(chainHead[chainNo] == -1) chainHead[chainNo] = curNode;

    chainInd[curNode] = chainNo;

    posInBase[curNode] = ++ptr;
    mp[ptr] = curNode;

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
        P[i] = -1;
    }

}

void toggle(int u) {

    update_tree(1, 1, ptr, posInBase[u]);
}


int main() {

#ifdef local
    freopen("in.txt", "r", stdin);
#endif

    int n, q;

    while(scanf("%d %d", &n, &q) != EOF) {

        memset(tree, 0, sizeof(tree));

        ptr = 0;

        init(n);

        for(int i=1; i<n; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        chainNo = 1;
        dfs(1, -1);
        HLD(1, -1);

        while(q--) {
            int u, v;
            scanf("%d %d", &u, &v);
            if(u == 0) toggle(v);
            else query(v);
        }


    }
    return 0;
}
