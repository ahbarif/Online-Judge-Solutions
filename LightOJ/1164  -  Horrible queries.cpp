#include <bits/stdc++.h>
using namespace std;
 
typedef long long Long;
const int sz = 100005;
 
Long tree[sz*4], lazy[sz*4], a[sz];
 
void construct(int node, int b, int e)
{
 
    if (b > e)     return;
 
    if (b == e)
    {
        tree[node] = a[b];
        return;
    }
 
    int mid = (b + e)/2;
 
    construct(2*node, b, mid);
 
    construct(2*node + 1, mid+1, e);
 
    tree[node] = tree[2*node] + tree[2*node+1];
}
 
void RangeUpdate(int node, int b, int e, int i, int j, int val)
{
 
    int Left = node*2, Right = 1 + node*2;
 
    if (lazy[node] != 0)
    {
        tree[node] += (e-b+1)*lazy[node];
 
        if (b != e)
        {
            lazy[Left]  += lazy[node];
            lazy[Right] += lazy[node];
        }
 
        lazy[node] = 0;
    }
 
    if (b>e || b>j || e<i)   return;
 
    if (b>=i && e<=j)
    {
        tree[node] += ( e - b + 1)*val;
 
        if (b != e)
        {
            lazy[Left]   += val;
            lazy[Right]  += val;
        }
        return;
    }
 
    int mid = (b+e) >> 1;
 
    RangeUpdate(Left, b, mid, i, j, val);
 
    RangeUpdate(Right, mid+1, e, i, j, val);
 
    tree[node] = tree[Left] + tree[Right];
}
 
Long Query(int node, int b, int e, int i, int j)
{
    int Left = node*2, Right = 1 + node*2;
 
    if (lazy[node] != 0)
    {
        tree[node] += (e - b + 1)*lazy[node];
 
        if (b != e)
        {
            lazy[Left] += lazy[node];
            lazy[Right] += lazy[node];
        }
 
        lazy[node] = 0;
    }
 
    if (b>e || b>j || e<i)     return 0LL;
 
 
    if (b>=i && e<=j)     return tree[node];
 
    int mid = (b + e) >> 1;
 
    return Query(Left, b, mid, i, j) +  Query(Right, mid+1, e, i, j);
}
 
 
int main()
{
 
        int test, cs = 1;
 
        scanf("%d", &test);
 
        while(test--)
        {
            int n, query, t, u, v;
            Long x;
 
            scanf("%d %d", &n, &query);
 
            memset(tree, 0, sizeof tree);
            memset(lazy, 0, sizeof lazy);
 
            printf("Case %d:\n", cs++);
 
            while(query--)
            {
                scanf("%d", &t);
 
                if(t)
                {
                    scanf("%d %d", &u, &v);
 
                    printf("%lld\n", Query(1, 0, n-1, u, v));
                }
 
                else
                {
                    scanf("%d %d %d", &u, &v, &x);
 
                    RangeUpdate(1, 0, n-1, u, v, x);
                }
            }
        }
 
    return 0;
}
 