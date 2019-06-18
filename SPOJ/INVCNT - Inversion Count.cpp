#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
ordered_set<int> st;
int a[200002];
void getInversionCount(int n)
{
    st.clear();
     for(int i = 0; i<n; i++) st.insert(a[i]);
     long long res = 0;
     for(int i = 0; i<n; i++)
    {
        int t = st.order_of_key(a[i]);
        res += (long long)t;
        st.erase(a[i]);
    }
     printf("%lld\n", res);
}
int main()
{
     int test;
     scanf("%d", &test);
     while(test--)
    {
        st.clear();
        int n;
        scanf("%d", &n);
         for(int i = 0; i<n; i++) scanf("%d", &a[i]);
         getInversionCount(n);
    }
   }
