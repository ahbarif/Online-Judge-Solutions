# include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M = 1000000007LL;
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

template<class T> inline T inverse(T a, T mod)
{
    return bigmod(a, mod-2, mod);
}

template<class T> inline T SOD(T n, T b)
{
    T i, ans = 1, p = 0;

    if(n%2==0)
    {
        while(n%2==0) n = n>>1, ++p;

        p*=b;

        ll x = bigmod(2LL, p+1, M) - 1;
      //  cout<<x<<endl;
        ll y = inverse(1LL, M);

        ans = ((ans%M) * (x%M))%M;
        ans = ((ans%M) * (y%M))%M;
    }

    for(i=3; i*i<=n; i+=2)
    {
        if(n%i==0)
        {
            p = 0;
            while(n%i==0) n/=i, ++p;

            p*=b;

            ll x = bigmod(i, p+1, M) - 1;
            ll y = inverse(i-1, M);

            ans = ((ans%M) * (x%M))%M;
            ans = ((ans%M) * (y%M))%M;
        }
    }

    if(n>1)
    {
            p=b;

            ll x = bigmod(n, p+1, M)-1;
            ll y = inverse(n-1, M);

            ans = ((ans%M) * (x%M))%M;
            ans = ((ans%M) * (y%M))%M;
    }
    if(ans<0)   ans+=M;
    return ans;
}

int main()
{

    int test, cs = 1;

    scanf("%d", &test);

    while(test--)
    {
        ll a, b;
        scanf("%lld %lld", &a, &b);

        printf("Case %d: %lld\n", cs++, SOD(a, b));
    }
    return 0;
}
