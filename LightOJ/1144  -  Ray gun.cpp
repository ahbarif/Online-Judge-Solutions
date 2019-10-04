#include<bits/stdc++.h>
using namespace std;

int factors[1000005];
bool ignoree[1000005];

void sieve(){
    for(int i = 2; i<=1000000; i++){
        if(factors[i] == 0){
            for(int k = i; k<=1000000; k+=i){
                factors[k]++;
            }
        }
    }

    for(int i = 2; i<=1000; i++){
        for(int k = i*i; k<=1000000; k+=i*i){
            ignoree[k] = true;
        }
    }
    return;
}

int main(){

    #ifdef local
        freopen("in.txt", "r", stdin);
    #endif

    sieve();

    int test, cs = 0;

    cin>>test;

    while(test--){
        long long n, m;
        scanf("%lld %lld", &n, &m);
        if(n>m) swap(n, m);

        printf("Case %d: ", ++cs);

        if(n == 0){
            if(m == 0) printf("0\n");
            else printf("1\n");
            continue;
        }

        long long ret = 0;

        for(int i = 1; i<=n; i++){
            if(ignoree[i]) continue;
            int sign = (factors[i]&1?-1:1);
            long long tmp = (n/i) *( m/i);
            ret += (tmp*sign);
        }

        printf("%lld\n", ret+2);
    }

    return 0;
}