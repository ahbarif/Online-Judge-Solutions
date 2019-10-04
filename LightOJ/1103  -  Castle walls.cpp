#include <bits/stdc++.h>
using namespace std;

const int maxn = 200005;
typedef long long ll;

int tree[maxn+100];
pair<int, int> a[maxn+100], b[maxn+100];

void update(int pos, int x){
   
    while(pos<=maxn)
    {
        tree[pos] += x;
        pos+=(pos)&(-pos);
    }
}

int query(int pos){

    ll sum = 0;
    while(pos>0)
    {
        sum+=tree[pos];
        pos-=(pos)&(-pos);
    }
    return sum;
}

int rangeSumQuery(int lo, int hi){
    if(lo>hi) return 0;
    return query(hi) - query(lo-1);
}

int main()
{
    #ifdef local
        freopen ("in.txt", "r", stdin);
    #endif

    int test, cs = 0;

    scanf("%d", &test);

    while(test--){
        memset(tree, 0, sizeof(tree));
        int n, m;
        scanf("%d %d", &n, &m);

        for(int i = 1; i<=n; i++) scanf("%d %d", &a[i].first, &a[i].second);
        for(int i = 1; i<=m; i++) scanf("%d %d", &b[i].first, &b[i].second);

        sort(a+1, a+n+1);
        sort(b+1, b+m+1);

        int ptr = 1;
        ll ret = 0;

        for(int i = 1; i<=m; i++){
            int st = b[i].first;
            int en = b[i].second;

            while(ptr <= n && a[ptr].first<=st){
                update(a[ptr].second, 1);
                ptr++;
            }

            int tmp = rangeSumQuery(en, maxn);
            ret += (ll)tmp;
        }

        memset(tree, 0, sizeof(tree));

        ptr = n;
        for(int i = m; i>=1; i--){
            int st = b[i].first;
            int en = b[i].second;

            while(ptr >=1 && a[ptr].first>=st){
                update(a[ptr].second, 1);
                ptr--;
            }

            int tmp = rangeSumQuery(1, en);
            ret += (ll)tmp;
        }

        printf("Case %d: %lld\n", ++cs, ret);
    }

    return 0;
}

