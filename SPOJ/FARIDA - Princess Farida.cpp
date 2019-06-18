#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[10004], ar[10004], n;
ll f(ll pos){
    if(pos>n) return 0;
     if(dp[pos] != -1) return dp[pos];
     ll ret = 0;
     ret = max(ret, f(pos+1));
    ret = max(ret, f(pos+2)+ar[pos]);
     return dp[pos] = ret;
}
int main() {
     int test, cs = 0;
     scanf("%d", &test);
     while(test--){
         scanf("%lld", &n);
         for(int i = 1; i<=n; i++) scanf("%lld", &ar[i]);
         memset(dp, -1, sizeof(dp));
         ll ret = f(1);
         printf("Case %d: ", ++cs);
         cout<<ret<<endl;
    }
}
