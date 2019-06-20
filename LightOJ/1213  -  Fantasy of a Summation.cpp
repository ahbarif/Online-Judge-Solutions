#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll bigmod(ll a, ll b, ll mod)
{
    ll ans = 1;

    while(b)
    {
        if(b&1) ans = (ans*a)%mod;
        a = (a*a)%mod;
        b = b>>1;
    }
    return ans%mod;
}

int main()
{
    int test, cs = 0;
    long long mod, n, k;
    scanf("%d", &test);

    while(test--)
    {
        scanf("%lld %lld %lld", &n, &k, &mod);

        ll sum = 0;

        for(int i = 0; i<n; i++)
        {
            ll x;

            scanf("%lld", &x);

            sum+=x;

            sum%=mod;
        }

        ll power = bigmod(n, k-1, mod);

        ll res = (power%mod) * (sum%mod);

        res = (res%mod) *(k%mod);

        printf("Case %d: %lld\n", ++cs, res%mod);


    }
    return 0;
}
