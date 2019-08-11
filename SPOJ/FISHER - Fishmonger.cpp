#include <bits/stdc++.h>
using namespace std;

const int N = 55;
int cost[N][N], adj[N][N];
int d[N][1005];

struct node {
    int u, t, w;
    node(int u, int t, int w):u(u), t(t), w(w) {}
    bool operator<(const node &p) const {
        return w>p.w;
    }
};

void dijsktra(int n, int rem) {

    memset(d, 1, sizeof(d));
   
    for(int i = 1; i<=rem; i++) d[1][i] = 0;

    priority_queue<node> pq;

    pq.push(node(1, 0, 0));

    while(!pq.empty()) {
        node top = pq.top();
        pq.pop();

        //  cout<<"top = "<<top.u<<" "<<top.t<<" "<<top.w<<endl;

        for(int v = 1; v<=n; v++) {
            if(v == top.u) continue;
            int toll = cost[top.u][v];
            int tme = adj[top.u][v];

            int newCost = top.w + toll;
            int newTime = top.t + tme;
            if(newTime > rem) continue;

            if(newCost < d[v][newTime]) {

                node newNode = node(v, newTime, newCost);
                pq.push(newNode);
                d[v][newTime] = newCost;
            }
        }
    }

    int ret = INT_MAX, tmm;

    for(int i = 1; i<=rem; i++){
      if(d[n][i] < ret){
        ret = d[n][i];
        tmm = i;
      }
    }

    cout<<ret<<" "<<tmm<<endl;
}




int main() {

#ifdef local
    freopen("in.txt", "r", stdin);
#endif

    int n, m;

    while(cin>>n>>m) {

        if(n == 0 && m == 0) break;

        for(int i = 1; i<=n; i++) {
            for(int j = 1; j<=n; j++) cin>>adj[i][j];
        }

        for(int i = 1; i<=n; i++) {
            for(int j = 1; j<=n; j++) cin>>cost[i][j];
        }

        dijsktra(n, m);

    }

    return 0;

}
