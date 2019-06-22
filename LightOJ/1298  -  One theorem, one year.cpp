#include<bits/stdc++.h>
using namespace std;

vector<int> primes;

typedef long long ll;

const ll mod = 1000000007;

ll bigmod(ll p, ll e, ll m)
{
    ll ret = 1;
    for(; e > 0; e >>= 1)
    {
        if(e & 1) ret = (ret * p) % m;
        p = (p * p) % m;
    }
    return ret;
}

void sieve()
{
    primes.push_back(2);
    primes.push_back(2);
    for(int i = 3; ; i+=2)
    {
        int n = i;
        for(int j = 2; j*j<=n; j++)
        {
            if(n%j==0)
            {
                n = -1;
                break;
            }
        }
        if(n!=-1) primes.push_back(i);
        if(primes.size()==505) break;
    }
}

ll dp[505][505];
ll guun[505];
ll vaag[505];

void pre()
{

    sieve();
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1LL;
    for(int i = 1; i<=500; i++)
    {
        for(int j = i; j<=500; j++)
        {
            dp[i][j] = (dp[i][j-1] + dp[i-1][j-1])*primes[i];
            dp[i][j] %= mod;
        }
    }

    guun[0] = 1;
    vaag[0] = 1;

    for(int i = 1; i<=500; i++){
        guun[i] = (guun[i-1] * (primes[i] - 1));
        vaag[i] = (vaag[i-1] * primes[i]);

        guun[i] %= mod;
        vaag[i] %= mod;
    }

}


int main()
{

    //  freopen("in.txt", "r", stdin);



    pre();

    int test, cs = 0;

    scanf("%d", &test);

    while(test--){
        int p, k;

        scanf("%d %d", &k, &p);

        ll ret = dp[p][k];

        ret = ret * guun[p];

        ret %= mod;

        ret = ret * bigmod(vaag[p], mod-2, mod);

        ret %= mod;

        printf("Case %d: %lld\n", ++cs, ret);
    }

    return 0;
}

