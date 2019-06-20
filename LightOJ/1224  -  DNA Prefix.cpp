#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef pair<long long, long long> pii;

template <typename T>

using ordered_set = tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update>;

int main()
{


    int test, cs = 0;
    ordered_set<pii>  s;

    int cnt = 0;

    s.insert(make_pair(1, cnt++));
    s.insert(make_pair(3, cnt++));


    cout << s.order_of_key(2) << endl; // the number of elements in the s less than 2
    cout << *s.find_by_order(0) << endl; // print the 0-th smallest number in s(0-based)
}
