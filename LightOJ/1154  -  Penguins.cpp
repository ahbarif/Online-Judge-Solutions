#include<bits/stdc++.h>
using namespace std;

const int maxn = 205;
const int inf = INT_MAX;
struct edge{
    int from, to, cap, flow;
};

vector<edge> edges;

vector<int> G[maxn];
    pair<int, int> points[105];

void init() {
//    sum = 0;
//    cnt = 0;
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

int cur[maxn];

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

double eps = 1e-9;
double dist(int xi, int yi, int xj, int yj){
    return sqrt((xi-xj)*(xi-xj) + (yi-yj)*(yi-yj));
}

void ClearFlow(){

    for(int i = 0; i<edges.size(); i++) edges[i].flow = 0;
}

void solve(int cs){

    init();

    double maxD;
    int icePack;

    cin>>icePack>>maxD;
    int source = 2*icePack + 2, tot = 0;

    for(int i = 0; i<icePack; i++){

        int cur, cap;

        cin>>points[i].first>>points[i].second>>cur>>cap;

        tot += cur;
        addEdge(source, i, cur);
        addEdge(i, i+icePack, cap);

        for(int j = 0; j<i; j++){

            double d = dist(points[i].first, points[i].second, points[j].first, points[j].second);

            if((d+eps) <= maxD){
                addEdge(i+icePack, j, inf);
                addEdge(j+icePack, i, inf);
            }
        }
    }
    printf("Case %d: ", cs);
    bool ok = 0;

    for(int i = 0; i<icePack; i++){
        ClearFlow();

        int flow = dinic(source, i);

        if(flow==tot){
            if(ok) printf(" ");
            printf("%d", i);
            ok = 1;
        }
    }

    if(!ok) puts("-1");
    else puts("");


}

int main(){

    int test, cs = 0;

    scanf("%d", &test);

    while(test--){
        solve(++cs);
    }

    return 0;
}



