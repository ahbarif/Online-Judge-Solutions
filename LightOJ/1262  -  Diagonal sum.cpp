#include<bits/stdc++.h>
using namespace std;

const int maxn = 20055;
const int inf = 1010101;

struct edge{
    int from, to, cap, flow;
};

vector<edge> edges;
vector<int> G[maxn];

int cur[maxn];

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

void solve(int cs){

    init();

    int n, m;

    cin>>n>>m;

    int offset = n+m-1, source = 0, sink = 2*offset + 10;

    for(int i = 1; i<=offset; i++){
        int x;
        cin>>x;

        x -= min(n, i) - max(0, i-m);

        addEdge(source, i, x);
    }


    for(int i = 1; i<=offset; i++){
        int x;
        cin>>x;

        x -= min(n, i) - max(0, i-m);

        addEdge(i + offset, sink, x);
    }

    int st = edges.size();

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            addEdge(i+j-1, m+i-j + offset, 99);
        }
    }

    int f = dinic(source, sink);

    printf("Case %d:\n", cs);
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            cout<<edges[st].flow+1;
            st += 2;
        if(j==m) puts("");
        else printf(" ");
        }
    }

    return;

}

int main(){



  //  freopen("in.txt", "r", stdin);

    int test, cs = 0;

    scanf("%d", &test);

    while(test--){
        solve(++cs);
    }

    return 0;
}

