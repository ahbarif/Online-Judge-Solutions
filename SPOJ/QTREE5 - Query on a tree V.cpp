#include<bits/stdc++.h>
using namespace std;

const int maxn = 100002, maxlog = 18, inf = 10000000;
int parent[maxn], P[maxn][maxlog+1], L[maxn], nn, sub[maxn], color[maxn];
set<int> adj[maxn];
multiset<pair<int, int> > st[maxn];

void dfs_lca(int u, int depth){

    L[u] = depth;

    for(auto v: adj[u]){
        if(L[v] == -1){
            parent[v] = u;
            dfs_lca(v, depth+1);
        }
    }
}

void preprocess_lca(int root, int N){

    memset(parent, -1, sizeof(parent));
    memset(L, -1, sizeof(L));

    dfs_lca(root, 0);

    for(int i = 0 ; i <= N ; ++i)  P[i][0] = parent[i];

    for(int j = 1; (1<<j) < N; ++j){
        for(int i = 1; i <= N; ++i){
            if(P[i][j-1] != -1){
                P[i][j] = P[P[i][j-1]][j-1] ;
            }
        }
    }
}


int lca(int u , int v)
{
	if(L[u] < L[v])
	swap(u , v);

	int log = 0;
	while( (1<<log) <= L[u]) log++;
	log -=1;

	for(int i= log; i >= 0; i--)
	{
		if( (L[u] - (1<<i)) >= L[v])
		{
			u = P[u][i];
		}
	}
	if(u == v) return u;
	for(int i= log; i >= 0; i--)
	{
		if(P[u][i]!=-1 && P[u][i] != P[v][i])
		{
			u = P[u][i];
			v = P[v][i];
		}
	}
	return P[u][0];
}
int dist(int u, int v){
    return L[u] + L[v] - 2 * L[lca(u, v)];
}

void getSize(int u, int par){
    nn++;
    sub[u] = 1;

    for(auto v: adj[u]){
        if(v != par){
            getSize(v, u);
            sub[u] += sub[v];
        }
    }
}

int getCentroid(int u, int par){

    for(auto v: adj[u]){
        if(v!=par){
            if(sub[v] > nn/2){
                return getCentroid(v, u);
            }
        }
    }
    return u;
}

void decompose(int u, int par){
    nn = 0;
    getSize(u, -1);

    int centroid = getCentroid(u, -1);

    parent[centroid] = par;

    for(auto v: adj[centroid]){
        adj[v].erase(centroid);
        if(v != par){
            decompose(v, centroid);
        }
    }

    adj[centroid].clear();
}

void update(int u, bool on){
    int x = u;

    while(true){
        if(on)  st[x].insert(make_pair(dist(x, u), u));
        else st[x].erase(make_pair(dist(x, u),u));
        x = parent[x];
        if(x == -1){
            break;
        }
    }
}

void toggle(int u){
    if(color[u] == 0){
        update(u, true);
    }
    else update(u, false);

    color[u] ^= 1;
}

int query(int u){

    int x = u, ret = inf;

    while(true){

        if(st[x].size()!=0){
            pair<int, int> d = *st[x].begin();

            ret = min(ret, d.first + dist(x, u));

        }

        if(parent[x] == -1) break;

        x = parent[x];
    }

    if(ret == inf) ret = -1;

    return ret;
}

int main()
{
	#ifdef local
	    freopen("in.txt", "r", stdin);
	#endif

	int n, q;

	scanf("%d", &n);

	for(int i = 1; i<n; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].insert(v);
        adj[v].insert(u);
	}

	preprocess_lca(1, n);

	decompose(1, -1);

	scanf("%d", &q);

	while(q--){
        int u, v;
        scanf("%d %d", &u, &v);
        if(u == 0) toggle(v);
        else{
            int ret = query(v);
            printf("%d\n", ret);
        }
	}


    return 0;
}
