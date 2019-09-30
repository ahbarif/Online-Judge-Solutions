#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int sz = 10000001;

ll phi[sz+5];

void sieve(){
    for (int i=1; i<=sz; i++)    phi[i] = i;

    for (int p=2; p<=sz; p++){
        if (phi[p] == p){
            phi[p] = p-1;
            for (int i = 2*p; i<=sz; i += p){
               phi[i] = (phi[i]/p) * (p-1);
            }
        }
    }

    for(int i = 1; i<=sz; i++) phi[i] += phi[i-1];
}


int main()
{
    sieve();

    int test, cs = 0;

    scanf("%d", &test);

    while(test--){

        long long n, p;
        scanf("%lld %lld", &n, &p);

        ll mid, lo = 1, hi = n, ret = -1;

        while(lo<=hi){
            mid = (lo+hi)/2;
            if(phi[n/mid]>=p) {
                ret = mid;
                lo = mid+1;
            }
            else hi = mid-1;
        }

        printf("Case %d: %lld\n", ++cs, ret);
    }


     return 0;
}

