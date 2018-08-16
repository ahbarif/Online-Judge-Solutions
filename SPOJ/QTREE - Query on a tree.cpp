// HLD with edge update
#include<bits/stdc++.h>
using namespace std;

const int maxn = 10002, maxLog = 14;
vector<int> adj[maxn], costs[maxn], indexx[maxn];
int baseArray[maxn], ptr;
int chainNo, chainInd[maxn], chainHead[maxn], posInBase[maxn];
int level[maxn], P[maxLog][maxn], otherEnd[maxn], subSize[maxn];
int tree[maxn*6];

void dfs(int u, int par, int depth = 0) {
    P[0][u] = par;
    level[u] = depth;
    subSize[u] = 1;

    for(int i = 0; i<adj[u].size(); i++) {
        int v = adj[u][i];
        if(v!=par) {
            otherEnd[indexx[u][i]] = v;
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

    tree[node] = tree[l]>tree[r]?tree[l]:tree[r];
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
    tree[node] = tree[l]>tree[r]?tree[l]:tree[r];

}

int tree_query(int node, int lo, int hi, int i, int j) {
    if(i>hi || j<lo)    return -1;

    if(i<=lo && j>=hi)  {
        return tree[node];
    }

    int left  = 2*node;
    int right = left + 1;
    int mid   = (lo+hi)>>1;

    int x = tree_query(left, lo, mid, i, j);
    int y = tree_query(right, mid+1, hi, i, j);

    return (x>y?x:y);
}

int query_up(int u, int v) { // v is ancestor
    if(u==v) return 0;

    int uChain, vChain = chainInd[v], ret = -1;

    while(true) {
        uChain = chainInd[u];

        if(uChain == vChain) {
            int x = tree_query(1, 0, ptr, posInBase[v] + 1, posInBase[u]);
            if(x>ret) ret = x;
            break;
        }

        int x = tree_query(1, 0, ptr, posInBase[chainHead[uChain]], posInBase[u]);
        if(x>ret) ret = x;
        u = chainHead[uChain];
        u = P[0][u];

    }

    return ret;
}

void query(int u, int v) {
    int lca = LCA(u, v);
    int ret1 = query_up(u, lca);
    int ret2 = query_up(v, lca);
    int ret = (ret1>ret2?ret1:ret2);
    printf("%d\n", ret);
}
void update(int i, int val) {
    int u = otherEnd[i];
    update_tree(1, 0, ptr, posInBase[u], val);
}

void HLD(int curNode, int cost, int par) {

    if(chainHead[chainNo] == -1) chainHead[chainNo] = curNode;

    chainInd[curNode] = chainNo;
    posInBase[curNode] = ptr;

    baseArray[ptr++] = cost;

    int heavyChild = -1, nCost;

    for(int i = 0; i<adj[curNode].size(); i++) {
        int v = adj[curNode][i];
        if(v!=par) {
            if(heavyChild == -1 || subSize[heavyChild] < subSize[v]) {
                heavyChild = v;
                nCost = costs[curNode][i];
            }
        }
    }

    if(heavyChild != -1) {
        HLD(heavyChild, nCost, curNode);
    }

    for(int i = 0; i<adj[curNode].size(); i++) {
        int v = adj[curNode][i];
        if(v!=par && v!= heavyChild) {
            ++chainNo;
            HLD(v, costs[curNode][i], curNode);
        }
    }

}

void init(int n) {
    for(int i = 0; i<=n; i++) {
        adj[i].clear();
        costs[i].clear();
        indexx[i].clear();
        chainHead[i] = -1;
        for(int j = 0; j<maxLog; j++) P[j][i] = -1;
    }
}


int main() {

#ifdef local
    freopen("in.txt", "r", stdin);
#endif

    int test;

    scanf("%d", &test);

    while(test--) {

        ptr = 0;

        int n, q, root = 0;

        scanf("%d", &n);

        init(n);

        for(int i=1; i<n; i++) {
            int u, v, c;
            scanf("%d %d %d", &u, &v, &c);
            u--;
            v--;
            adj[u].push_back(v);
            costs[u].push_back(c);
            indexx[u].push_back(i-1);
            adj[v].push_back(u);
            costs[v].push_back(c);
            indexx[v].push_back(i-1);

        }

        chainNo = 0;
        dfs(root, -1);
        HLD(root, -1, -1);
        ptr--;

        make_tree(1, 0, ptr);


        for(int i=1; i<maxLog; i++)
            for(int j=0; j<n; j++)
                if(P[i-1][j] != -1)
                    P[i][j] = P[i-1][P[i-1][j]];


        char s[10];

        while(true) {
            scanf("%s", s);

            if(s[0] == 'D') break;

            if(s[0]=='Q') {
                int i, v;
                scanf("%d %d", &i, &v);
                i--;
                v--;
                query(i, v);
            } else {
                int i, v;
                scanf("%d %d", &i, &v);
                i--;
                update(i, v);
            }
        }

    }


    return 0;
}
