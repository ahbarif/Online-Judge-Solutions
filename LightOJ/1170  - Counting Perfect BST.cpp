#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = 100000007LL;
const int mx = 1000001;

ll fact[2*mx];
ll cat[mx];

ll bigmod(ll a, ll b, ll mod)
{
    ll ans = 1;
    while(b){
        if(b&1) ans = (ans*a)%mod;        a = (a*a)%mod;        b = b>>1;
    }
    return ans%mod;
}

void pre()
{
    fact[0] = fact[1] = 1LL;

    for(ll i = 2; i<=2*mx; i++)
    {
        fact[i] = fact[i-1] * i;
        fact[i]%= mod;
    }

    cat[1] = 1;

    for(ll i = 2; i<=mx; i++)
    {
        cat[i] = fact[2*i];
        ll hor = fact[i]*fact[i+1];
        hor%=mod;
        ll temp = bigmod(hor, mod-2, mod);
        cat[i] *= temp;
        cat[i] %= mod;
    }

   // for(ll i =0; i<=10; i++)    cout<<cat[i]<<endl;

}

set<ll> st;
  vector<ll> v;
void cal()
{
    for(ll i = 2; i<=mx; i++)
    {
        ll res = i*i;

        while(res<=10000000000LL)  st.insert(res), res*=i;
    }


    for(set<ll> ::iterator it = st.begin(); it!=st.end(); it++) v.push_back(*it);
    
    v.push_back(100000000000LL);
}

int main()
{
    pre();
    cal();

    int test, cs = 0;

    scanf("%d", &test);

    while(test--)
    {
        ll a, b;
        
        scanf("%lld %lld", &a, &b);

        int x = st.upper_bound(b) - st.begin();

        int hi = upper_bound(v.begin(), v.end(), b) - v.begin();
        int lo = lower_bound(v.begin(), v.end(), a) - v.begin();

        printf("Case %d: %lld\n", ++cs, cat[hi-lo]);
    }

    return 0;
}
