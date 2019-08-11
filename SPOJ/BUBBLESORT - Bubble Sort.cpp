#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <typename T>

using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

ordered_set<int> st;
map<string, int> mp;

int a[100005];

void getInversionCount(int n) {

    st.clear();

    for(int i = 0; i<n; i++) st.insert(a[i]);

    int res = 0;

    for(int i = 0; i<n; i++) {
        int t = st.order_of_key(a[i]);
        res += t;
        res %= 10000007;
        st.erase(a[i]);
    }

    printf("%d\n", res);
}

int main() {

    int test, cs = 0;

    scanf("%d", &test);

    while(test--){
        int n;

        scanf("%d", &n);

        for(int i = 0; i<n; i++) scanf("%d", &a[i]);

        printf("Case %d: ", ++cs);

        getInversionCount(n);
    }

}
