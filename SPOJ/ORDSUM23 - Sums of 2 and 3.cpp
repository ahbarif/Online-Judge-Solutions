#include<bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
typedef long long ll;
ll dp[1000002];
ll f(ll n){
     if(n==0) return 1;
     else if(n<0) return 0;
     if(dp[n] != -1) return dp[n];
     ll x = 0, y = 0;
     if(n>=3) x = f(n-3);
    if(n>=2) y = f(n-2);
     return dp[n] = (x+y)%mod;
}
int main()
{
     memset(dp, -1, sizeof(dp));
     int test;
     scanf("%d", &test);
     while(test--){
         int x;
         scanf("%d", &x);
         printf("%lld\n", f(x));
    }
}
