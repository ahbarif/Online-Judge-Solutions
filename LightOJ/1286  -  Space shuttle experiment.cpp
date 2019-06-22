#include<bits/stdc++.h>
using namespace std;

const int maxn = 255;

typedef long long Long;

int cap[maxn][maxn], par[maxn], minCap[maxn], a[maxn];

bool getpath(int src, int dst, int nodes)
{
    memset(par,-1,sizeof(par));

    for(int i = 0; i<=nodes; i++) minCap[i] = INT_MAX;

    queue<int> q;

    q.push(src);

    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i=0; i<=nodes; i++)
        {
            if(cap[u][i]!=0 && par[i]==-1)
            {
                par[i]=u;
                minCap[i] = min(minCap[u], cap[u][i]);
                if(i==dst) return true;
                q.push(i);
            }
        }
    }
    return false;
}

int Edmond_Karp(int src, int dst, int nodes)
{
    Long maxFlow = 0;

    while(getpath(src, dst, nodes))
    {

        Long ff = minCap[dst];

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

void solve(int cs){

    memset(cap, 0, sizeof(cap));

    int nodes, exps, profit = 0;

    scanf("%d %d", &nodes, &exps);

    for(int i = 1; i<=nodes; i++){
        int x;
        scanf("%d", &x);
        a[i]= x;
        addEdge(0, i, x);
        profit += x;
    }

    for(int i = 1; i<=exps; i++){
        int x;
        scanf("%d", &x);
        addEdge(i + nodes, nodes+exps + 1, x);
    }

    for(int i = 1; i<=nodes; i++){
        int tot, x;
        scanf("%d", &tot);
        while(tot--){
            scanf("%d", &x);
            addEdge(i, x+nodes, a[i]);
        }

    }

    int maxFlow = Edmond_Karp(0, nodes + exps + 1, nodes + exps + 1);

    int minCut = profit - maxFlow;

    printf("Case %d: %d\n", cs, max(0, minCut));

    return;

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

