#include <bits/stdc++.h>
using namespace std;

const int sz = 100005;

struct data
{
    int zero, one, two;

    data()
    {
        zero = 1;
        one = 0;
        two = 0;
    }

} tree[sz*4];

int lazy[sz*4];

void construct(int node, int b, int e)
{

    if (b > e)     return;

    if (b == e)
    {
        tree[node] = data();
        return;
    }

    int mid = (b + e)/2;

    construct(2*node, b, mid);

    construct(2*node + 1, mid+1, e);

    tree[node].zero = tree[2*node].zero + tree[2*node+1].zero;
    tree[node].one = tree[2*node].one + tree[2*node+1].one;
    tree[node].two = tree[2*node].two + tree[2*node+1].two;
}

void RangeUpdate(int node, int b, int e, int i, int j)
{

    int Left = node*2, Right = 1 + node*2;

    if(b>=i && e<=j)    lazy[node]++;

    if (lazy[node] != 0)
    {
        int ss = lazy[node]%3;

        while(ss--)
        {
            int temp = tree[node].zero;
            tree[node].zero = tree[node].two;
            tree[node].two = tree[node].one;
            tree[node].one = temp;
        }

        if (b != e)
        {
            lazy[Left]  += lazy[node];
            lazy[Right] += lazy[node];
        }

        else
        {
            int ss = lazy[node]%3;
        }

        lazy[node] = 0;
    }

    if(b>=i && e<=j)    return;

    if (b>e || b>j || e<i)   return;

    int mid = (b+e) /2;

    RangeUpdate(Left, b, mid, i, j);

    RangeUpdate(Right, mid+1, e, i, j);

    tree[node].zero = tree[2*node].zero + tree[2*node+1].zero;
    tree[node].one = tree[2*node].one + tree[2*node+1].one;
    tree[node].two = tree[2*node].two + tree[2*node+1].two;

    return;
}

int Query(int node, int b, int e, int i, int j)
{
    int Left = node*2, Right = 1 + node*2;



    if (lazy[node] != 0)
    {
        int ss = lazy[node]%3;

        while(ss--)
        {
            int temp = tree[node].zero;
            tree[node].zero = tree[node].two;
            tree[node].two = tree[node].one;
            tree[node].one = temp;
        }

        if (b != e)
        {
            lazy[Left]  += lazy[node];
            lazy[Right] += lazy[node];
        }

        lazy[node] = 0;
    }

    if (b>e || b>j || e<i)     return 0;

    if (b>=i && e<=j)     return tree[node].zero;

    int mid = (b + e) >> 1;

    return Query(Left, b, mid, i, j) +  Query(Right, mid+1, e, i, j);
}


int main()
{


    int test, cs = 0;

    scanf("%d", &test);

    while(test--)
    {


        memset(lazy, 0, sizeof(lazy));

        int n, q, x, y, t;

        scanf("%d %d", &n, &q);

        construct(1, 1, n);

        printf("Case %d:\n", ++cs);

        while(q--)
        {
            scanf("%d %d %d", &t, &x, &y);

            if(t==0)
            {
                RangeUpdate(1, 1, n, x+1, y+1);
            }

            else
            {
                printf("%d\n", Query(1, 1, n, x+1, y+1));
            }

        }

    }

    return 0;
}
