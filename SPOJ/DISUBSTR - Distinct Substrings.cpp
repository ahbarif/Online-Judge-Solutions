#include<bits/stdc++.h>
using namespace std;

namespace suffix_array {
    const int MAXN = 1 << 19;
    const int MAXL = 19;

    int n, stp, mv, suffix[MAXN], tmp[MAXN], lcp[MAXN];
    int sum[MAXN], cnt[MAXN], rank[MAXL][MAXN];
    char str[MAXN];

    inline bool equal(const int &u, const int &v) {
        if(!stp) return str[u] == str[v];
        if(rank[stp-1][u] != rank[stp-1][v]) return false;
        int a = u + mv < n ? rank[stp-1][u+mv] : -1;
        int b = v + mv < n ? rank[stp-1][v+mv] : -1;
        return a == b;
    }

    void update() {
        int i, rnk;
        for(i = 0; i < n; i++) sum[i] = 0;
            for(i = rnk = 0; i < n; i++) {
                suffix[i] = tmp[i];
                if(i && !equal(suffix[i], suffix[i-1])) {
                    rank[stp][suffix[i]] = ++rnk;
                    sum[rnk+1] = sum[rnk];
                } else rank[stp][suffix[i]] = rnk;
                sum[rnk+1]++;
            }
        }

        void Sort() {
            int i;
            for(i = 0; i < n; i++) cnt[i] = 0;
                memset(tmp, -1, sizeof tmp);
            for(i = 0; i < mv; i++) {
                int idx = rank[stp - 1][n - i - 1];
                int x = sum[idx];
                tmp[x + cnt[idx]] = n - i - 1;
                cnt[idx]++;
            }
            for(i = 0; i < n; i++) {
                int idx = suffix[i] - mv;
                if(idx < 0)continue;
                idx = rank[stp-1][idx];
                int x = sum[idx];
                tmp[x + cnt[idx]] = suffix[i] - mv;
                cnt[idx]++;
            }
            update();
            return;
        }

        inline bool cmp(const int &a, const int &b) {
            if(str[a]!=str[b]) return str[a]<str[b];
            return false;
        }

        void SortSuffix() {
            int i;
            for(i = 0; i < n; i++) tmp[i] = i;
                sort(tmp, tmp + n, cmp);
            stp = 0;
            update();
            ++stp;
            for(mv =  1; mv < n; mv <<= 1) {
                Sort();
                stp++;
            }
            stp--;
            for(i = 0; i <= stp; i++) rank[i][n] = -1;
        }

    int find_lcp(int u, int v) {
        if(u == v) return n - u;
        int ret, i;
        for(ret = 0, i = stp; i >= 0; i--) {
            if(rank[i][u] == rank[i][v]) {
                ret += 1<<i;
                u += 1<<i;
                v += 1<<i;
            }
        }
        return ret;
    }
    void create_lcp(){
        for(int i=1;i<n;i++){
            lcp[i]=find_lcp(suffix[i-1],suffix[i]);
        }
    }
}

using namespace suffix_array;

int main(){

    int test, cs = 0;

    scanf("%d", &test);

    while(test--){
        scanf("%s", suffix_array::str);
        n = strlen(suffix_array::str);
        SortSuffix();
        create_lcp();
        long long tot = (n*(n+1))/2LL;
        for(int i = 1; i<n; i++) tot -= lcp[i];

        printf("%lld\n", tot);

    }

    return 0;

}

