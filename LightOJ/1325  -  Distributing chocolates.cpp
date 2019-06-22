#include <bits/stdc++.h>
using namespace std;

long long modexp(long long p, long long e, long long m)
{
    long long ret = 1;
    for(; e > 0; e >>= 1)
    {
        if(e & 1) ret = (ret * p) % m;
        p = (p * p) % m;
    }
    return ret%m;
}

long long modinv(long long a, long long p){
    return modexp(a, p-2, p);
}

long long shank(long long a, long long b, long long p) {

    long long i, j, m;
    long long c, aj, ami;
    map< long long, long long > M;
    map< long long, long long > :: iterator it;
    m = (long long)ceil(sqrt((double)(p)));
    M.insert(make_pair(1, 0));
    for(j = 1, aj = 1; j < m; j++) {
        aj = (aj * a) % p;
        M.insert(make_pair(aj, j));
    }
    ami = modexp(modinv(a, p), m, p);
    for(c = b, i = 0; i < m; i++) {
        it = M.find(c);
        if(it != M.end()) return i * m + it->second;
        c = (c * ami) % p;
    }
    return 0;
}

int main()
{

    int test, cs = 0;

    scanf("%d", &test);

    while(test--){
        long long a, b, p;
        scanf("%lld %lld", &a, &b);
        p = 100000007;

        long long ret = shank(a, b, p);

        printf("Case %d: %lld\n", ++cs, ret);
    }

}

