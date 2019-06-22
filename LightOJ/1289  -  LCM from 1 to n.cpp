#include<bits/stdc++.h>
using namespace std;

const int mx = 100000010;

unsigned primes[5861455];
unsigned dp[5861455];
int status[(mx/32)+12];

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

unsigned __LCM(int n){

    unsigned lcm = 1;

    int sqrtt = sqrt(n);

    for (int i=0; primes[i]*primes[i]<=n; i++)
    {
        unsigned pp = n/primes[i];

        while (pp>=primes[i]){
            pp /= primes[i];
            lcm *= primes[i];
        }
    }
    return lcm;

}

int main()
{
    sieve(100000005);

   // for(int i = 0; i<=10; i++) cout<<primes[i]<<endl;

    dp[0] = 2;

    for(int i = 1; i<idx; i++) dp[i] = dp[i-1] * primes[i];

    int test, cs = 0;

    scanf("%d", &test);

    while(test--){

            int n;

            scanf("%d", &n);

            int x = sqrt(n);

            unsigned lcm = __LCM(n);
        //    cout<<lcm<<endl;

            int pos = upper_bound(primes, primes+idx, n) - primes;

            lcm *= dp[pos-1];

        printf("Case %d: %u\n", ++cs, lcm);
    }
  //  5861455

}


