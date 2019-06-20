#include<bits/stdc++.h>
using namespace std;

int a[100010], dp[100010], tree[400010];
const int inf = 200000000;

void build(int node, int lo, int hi)
{
    if(lo==hi)
    {
        tree[node] = dp[lo];
        return;
    }

    int left  = 2*node;
    int right = 2*node+1;
    int mid   = (lo+hi)>>1;


    build(left, lo, mid);

    build(right, mid+1, hi);

    tree[node] = min(tree[left], tree[right]);
}

int query(int node, int lo, int hi, int i, int j)
{
    if(i>hi || j<lo)    return inf;

    if(i<=lo && j>=hi)  return tree[node];

    int left  = 2*node;
    int right = 2*node + 1;
    int mid   = (lo+hi)/2;

    int x = query(left, lo, mid, i, j);
    int y = query(right, mid+1, hi, i, j);

    return min(x, y);
}

void update(int node, int lo, int hi, int i, int val)
{

    if(i>hi || i<lo)    return;

    if(lo==hi)
    {
        tree[node] = val;
        return;
    }

    int left  = 2*node;
    int right = 2*node+1;
    int mid   = (lo+hi)>>1;


    update(left, lo, mid, i, val);

    update(right, mid+1, hi, i, val);

    tree[node] = min(tree[left], tree[right]);

}

int main()
{

   // freopen("in.txt", "r", stdin);
  //  freopen("out.txt", "w", stdout);

    int test, cs = 0;

    scanf("%d", &test);

    while(test--){

        int n, k;

        scanf("%d %d", &n, &k);

        for(int i = 0; i<n; i++) scanf("%d", &a[i]);

        sort(a, a+n);


        for(int i = 0; i<=n; i++) dp[i] = inf;
        dp[n] = 0;
        a[n] = inf+inf;

        build(1, 0, n);

        for(int i = n-1; i>=0; i--){

            dp[i] = inf;

            int R = upper_bound(a, a+n, a[i] + 2*k) - a;

            if(i+3>R){
                continue;
            }

            int q = query(1, 0, n, i+3, R);

            dp[i] = 1 + q;

            update(1, 0, n, i, dp[i]);
        }

        int ret = (dp[0]>=inf?-1:dp[0]);

        printf("Case %d: %d\n", ++cs, ret);
    }

    return 0;
}

