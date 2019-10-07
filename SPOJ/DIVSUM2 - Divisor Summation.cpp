#include <bits/stdtr1c++.h>
using namespace std;

#define chkbit(ar, i) (((ar[(i) >> 6]) & (1 << (((i) >> 1) & 31))))
#define setbit(ar, i) (((ar[(i) >> 6]) |= (1 << (((i) >> 1) & 31))))
#define isprime(x) (( (x) && ((x)&1) && (!chkbit(ar, (x)))) || ((x) == 2))
#define LEN 5761470
#define MAX 100000101
#define ull unsigned long long
int p;
ull prime[LEN];
int ar[(MAX >> 6) + 5];


void Sieve(){
    int i, j, k;
    setbit(ar, 0), setbit(ar, 1);

    for (i = 3; (i * i) < MAX; i++, i++){
        if (!chkbit(ar, i)){
            k = i << 1;
            for (j = (i * i); j < MAX; j += k) setbit(ar, j);
        }
    }

    p = 0;
    prime[p++] = 2;
    for (i = 3; i < MAX; i++, i++){
        if (isprime(i)) prime[p++] = i;
    }
}

ull modex(ull n, int p){
    ull x = (ull)1, y = n;
    while(p)
    {
        if(p&1) x *= y;
        y *= y;
        p >>= 1;
    }
    return x;
}

void factorize(){
    ull n, pp;
    scanf("%llu", &n);
    pp = n;
    ull ret = 1;
    for(int i = 0; prime[i]*prime[i]<=n; i++){
        if(n%prime[i] == 0){
            int c = 0;
            while(n%prime[i] == 0){
                n /= prime[i];
                c++;
            }

            ull tmp = modex(prime[i], c+1) - 1;
            tmp /= (prime[i]-1);
            ret *= tmp;
        }
    }

    if(n>1){
        ret *= (n+1);
    }
    printf("%llu\n", ret - pp);
}

int main(){
#ifdef local
   freopen("out.txt", "r", stdin);
#endif
    Sieve();
    int t;
    scanf("%d", &t);
    while(t--){
        factorize();
    }
   

    return 0;
}
