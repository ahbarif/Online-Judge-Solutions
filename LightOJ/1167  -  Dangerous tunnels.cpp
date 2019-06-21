#include<bits/stdc++.h>
using namespace std;

const int maxn = 255;

const int inf = 1010101;
struct edge{
    int from, to, cap, flow;
};

vector<edge> edges;
vector<int> G[maxn];
int cur[maxn], a[maxn];
bool big[maxn];
int u[10005], v[10005], cc[10005];


void init() {
    for (int i = 0; i < maxn; i++) G[i].clear();
    edges.clear();
}

void addEdge(int from, int to, int cap) {
    edges.push_back((edge){from, to, cap, 0});
    edges.push_back((edge){to, from, 0, 0});
    int m = edges.size();
    G[from].push_back(m - 2);
    G[to].push_back(m - 1);
}

int vis[maxn], d[maxn];

bool BFS(int source, int sink) {
    memset(vis, 0, sizeof(vis));
    queue<int> Q;
    Q.push(source);
    d[source] = 0;
    vis[source] = 1;
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        for (int i = 0; i < G[u].size(); i++) {
            edge &e = edges[G[u][i]];
            if (!vis[e.to] && e.cap > e.flow) {
                vis[e.to] = 1;
                d[e.to] = d[u] + 1;
                Q.push(e.to);
            }
        }
    }
    return vis[sink];
}


int DFS(int u, int sink, int a) {
    if (u == sink || a == 0) return a;
    int flow = 0, f;
    for (int &i = cur[u]; i < G[u].size(); i++) {
        edge &e = edges[G[u][i]];
        if (d[u] + 1 == d[e.to] && (f = DFS(e.to, sink, min(a, e.cap - e.flow))) > 0) {
            e.flow += f;
            edges[G[u][i]^1].flow -= f;
            flow += f;
            a -= f;
            if (a == 0) break;
        }
    }
    return flow;
}

int dinic(int source, int sink){
    int ans = 0;
    while (BFS(source, sink)) {
        memset(cur, 0, sizeof(cur));
        ans += DFS(source, sink, inf);
    }
    return ans;

}


    int n, m, k;

bool ok(int mid){
    init();

    int source = 221;
    int sink = 231;

    for(int i = 1; i<=n; i++) {
        addEdge(i, i+n+2, 1);
    }

    addEdge(0, n+2, k);
    addEdge(n+1, n+1+n+2, k);

    for(int i = 1; i<=m; i++){

        if(cc[i]<=mid){
            addEdge(u[i]+(n+2), v[i], 1);
        }
    }

    addEdge(source, 0, k);
    addEdge(n+1+n+2, sink, k);

    return dinic(source, sink)==k;



}

void solve(int cs){

    memset(big, 0, sizeof(big));

    scanf("%d %d", &n, &m);

    for(int i = 1; i<=m; i++) {
        scanf("%d %d %d", &u[i], &v[i], &cc[i]);
        if(u[i]>v[i])  swap(u[i], v[i]);
    }
    cin>>k;


    int lo = 1, hi = 100000, mid, res = inf;

    while(lo<hi){
        mid = (lo+hi)/2;
        if(ok(mid)){
            res = min(res, mid);
            hi = mid;
        }
        else lo = mid+1;

    }

    printf("Case %d: ", cs);
    if(res==inf) puts("no solution");
    else printf("%d\n", res);

}

int main(){

   // freopen("in.txt", "r", stdin);
    int test, cs = 0;

    scanf("%d", &test);

    while(test--){
        solve(++cs);
    }

    return 0;
}



