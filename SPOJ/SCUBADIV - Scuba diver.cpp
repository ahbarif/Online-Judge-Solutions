#include <bits/stdc++.h>
using namespace std;

int dp[1003][22][80], inf = 10000000, n;
int oxygen[1003], nitrogen[1003], weight[1003];

int f(int pos, int oxy, int nitro){

    if(pos>n){
      if(oxy == 0 && nitro == 0) return 0;
      else return inf;
    }

    int &ret = dp[pos][oxy][nitro];

    if(ret != -1) return ret;

    ret = inf;

    // case 1: nibo na
    ret = min(ret, f(pos+1, oxy, nitro));

    int nt = nitrogen[pos];
    int ot = oxygen[pos];
    int wt = weight[pos];

    ret = min(ret, wt + f(pos+1, max(0, oxy-ot), max(0, nitro-nt)));

    return ret;

}



int main()
{

    int test;

    scanf("%d", &test);

    while(test--){
        int ot, nt;

        scanf("%d %d", &ot, &nt);

        scanf("%d", &n);

        for(int i = 1; i<=n; i++) scanf("%d %d %d", &oxygen[i], &nitrogen[i], &weight[i]);

        memset(dp, -1, sizeof(dp));

        printf("%d\n", f(1, ot, nt));
    }


	return 0;
}

