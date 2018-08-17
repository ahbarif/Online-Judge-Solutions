#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1000010;

ll mod = 1000000007;

bool mark[maxn+10];

vector<pair<int, int> > adj[1000002];

int primes[maxn] = {2}, id = 1;
int factors[maxn];


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

void sieve()
{

    mark[1] = true;
    for(int i = 4; i<=maxn; i+=2) mark[i] = true;

    for(int i = 3; i<=maxn; i+=2)
    {
        if(mark[i] == false)
        {
            primes[id++] = i;

            for(int j = 2*i; j<=maxn; j+=i)
            {
                mark[j] = true;
            }
        }
    }
}

void factorize(int n)
{

    if(mark[n] == false)
    {
        adj[n].push_back(make_pair(n, 1));
        return;
    }
    int nn = n;

    int cnt = 0;
    while(n%2==0)
    {
        n /= 2;
        cnt++;
    }

    if(cnt) adj[nn].push_back(make_pair(2, cnt));

    for(int i = 0; primes[i]*primes[i]<=n; ++i)
    {
        if(n%primes[i]==0)
        {
            cnt = 0;
            while(n%primes[i]==0)
            {
                n/=primes[i];
                ++cnt;
            }
            adj[nn].push_back(make_pair(primes[i], cnt));
        }
    }

    if(n>1) adj[nn].push_back(make_pair(n, 1));
}


void pre()
{
    sieve();
    for(int i = 2; i<=1000000; i++) factorize(i);
}

void solve(int cs)
{

    memset(factors, 0, sizeof(factors));

    ll cur = 1;
    ll sum = 0, res = 1;

    int n, x;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d", &x);
        if(x == 1 || x == -1)
        {
            sum = (sum+res)%mod;
            continue;
        }

        if(x>0)
        {

            for(int i = 0; i<adj[x].size(); i++)
            {
                int pr = adj[x][i].first;
                int no = adj[x][i].second;

                no += factors[pr];

                ll tmp = bigmod(factors[pr]+1,mod-2, mod);
                res *= tmp;
                res %= mod;
                res *= (no + 1);
                res %= mod;


                factors[pr] = no;
            }
        }
        else
        {
            x *= -1;

            for(int i = 0; i<adj[x].size(); i++)
            {
                int pr = adj[x][i].first;
                int no = adj[x][i].second;

                ll tmp = bigmod(factors[pr]+1,mod-2, mod);
                res *= tmp;
                res %= mod;

                factors[pr]-= no;

                res *= (factors[pr] + 1);
                res %= mod;
            }
        }
            sum += res;
            sum %= mod;

    }

    printf("Case %d: %lld\n", cs, sum);

}

int main()
{

   // freopen("in.txt", "r", stdin);

    pre();

    int t;

    scanf("%d", &t);

    for(int i = 1; i<=t; i++) solve(i);


    return 0;
}
