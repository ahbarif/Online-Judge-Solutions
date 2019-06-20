#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
const int mx = 1005;
const ll mod = 1000000007LL;
 
ll combination[mx][mx];
ll derangement[mx][mx];
ll fact[mx];
 
ll nCr(ll n, ll r)
{
 
    if(n == r || r == 0)    return 1;
 
    else if(r == 1)   return n;
 
    if(combination[n][r]!=-1)    return combination[n][r];
 
    int res1 = nCr(n-1, r) % mod;
    int res2 = nCr(n-1, r-1) % mod;
 
    return combination[n][r] = (res1+res2) % mod;
 
}
 
ll permute(int n, int m)
{
    if(m==0)    return fact[n];
    if(m==1)    return (fact[n-1]*(n-1)) % mod;
 
    if(derangement[n][m] != -1) return derangement[n][m];
 
    ll x = permute(n-1, m-2) * (m-1);
    ll y = permute(n-1, m-1) * (n-m);
 
    return derangement[n][m] = ((x%mod) + (y%mod))%mod;
 
}
 
void calc()
{
    memset(combination, -1, sizeof(combination));
 
    memset(derangement, -1, sizeof(derangement));
 
    fact[0] = fact[1] = 1;
 
    for(int i=2; i<=1005; i++)  fact[i] = ((fact[i-1]%mod) * (i))%mod;
 
}
 
int main()
{
 
    calc();
 
    int test, cs = 0;
 
    scanf("%d", &test);
 
    while(test--)
    {
        ll n, m, k;
 
        scanf("%lld %lld %lld", &n, &m, &k);
 
        ll res = nCr(m, k) * permute(n-k, m-k);
 
        printf("Case %d: %lld\n", ++cs, res%mod);
    }
 
    return 0;
}
 