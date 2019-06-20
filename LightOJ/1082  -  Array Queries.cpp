#include<bits/stdc++.h>
using namespace std;
 
const int N = 100005;
 
int a[N];
int SegTree[4*N];
 
void construct_tree(int node, int lo, int hi)
{
        if(lo==hi)
        {
            SegTree[node]=a[lo];
            return;
        }
 
        int left  = node * 2;
        int right = left + 1;
        int mid   = (lo+hi)>>1;
 
        construct_tree(left, lo, mid);
        construct_tree(right, mid+1, hi);
 
        SegTree[node]=min(SegTree[left], SegTree[right]);
 
}
 
int tree_query(int node, int lo, int hi, int i, int j)
{
 
        if(i>hi || j<lo)    return INT_MAX;
 
        if(i<=lo && j>=hi)  return SegTree[node];
 
        int left  = node * 2;
        int right = left + 1;
        int mid   = (lo+hi)>>1;
 
        int x = tree_query(left, lo, mid, i, j);
        int y = tree_query(right, mid + 1, hi, i, j);
 
        return min(x, y);
 
}
 
int main()
{
 
        int n, i, query, x, y, T, csn;
 
        scanf("%d", &T);
 
        for(csn=1; csn<=T; csn++)
        {
 
                scanf("%d %d", &n, &query);
 
                for(i=1; i<=n; i++) scanf("%d", &a[i]);
 
                construct_tree(1, 1, n);
 
                printf("Case %d:\n", csn);
 
                while(query--)
                {
                    scanf("%d %d", &x, &y);
 
                    printf("%d\n", tree_query(1, 1, n, x, y));
                }
 
        }
 
  return 0;
}