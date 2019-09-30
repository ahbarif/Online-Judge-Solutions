#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef tree<pair<int, int>, null_type, less<pair<int, int> >,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const int maxn = 300005;
int global_count = 1;

namespace DSU{
    ordered_set vec[maxn];
    int par[maxn];

    void __init(int n){
        for(int i = 0; i<=n; i++){
             par[i] = i;
             vec[i].clear();
        }
    }

    int __findParent(int u){
        if(par[u] == u) return u;
        return par[u] = __findParent(par[u]);
    }

    void __insert(int x, int t){
        int u = __findParent(x);
        vec[u].insert(make_pair(t, global_count++));
    }

    void __union(int x, int y){
        int u = __findParent(x);
        int v = __findParent(y);

        if(u == v) return;

        int target = (vec[u].size()>vec[v].size()?u:v);

        if(target == u){
            for(auto it:vec[v]) vec[u].insert(it);
            par[v] = u;
        }
        else{
            for(auto it:vec[u]) vec[v].insert(it);
            par[u] = v;
        }
    }

    int __query(int x, int L, int R){
        int u = __findParent(x);
        int hi = vec[u].order_of_key(make_pair(R, INT_MAX));
        int lo = vec[u].order_of_key(make_pair(L, 0));
        return hi-lo;
    }

}

int main(){

    int test, cs = 0;

    scanf("%d", &test);

    while(test--){
        int n, q;
        scanf("%d %d", &n, &q);
        DSU::__init(n);
        printf("Case %d:\n", ++cs);
        while(q--){
            int t, u, v, l, r, x;
            scanf("%d", &t);
            if(t == 0){
                scanf("%d %d", &u, &v);
                DSU::__union(u, v);
            }
            else if(t == 1){
                scanf("%d %d", &u, &t);
                DSU::__insert(u, t);
            }
            else{
                scanf("%d %d %d", &u, &l, &r);
                int ret = DSU::__query(u, l, r);
                printf("%d\n", ret);
            }
        }
    }
    return 0;
}
