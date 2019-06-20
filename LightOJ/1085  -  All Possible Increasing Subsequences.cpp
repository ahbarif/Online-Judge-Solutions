#include<bits/stdc++.h>
using namespace std;

const int sz = 100005;
const long long mod = 1000000007LL;

long long tree[sz*4];

struct data{
    long long x;
    int id;

    bool operator<(const data &p)const{
        if(x==p.x)return id>p.id;
        return x<p.x;
    }
}a[sz];

void construct(int node, int i, int j)
{
    memset(tree, 0, sizeof(tree));
    return;
}

void update(int node, int i, int j, int x, int key)
{
    if(i==x && j==x)
    {
        tree[node] = key%mod;
        return;
    }

    int Left = node*2;
    int Right = Left + 1;
    int mid = (i+j)/2;

    if(x<=mid)  update(Left, i, mid, x, key);
    else update(Right, mid+1, j, x, key);

    tree[node] = tree[Left] + tree[Right];

    tree[node]%=mod;

    return;
}


long long query(int node, int i, int j, int x, int y)
{

    if(x>y)return 0;

    if(i==x && j==y)    return tree[node];

    int Left = 2*node;
    int Right = Left + 1;
    int mid = (i+j)/2;

    long long l = query(Left, i, mid, x, min(y, mid))%mod;
    long long r = query(Right, mid+1, j, max(x, mid+1), y)%mod;

    long long res = (l+r);
    return res%mod;

}

int main()
{

        int test, cs = 0;

        scanf("%d", &test);

        while(test--)
        {

            int n, i;

            data d;

            scanf("%d", &n);

            construct(1, 1, n);

            for(i = 1; i<=n; i++)
            {
                scanf("%lld", &d.x);
                d.id = i;
                a[i] = d;
            }

            sort(a+1, a+n+1);

            for(int i = 1; i<=n; i++)
            {
                long long res = 1 + query(1, 1, n, 1, a[i].id - 1);

                update(1, 1, n, a[i].id, res);
            }

            printf("Case %d: %lld\n", ++cs, query(1, 1, n, 1, n));
        }

        return 0;
}
