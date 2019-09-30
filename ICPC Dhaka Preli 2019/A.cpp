#include <bits/stdc++.h>
using namespace std;
const int maxn = 1250005;

char str[maxn];
unsigned long long base = 1925728309;
unsigned long long P[maxn];
int n;
typedef unsigned long long ull;

namespace StringHash{
    char text[maxn], pattern[maxn];
    ull P[maxn], tHash[maxn], pHash[maxn];

    void __calc__(){
        P[0] = 1;
        for(int i = 1; i<=1250000; i++) P[i] = (P[i-1] * base);
    }

    void __generate_text__hash(){
        int n = strlen(text);
        ull x = 0;
        for (int i = 0; i < n; i++){
            x = (x * base) + text[i];
            tHash[i] = x;
        }
    }

    void __generate_pattern__hash(){
        int n = strlen(pattern);
        ull x = 0;
        for (int i = 0; i < n; i++){
            x = (x * base) + pattern[i];
            pHash[i] = x;
        }
    }

    ull getTextHash(int i, int j){
        unsigned long long x = tHash[j];
        if (i){
            unsigned long long y = P[j - i + 1] * tHash[i - 1];
            x -= y;
        }
        return x;
    }

    ull getPatternHash(int i, int j){
        unsigned long long x = pHash[j];
        if (i){
            unsigned long long y = P[j - i + 1] * pHash[i - 1];
            x -= y;
        }
        return x;
    }
}

using namespace StringHash;

int nn, mm;

int firstMismatch(int offset, int st, int en){
    int ret = numeric_limits<int>::max();
    int lo = st, hi = en, mid;

    while(lo<=hi){
        mid = (lo+hi)/2;
        ull tt = getTextHash(st+offset, mid+offset);
        ull pp = getPatternHash(st, mid);

        if(tt == pp){
            lo = mid+1;
        }
        else{
            ret = min(ret, mid);
            hi = mid-1;
        }
    }
    if(ret == numeric_limits<int>::max()) ret = -1;
    return ret;

}

int allowedMisMatch;

bool isAlmostequal(int offset, int x, int y){

    int a[6];
    memset(a, -1, sizeof(a));
    a[0] = firstMismatch(offset, x, y);
    int sofar = a[0];
    for(int i = 1; i<5; i++){
        a[i] = firstMismatch(offset, sofar+1, y);
        sofar = max(sofar, a[i]);
    }
    if(a[allowedMisMatch] == -1) return true;
    return false;
}

void solve(){
    scanf("%s %s %d", &text, &pattern, &allowedMisMatch);
    StringHash::__generate_pattern__hash();
    StringHash::__generate_text__hash();
    nn = strlen(text);
    mm = strlen(pattern);

    int ret = 0, cnt = 1;

    for(int i = 0; i<=(nn-mm); i++){
        ret += (isAlmostequal(i, 0, mm-1) == true);
    }

    printf("%lld\n", ret);
}

int main(){

    StringHash::__calc__();

    int test, cs = 0;

    scanf("%d", &test);

    while(test--){
        printf("Case %d: ", ++cs);
        solve();
    }

    return 0;
}
