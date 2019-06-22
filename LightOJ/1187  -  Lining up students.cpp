#include <bits/stdc++.h>
using namespace std;


const int N = 100005;
int a[N], tree[N*4];

void build(int node, int st, int en){

    if(st==en){
        tree[node] = 1;
        return;
    }

    int mid = (st+en)/2, l = node*2, r = l|1;
    build(l, st, mid);
    build(r, mid+1, en);
    tree[node] = tree[l] + tree[r];
}

int query(int node, int st, int en, int v)
{
    if(st == en) return st;

    int mid = (st+en)/2, l = node*2, r = l|1;

    int lSum = tree[l], rSum = tree[r];

    if(rSum >= v) return query(r, mid+1, en, v);

    else return query(l, st, mid, v - rSum);

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
    int right = left + 1;
    int mid   = (lo+hi)>>1;


    update(left, lo, mid, i, val);

    update(right, mid+1, hi, i, val);

    tree[node] = tree[left] + tree[right];

}


int main(){


    int test, cs = 0;

    scanf("%d", &test);

    while(test--){

        int n;

        scanf("%d", &n);

        build(1, 1, n);

        for(int i = 1; i<=n; i++) scanf("%d", &a[i]);

        int x;

        for(int i = n; i>0; i--){
            x = query(1, 1, n, a[i]+1);
            update(1, 1, n, x, 0);
        }

        printf("Case %d: %d\n", ++cs, x);
    }

}

