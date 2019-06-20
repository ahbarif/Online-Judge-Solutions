#include<bits/stdc++.h>
using namespace std;

int n, m;
long long d[16][16];
int degree[16];
long long dp[1<<16], inf = 1000000000000000LL;

void Warshall(int n){

    for(int k = 0; k<n; k++){
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
            }
        }
    }
}

void init(){
    for(int i = 0; i<16; i++){
        for(int j = 0; j<16; j++){
            d[i][j] = inf;
        }
    }
    for(int i = 0; i<16; i++) d[i][i] = 0;
    memset(degree, 0, sizeof(degree));
}

long long f(int mask){

    if(__builtin_popcount(mask) == n) return 0;

    if(dp[mask] != -1) return dp[mask];

    int pos;

    for(pos = 0; pos<n; pos++){
    	if((mask&(1<<pos))==0){
    		break;
    	}
    }

    long long ret = inf;

    for(int i = pos+1; i<n; i++){
    	
    	if((mask&(1<<i))==0){
    		int subMask = mask|(1<<pos);
    		subMask |= (1<<i);

    		long long temp = d[pos][i] + f(subMask|(1<<i));
    		ret = min(ret, temp);
    	}
    }

 
    return dp[mask] = ret;




}

int CreateMask(){
	int mask = 0;
	for(int i = 0; i<n; i++){
		if(degree[i]%2==0){
			mask |= (1<<i);
		}
	}

	return mask;
}

int main()
{

 //   freopen("in.txt", "r", stdin);

    int test, cs = 0;

    cin>>test;

    while(test--){

        init();

        scanf("%d %d", &n, &m);
    
        long long int tot = 0;

        while(m--){
            int u, v;
            long long w;

            scanf("%d %d %lld", &u, &v, &w);

            u--;
            v--;

            d[u][v] = min(d[u][v], w);
            d[v][u] = min(d[v][u], w);

            tot += w;
            degree[u]++;
            degree[v]++;
        }

        bool eulerian = true;

        for(int i = 0; i<n; i++){
            if(degree[i]&1){
                eulerian = false;
                break;
            }
        }

        if(eulerian){
            printf("Case %d: %lld\n", ++cs, tot);
            continue;
        }

        Warshall(n);

        memset(dp, -1, sizeof(dp));

        int mask = CreateMask();
        long long ex = f(mask);

        long long ret = tot + ex;

        printf("Case %d: %lld\n", ++cs, ret);
    
    }



    return 0;
}



