#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline T bigmod(T a, T b, T mod)
{
    T ans = 1;
    while(b)
    {
        if(b&1) ans = (ans*a)%mod;
        a = (a*a)%mod;
        b = b>>1;
    }
    return ans%mod;
}
void solve(ll n, ll p)
{
    if(n>=p)
    {
        puts("0");
        return;
    }
     ll ans = -1;
     for(ll i = n+1; i<p; i++)
    {
        ll x = i;
        ll tmp = bigmod(x, p-2, p);
         ans = (ans%p) * (tmp%p);
         ans%=p;
    }
     cout<<ans+p<<endl;
}
   int main()
{
    int i, t;
     cin>>t;
     while(t--)
    {
       ll n, p;
        cin>>n>>p;
        solve(n, p);
    }
     return 0;
}
