#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = 1000000007;

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

ll fac[1000001];

ll nCr(int n, int r){

    ll top = fac[n];
    ll down = (fac[r] * fac[n-r])%mod;
    ll ret = bigmod(down, mod-2, mod);
    ret = (ret*top);
    return ret%mod;
}


int main()
{

    fac[0] = 1;
    for(int i = 1; i<=1000000; i++){
        fac[i] = i*fac[i-1];
        if(fac[i]>=mod) fac[i]%= mod;
    }


    int test, cs = 0;

    scanf("%d", &test);

    while(test--)
    {
        int n, x;

        scanf("%d", &n);

        ll ans = 1;

        ll sum = 0;

        for(int i = 0; i<n; i++){
            scanf("%d", &x);
            sum +=x;
            ll tmp = nCr(sum-1, x-1);
            ans = ans*tmp;
            ans%=mod;
        }

        printf("Case %d: %lld\n", ++cs, ans);

    }

    return 0;
}

