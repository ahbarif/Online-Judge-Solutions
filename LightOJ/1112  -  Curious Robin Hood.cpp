#include <bits/stdc++.h>
using namespace std;
 
int a[100005];
class segmentTree
{
 
public:
    int tree[400055];
 
    void min_init(int node, int i, int j)
    {
        if(i==j)
        {
            tree[node] = a[i];
            return;
        }
 
 
        int lt = node*2;
        int rt = lt+1;
        int mid = (i+j)>>1;
 
        min_init(lt, i, mid);
        min_init(rt, mid+1, j);
 
        tree[node] = min(tree[lt], tree[rt]);
    }
 
    int min_query(int node, int i, int j, int x, int y)
    {
        if(x>y) return INT_MAX;
        if(i==x && j==y)    return tree[node];
 
        int lt = node*2;
        int rt = lt+1;
        int mid = (i+j)>>1;
 
        int l = min_query(lt, i, mid, x, min(y, mid));
        int r = min_query(rt, mid+1, j, max(x, mid+1), y);
 
        return min(l, r);
    }
 
    void min_update(int node, int i, int j, int x, int key)
    {
        if(i==x && j==x)
        {
            tree[node] = key;
            return;
        }
 
        int lt = node*2;
        int rt = lt+1;
        int mid = (i+j)>>1;
 
        if(x<=mid)  min_update(lt, i, mid, x, key);
        else min_update(rt, mid+1, j, x, key);
 
        tree[node] = min(tree[lt], tree[rt]);
    }
 
    void sum_init(int node, int i, int j)
    {
        if(i==j)
        {
            tree[node] = a[i];
            return;
        }
 
        int lt = node*2;
        int rt = lt+1;
        int mid = (i+j)>>1;
 
        sum_init(lt, i, mid);
        sum_init(rt, mid+1, j);
 
        tree[node] = tree[lt] + tree[rt];
    }
 
    int sum_query(int node, int i, int j, int x, int y)
    {
        if(x>y) return 0;
        if(i==x && j==y)    return tree[node];
 
        int lt = node*2;
        int rt = lt+1;
        int mid = (i+j)>>1;
 
        int l = sum_query(lt, i, mid, x, min(y, mid));
        int r = sum_query(rt, mid+1, j,  max(x, mid+1), y);
 
        return l+r;
    }
 
    void sum_update(int node, int i, int j, int x, int key)
    {
 
        if(i==x && j==x)
        {
            tree[node] = key;
            return;
        }
 
        int lt = node*2;
        int rt = lt+1;
        int mid = (i+j)>>1;
 
        if(x<=mid)  sum_update(lt, i, mid, x, key);
        else sum_update(rt, mid+1, j, x, key);
 
        tree[node] = tree[lt] + tree[rt];
    }
};
 
segmentTree sgt;
 
int main()
{
 
    int test, cs = 1, n, i, j, q;
 
    scanf("%d", &test);
 
    while(test--)
    {
        scanf("%d %d", &n, &q);
 
        for(i=1; i<=n; i++)    scanf("%d", &a[i]);
 
        sgt.sum_init(1, 1, n);
 
        printf("Case %d:\n", cs++);
 
        while(q--)
        {
                int querytype;
 
                scanf("%d", &querytype);
 
                if(querytype==1)
                {
                    int x;
                    scanf("%d", &x);
 
                    printf("%d\n", a[x+1]);
                    a[x+1] = 0;
 
                    sgt.sum_update(1, 1, n, x+1, 0);
                }
 
                else if(querytype==2)
                {
                    int x, v;
                    scanf("%d %d", &x, &v);
                    x++;
 
                    int y = a[x]+v;
                    a[x] = y;
                //    cout<<"new = "<<y<<endl;
                    sgt.sum_update(1, 1, n, x, y);
                }
 
                else
                {
                    int u, v;
                    scanf("%d %d", &u, &v);
 
                    u++;v++;
 
                    printf("%d\n", sgt.sum_query(1, 1, n, u, v));
 
                }
        }
 
    }
 
    return 0;
 
}