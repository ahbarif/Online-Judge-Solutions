#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[1<<16][2][2];
int a[18][18], n;

ll foo(int mask, int row, int sup, int all)
{
    if(__builtin_popcount(mask) == n) {
        return ( sup || all );
    }

    ll &ret = dp[mask][sup][all];

    if(ret != -1) return ret;

    ret = 0;

    for(int i = 0; i<n; i++)
    {
        if((mask & (1<<i))== 0){
            ret += foo( mask | ( 1 << i ), row + 1 , sup || a[row][i]==2 , all && a[row][i] == 1 );

        }
    }
    return ret ;
}


int main()
{

   int test, cs = 0;

   scanf("%d", &test);

   while(test--){

        memset(dp, -1, sizeof(dp));
        scanf("%d", &n);

        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                scanf("%d", &a[i][j]);
            }
        }

        ll ret = foo(0, 0, 0, 1);

        printf("Case %d: %lld\n", ++cs, ret);

   }

    return 0;
}

