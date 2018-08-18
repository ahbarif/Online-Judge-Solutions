#include<bits/stdc++.h>
using namespace std;

int n, m;
long long d[16][16], ax[16], ay[16];
int degree[16];
long long dp[1<<16], inf = 1000000000000000LL;

long long dist(int i, int j) {
    return (ax[i] - ax[j])*(ax[i]-ax[j]) + (ay[i] - ay[j])*(ay[i]-ay[j]);
}

void Warshall(int n) {

    for(int k = 0; k<n; k++) {
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
            }
        }
    }
}

void init() {
    memset(degree, 0, sizeof(degree));
}

long long f(int mask) {

    if(n - __builtin_popcount(mask) <= 2) return 0;

    if(dp[mask] != -1) return dp[mask];

    long long ret = inf;

    for(int i = 0; i<n; i++) {
        for(int j = 0; j<n; j++) {
            if((mask&(1<<i)) == 0 && (mask&(1<<j)) == 0 && i!=j) {
                long long tmp = mask;
                tmp |= (1<<i);
                tmp |= (1<<j);
                long long foo = f(tmp) + d[i][j];
              //  cout<<"foo = "<<foo<<endl;
                ret = min(ret, foo);
            }
        }
    }

    return dp[mask] = ret;
}

int main() {

   // freopen("in.txt", "r", stdin);

    int test, cs = 0;

    cin>>test;

    while(test--) {

        init();

        scanf("%d", &n);

        for(int i = 0; i<n; i++) cin>>ax[i]>>ay[i];

        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                d[i][j] = dist(i, j);
            }
        }

        scanf("%d", &m);

        while(m--) {
            int u, v;

            cin>>u>>v;

            degree[u]++;
            degree[v]++;
        }

        int mask = 0;

        for(int i = 0; i<n; i++) {
            if(degree[i]%2==0) mask |= (1<<i);
        }

        Warshall(n);

        memset(dp, -1, sizeof(dp));

        long long ret = f(mask);

        printf("Case %d: %lld\n", ++cs, ret);

    }



    return 0;
}
