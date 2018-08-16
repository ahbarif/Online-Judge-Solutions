// HLD with merge sort tree
#include<bits/stdc++.h>
using namespace std;

const int maxn = 100001, maxLog = 18, mxn = 0;
vector<int> adj[maxn];
int baseArray[maxn], ptr;
int chainNo, chainInd[maxn], chainHead[maxn], posInBase[maxn];
int level[maxn], P[maxLog][maxn], subSize[maxn], costs[maxn];
vector<int> tree[maxn*4];


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

void merge__(int cur, int l, int r){

    tree[cur].clear();
    int i = 0, ls = tree[l].size();
    int j = 0, rs = tree[r].size();

    while(i<ls && j<rs){
        if(tree[l][i]<tree[r][j]) tree[cur].push_back(tree[l][i++]);
        else tree[cur].push_back(tree[r][j++]);
    }

    for(int x = i; x<ls; x++) tree[cur].push_back(tree[l][x]);
    for(int x = j; x<rs; x++) tree[cur].push_back(tree[r][x]);
}

void make_tree(int cur, int l, int r ) {

    if(l==r) {
        tree[cur].clear();
        tree[cur].push_back(baseArray[l]);
        return ;
    }
    int mid = (l+r)/2;
    make_tree(2*cur, l, mid );
    make_tree(2*cur+1, mid+1, r );

    merge__(cur, 2*cur, 2*cur + 1);
}

bool tree_query( int cur, int l, int r, int x, int y, int k) {
    if( r < x || l > y ) {
        return 0; //out of range
    }
    if( x<=l && r<=y ) {

        int p = lower_bound(tree[cur].begin(), tree[cur].end(), k) - tree[cur].begin();

        if(p == tree[cur].size()) return 0;

        if(tree[cur][p] == k) return true;
        return false;
    }

    int mid = (l+r)/2;
    return tree_query(2*cur,l,mid,x,y,k)|tree_query(2*cur+1,mid+1,r,x,y,k);
}

bool query_up(int u, int v, int c) {

    if(u==v) return (costs[u]==c);

    int uChain, vChain = chainInd[v];

    bool ret = false;

    while(true) {
        uChain = chainInd[u];

        if(uChain == vChain) {
            bool x = tree_query(1, 0, ptr-1, posInBase[v], posInBase[u], c);
            ret |= x;
            break;
        }

        bool x = tree_query(1, 0, ptr-1, posInBase[chainHead[uChain]], posInBase[u], c);
        ret |=x;
        u = chainHead[uChain];
        u = P[0][u];
    }

    return ret;
}

void query(int u, int v, int c) {
    int lca = LCA(u, v);
    bool ret = query_up(u, lca, c);
    if(ret) {
        puts("Find");
        return;
    }
    ret = query_up(v, lca, c);

    if(ret) {
        puts("Find");
        return;
    }

    printf("NotFind\n");
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


    int n, q, root = 0;


    while(scanf("%d %d", &n, &q) != EOF) {

        ptr = 0;


        init(n);

        for(int i = 0; i<n; i++) scanf("%d", &costs[i]);

        for(int i=1; i<n; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            u--;
            v--;
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


        while(q--) {
            int c, u, v;
            scanf("%d %d %d", &u, &v, &c);
            query(u-1, v-1, c);

        }
        puts("");

    }
    return 0;
}
