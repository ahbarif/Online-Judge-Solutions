#include <bits/stdc++.h>
using namespace std;

const int maxn = 5005;
unsigned long long base = 1925728309;
unsigned long long P[maxn];
typedef unsigned long long ull;

namespace StringHash {
char text[4][maxn];
ull P[maxn], tHash[4][maxn];
int lens[4];

void __calc__() {
    P[0] = 1;
    for(int i = 1; i<maxn; i++)
        P[i] = (P[i-1] * base);
}

void __generate_text__hash(int id) {
    int n = strlen(text[id]);
    lens[id] = n;
    ull x = 0;
    for (int i = 0; i < n; i++) {
        x = (x * base) + text[id][i];
        tHash[id][i] = x;
    }
}

ull getTextHash(int id, int i, int j) {
    unsigned long long x = tHash[id][j];
    if (i) {
        unsigned long long y = P[j - i + 1] * tHash[id][i - 1];
        x -= y;
    }
    return x;
}
}

using namespace StringHash;
unordered_map<ull, int> mp;
unordered_map<ull, int> tmp;

bool exist(int n, int mid) {
    // n = number of strings
    mp.clear();
    for(int i = 0; i<n; i++) {
        tmp.clear();
        int len = lens[i];
        for(int j = 0; j<len; j++) {
            if(j+mid-1>=len)
                break;
            ull h = getTextHash(i, j, j+mid-1);
            tmp[h]++;
        }
        for(auto it:tmp) {
            mp[it.first]++;
            if(mp[it.first] == n)
                return true;
        }
    }


    return false;
}

int main() {

  //    freopen("in.txt" ,"r", stdin);

    StringHash::__calc__();

    int test, cs = 0;

    scanf("%d", &test);

    while(test--) {
        int mn = INT_MAX;

        for(int i = 0; i<3; i++) {
            scanf("%s", text[i]);
            __generate_text__hash(i);
            mn = min(mn, lens[i]);

        }
        int lo = 0, hi = mn, mid, ans = 0;

        while(lo<=hi) {
            mid = (lo+hi)/2;

            if(exist(3, mid)) {
                ans = max(ans, mid);
                lo = mid+1;
            } else
                hi = mid-1;
        }

        printf("Case %d: %d\n", ++cs, ans);
    }




    return 0;
}
