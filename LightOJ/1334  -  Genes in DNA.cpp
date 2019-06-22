#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = 50005;
const ll base = 127, mod = 1000000007;
ll prefix[maxn], suffix[maxn];
ll suffixHash[maxn], powers[maxn], inv[maxn];

ll modexp(ll a, ll b, ll mod){

    ll res = 1;

    while(b){
        if(b&1) res = (res*a)%mod;
        a = (a*a)%mod;
        b = b>>1;
    }

    return res%mod;
}

struct stringHash{

    ll base, mod, sz;
    ll forwardHash[maxn];
    char str[maxn];

    stringHash(){}

    stringHash(ll base, ll mod):base(base), mod(mod){}

    void generateForwardHash(){

        ll p = base;
        sz = strlen(str);

        forwardHash[0] = p * str[0];

        for(int i = 1; i<sz; i++){
            p = (p*base)%mod;
            forwardHash[i] = p * str[i];
            forwardHash[i] += forwardHash[i-1];
            forwardHash[i] %= mod;
        }
    }

    ll getHash(int i, int j){   // return hash from str[i] to str[j]

        if(i == 0) return forwardHash[j];

        ll mid = forwardHash[j] - forwardHash[i-1];
        mid = (mid + mod) % mod;
        ll ret = mid * inv[i];
        return ret%mod;
    }

};

stringHash text, pattern;
char str1[maxn], str2[maxn];

void init(){

    text.base = base;
    text.mod = mod;

    pattern.base = base;
    pattern.mod = mod;

    text.generateForwardHash();
    pattern.generateForwardHash();

    memset(prefix, 0, sizeof(prefix));
    memset(suffix, 0, sizeof(suffix));
}

void prefixUpdate(int L, int R){
    if(R<L) return;
    prefix[L] += 1;
    prefix[R+1] -= 1;
}

void suffixUpdate(int L, int R){
    if(R<L) return;
    suffix[L] += 1;
    suffix[R+1] -= 1;
}

void calculateSuffixHash(){

    for(int i = 0; i<pattern.sz; i++){
        suffixHash[i] = pattern.getHash(i, pattern.sz-1);
    }

}

int main()
{

  //  freopen("in.txt", "r", stdin);

    int test, cs = 0;

    scanf("%d", &test);

    powers[0] = 1;
    for(int i = 1; i<maxn; i++){
        powers[i] = powers[i-1] * base;
        if(powers[i] >= mod) powers[i] %=mod;

    }

    for(int i = 0; i<maxn; i++) {
        inv[i] = modexp(powers[i], mod-2, mod);
    }

    while(test--){

        scanf("%s %s", text.str, pattern.str);

        init();

        calculateSuffixHash();

        for(int i = 0; i<text.sz; i++){

            int lo = 1, hi = pattern.sz-1, mid, longestMatch = 0;

            while(lo<=hi){
                mid = (lo+hi)/2;

                if(i+mid-1>=text.sz){
                    hi = mid-1;
                    continue;
                }

                ll tHash = text.getHash(i, i+mid-1);
                ll pHash = pattern.getHash(0, mid-1);
                if(tHash == pHash){
                    longestMatch = max(longestMatch, mid);
                    lo = mid+1;
                }
                else hi = mid-1;
            }
            prefixUpdate(i, i+longestMatch-1);
        }

        for(int i = text.sz-1; i>=0; i--){

            int lo = 1, hi = pattern.sz-1, mid, longestMatch = 0;

            while(lo<=hi){

                mid = (lo+hi)/2;

                if(i-mid+1 <0) {
                    hi = mid-1;
                    continue;
                }

                ll tHash = text.getHash(i-mid+1, i);
                ll pHash = suffixHash[pattern.sz - mid];

                if(tHash == pHash){
                    longestMatch = max(longestMatch, mid);
                    lo = mid+1;
                }
                else hi = mid-1;
            }

            suffixUpdate(i-longestMatch + 1, i);
        }


        for(int i = 1; i<maxn; i++) prefix[i] += prefix[i-1];
        for(int i = 1; i<maxn; i++) suffix[i] += suffix[i-1];

        long long ret = 0;

        for(int i = 0; i<text.sz; i++){
            ret += (prefix[i] * suffix[i+1]);
        }

        printf("Case %d: %lld\n", ++cs, ret);

    }

    return 0;
}

