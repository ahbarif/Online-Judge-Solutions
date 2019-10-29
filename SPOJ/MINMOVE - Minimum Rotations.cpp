#include<bits/stdc++.h>
using namespace std;

namespace suffix_array {
    const int MAXN = 1 << 18;
    const int MAXL = 18;

    int n, stp, mv, suffix[MAXN], tmp[MAXN], lcp[MAXN];
    int sum[MAXN], cnt[MAXN], rankk[MAXL][MAXN];
    char str[MAXN];

    inline bool equal(const int &u, const int &v) {
        if(!stp) return str[u] == str[v];
        if(rankk[stp-1][u] != rankk[stp-1][v]) return false;
        int a = u + mv < n ? rankk[stp-1][u+mv] : -1;
        int b = v + mv < n ? rankk[stp-1][v+mv] : -1;
        return a == b;
    }

    void update() {
        int i, rnk;
        for(i = 0; i < n; i++) sum[i] = 0;
            for(i = rnk = 0; i < n; i++) {
                suffix[i] = tmp[i];
                if(i && !equal(suffix[i], suffix[i-1])) {
                    rankk[stp][suffix[i]] = ++rnk;
                    sum[rnk+1] = sum[rnk];
                } else rankk[stp][suffix[i]] = rnk;
                sum[rnk+1]++;
            }
        }

        void Sort() {
            int i;
            for(i = 0; i < n; i++) cnt[i] = 0;
                memset(tmp, -1, sizeof tmp);
            for(i = 0; i < mv; i++) {
                int idx = rankk[stp - 1][n - i - 1];
                int x = sum[idx];
                tmp[x + cnt[idx]] = n - i - 1;
                cnt[idx]++;
            }
            for(i = 0; i < n; i++) {
                int idx = suffix[i] - mv;
                if(idx < 0)continue;
                idx = rankk[stp-1][idx];
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
            for(i = 0; i <= stp; i++) rankk[i][n] = -1;
        }
}

const int maxn = 200005;
unsigned long long base = 1925728309;
typedef unsigned long long ull;

namespace StringHash{

    ull P[maxn], tHash[maxn];

    void __calc__(){
        P[0] = 1;
        for(int i = 1; i<maxn; i++) P[i] = (P[i-1] * base);
    }

    void __generate_text__hash(){
        int n = strlen(suffix_array::str);
        ull x = 0;
        for (int i = 0; i < n; i++){
            x = (x * base) + suffix_array::str[i];
            tHash[i] = x;
        }
        return;
    }

    ull getTextHash(int i, int j){
        unsigned long long x = tHash[j];
        if (i){
            unsigned long long y = P[j - i + 1] * tHash[i - 1];
            x -= y;
        }
        return x;
    }
}

string s;

int main(){

        #ifdef local
            freopen("in.txt", "r", stdin);
        #endif

        StringHash::__calc__();

        int t = 1;
    //    cin>>t;
        while(t--){
            int k;
            cin>>s;
            k = s.size();
            s = s + s;
            strcpy(suffix_array::str, s.c_str());
            suffix_array::n = 2*k;
            suffix_array::SortSuffix();
            StringHash::__generate_text__hash();

            int ret = -1;
            ull H;

            for(int i = 0; i<suffix_array::n; i++){
                int idx = suffix_array::suffix[i];
                if(idx<k){
                    H = StringHash::getTextHash(idx, idx+k-1);
                    ret = idx;
                    break;
                }
            }

            for(int i = 0; i<suffix_array::n; i++){
                int idx = suffix_array::suffix[i];
                if(idx<ret && idx<k){
                    ull hhash = StringHash::getTextHash(idx, idx+k-1);
                    if(hhash == H) ret = idx;
                }
            }

            cout<<ret<<endl;
        }


}

