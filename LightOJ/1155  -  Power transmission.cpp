#include<bits/stdc++.h>
using namespace std;

const int maxn = 255;

int cap[maxn][maxn], par[maxn], minCap[maxn];

bool getpath(int src, int dst, int nodes)
{
    memset(par, -1, sizeof(par));

    for(int i = 0; i<=nodes; i++) minCap[i] = INT_MAX;

    queue<int> q;

    q.push(src);

    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i=1; i<=nodes; i++)
        {
            if(cap[u][i] != 0 && par[i] == -1)
            {
                par[i] = u;
                minCap[i] = min(minCap[u], cap[u][i]);
                if(i == dst) return true;
                q.push(i);
            }
        }
    }
    return false;
}

int Edmond_Karp(int src, int dst, int nodes)
{
    int maxFlow = 0;

    while(getpath(src, dst, nodes))
    {

        int ff = minCap[dst];

        maxFlow += ff;

        int u = dst;

        while(u != src)
        {
            int v = par[u];
            cap[u][v] += ff;
            cap[v][u] -= ff;
            u = v;
        }
    }

    return maxFlow;
}

void addEdge(int u, int v, int w){
    cap[u][v] += w;
}

void split(int node, int n, int cap){

    addEdge(node, node+n, cap);
}

void solve(int cs){

    memset(cap, 0, sizeof(cap));

    int source = 0, sink = 201;

    int n, m;

    scanf("%d", &n);

    for(int i = 1; i<=n; i++) {
        int c;
        scanf("%d", &c);
        split(i, n, c);
    }

    scanf("%d", &m);

    for(int i = 1; i<=m; i++){
        int u, v, w;

        scanf("%d %d %d", &u, &v, &w);

        addEdge(u+n, v, w);

    }

    int b, d;

    scanf("%d %d", &b, &d);

    for(int i = 0; i<b; i++){
        int v;
        scanf("%d", &v);
        addEdge(source, v, INT_MAX);
    }

    for(int i = 0; i<d; i++){
        int v;
        scanf("%d", &v);
        addEdge(v+n, sink, INT_MAX);
    }


    int maxFlow = Edmond_Karp(source, sink, 201);

    printf("Case %d: %d\n", cs, maxFlow);


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



