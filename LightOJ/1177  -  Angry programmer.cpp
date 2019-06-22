#include<bits/stdc++.h>
using namespace std;

const int maxn = 255;

int cap[maxn][maxn], par[maxn], minCap[maxn];

bool getpath(int src, int dst, int nodes)
{
    memset(par, -1, sizeof(par));

    for(int i = 1; i<=nodes; i++) minCap[i] = INT_MAX;

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
  //  cap[v][u] += w;
}

int out(int u, int n){
    if(u==1 || u==n) return u;
    return u+n;
}

void solve(int cs){

    memset(cap, 0, sizeof(cap));

    int n, m;

    scanf("%d %d", &n, &m);

    for(int i = 2; i<n; i++){
        int x;
        scanf("%d", &x);

        addEdge(i, i+n, x);
      //  addEdge(v, u, x);
    }

    for(int i = 0; i<m; i++){
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        addEdge(out(u, n), v, w);
        addEdge(out(v, n), u, w);

    }

   // cout<<getpath(1, n, 100)<<endl;

    int minCut = Edmond_Karp(1, n, 2*n);

    printf("Case %d: %d\n", cs, max(0, minCut));

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



