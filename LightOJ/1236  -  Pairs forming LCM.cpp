#include<bits/stdc++.h>
using namespace std;

const int mx = 100000010;

typedef long long ll;

int status[(mx/32)+10];
ll primes[667600];
int idx = 0;

bool Check(int N,int pos)
{
    return (bool)(N & (1<<pos));
}

int Set(int N,int pos)
{
    return N = N | (1<<pos);
}

void sieve(long long N)
{

    for( long long i = 3; i*i <= N; i += 2 )
    {
        if( Check(status[i>>5],i&31)==0)
        {
            for( long long j = i*i; j <= N; j += (i<<1) )
            {
                status[j>>5]=Set(status[j>>5],j & 31);
            }
        }
    }

    primes[idx++] = 2;

    for(int i=3; i<=N; i+=2)
    {
        if( Check(status[i>>5],i&31)==0)
        {
            primes[idx++] = i;
        }
    }

}


ll __LCM_cardinality(ll n){

    ll ans = 1;

    for(int i = 0; i<idx && primes[i]*primes[i] <= n ; i++){
        if(n%primes[i]==0){
            int cnt = 0;
            while(n%primes[i]==0){
                n/= primes[i];
                cnt++;
            }

            ans = ans * (2*cnt+1);
        }
    }

    if(n>1) ans *= 3;

    return (ans/2) + 1;

}

int main()
{
    sieve(10000100);

    int test, cs = 0;

    scanf("%d", &test);

    while(test--){

        ll n;
        scanf("%lld", &n);
        ll res = __LCM_cardinality(n);
        printf("Case %d: %u\n", ++cs, res);
    }


}


