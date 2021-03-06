#include<bits/stdc++.h>
using namespace std;

const int maxn = 2010;
vector<int> adj[maxn];
vector<pair<string, string> > v;
const int inf = 1010101;

struct edge{
    int from, to, cap, flow;
};

vector<edge> edges;
vector<int> G[maxn];
int cur[maxn];

void init(){
    for(int i = 0; i<maxn; i++) G[i].clear();
    edges.clear();
    v.clear();
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


int main()
{

//   freopen("in.txt", "r", stdin);

    int cs = 0, test;

    cin>>test;

    while(test--){

        init();

        int mv, fv, voters;

        scanf("%d %d %d", &mv, &fv, &voters);

        int source = 2*voters, sink = source+1;

        for(int i = 0; i<voters; i++){
        	addEdge(source, i, 1);
        	addEdge(voters+i, sink, 1);
        }

        for(int i = 0; i<voters; i++){

            string s1, s2;

            cin>>s1>>s2;

            v.push_back(make_pair(s1, s2));
        }

        for(int i = 0; i<v.size(); i++){

            if(v[i].first[0]=='F') continue;

            for(int j = 0; j<v.size(); j++){
                if(v[j].first[0]=='M') continue;

                if(v[i].first == v[j].second || v[i].second == v[j].first){
                    addEdge(i, j+voters, 1);
                }
            }
        }

        int maxMatch = dinic(source, sink);

        int ret = voters - maxMatch;

        printf("Case %d: %d\n", ++cs, ret);

    }

    return 0;
}



