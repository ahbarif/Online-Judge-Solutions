#include <bits/stdc++.h>
using namespace std;

const int maxn = 505, inf = 10000000;

int adj[maxn][maxn];

bool vis[maxn];

vector<int> dijkstra(int src, int n){

    vector<int> d;
    for(int i = 0; i<n; i++) d.push_back(inf);
    d[src] = 0;
    priority_queue<pair<int, int> > pq;

    pq.push(make_pair(0, src));


    while(pq.size()!=0){
        pair<int, int> top = pq.top();

        pq.pop();

        int u = top.second;

        for(int i = 0; i<n; i++){

            if(adj[u][i] != 0){
                int c = adj[u][i];

                if(vis[i]) continue;

                int v = i;

                if(d[v] > d[u] + c) {
                    d[v] = d[u] + c;
                    pq.push(make_pair(-d[v], v));
                }
            }
        }
    }

    return d;
}

void rev(int n){
    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            swap(adj[i][j], adj[j][i]);
        }
    }
}

int main()
{

        int n, m;

        while(scanf("%d %d", &n, &m) && (n|m)){
            int src, dst;

            scanf("%d %d", &src, &dst);

            memset(adj, 0, sizeof(adj));
            memset(vis, 0, sizeof(vis));

            for(int i = 0; i<m; i++){
                int u, v, w;
                scanf("%d %d %d", &u, &v, &w);
                adj[v][u] = w;
            }

            vector<int> disFromDestination = dijkstra(dst, n);

            rev(n);

            vector<int> disFromSource = dijkstra(src, n);


            int minDis = disFromSource[dst];


            for(int i = 0; i<n; i++){
                if(i == src || i == dst) continue;

                if(disFromSource[i] + disFromDestination[i] == minDis){
                    vis[i] = 1;
                }
            }

            if(adj[src][dst] && adj[src][dst] == minDis){
                adj[src][dst] = 0;
            }

            disFromSource = dijkstra(src, n);

            if(disFromSource[dst] == inf) cout<<"-1"<<endl;

            else cout<<disFromSource[dst]<<endl;


        }


		return 0;

}

