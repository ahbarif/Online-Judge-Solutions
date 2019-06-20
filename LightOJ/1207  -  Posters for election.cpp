#include <bits/stdc++.h>
using namespace std;

const int sz = 200005;

int tree[sz*4];
bool flag[sz];
int res = 0;

inline void pushDown(int node, int left, int right)
{
    tree[left] = tree[right] = tree[node];
    tree[node] = 0;
}

void update(int node, int s, int t, int rs, int rt, int col)
{
    if(t < rs || rt < s) return;
    if(rs <= s && t <= rt)
    {
        tree[node] = col;
        return;
    }

    int left = node << 1, right = left | 1, mid = (s + t) >> 1;

    if(tree[node]) pushDown(node, left, right);

    update(left, s, mid, rs, rt, col);
    update(right, mid+1, t, rs, rt, col);
}

void Update(int node, int b, int e, int i, int j, int index)
{

    if(i>e || j<b)  return;

    if(b>=i && j>=e)
    {
        tree[node] = index;
        return;
    }

    int Left = node<<1, Right = Left|1, mid = (b+e) >> 1;

    if(tree[node])
    {
        tree[Left] = tree[node];
        tree[Right] = tree[node];
        tree[node] = 0;
    }

    Update(Left, b, mid, i, j, index);
    Update(Right, mid+1, e, i, j, index);


}

void query(int node, int b, int e)
{
    if(b>e) return;

    if (tree[node])
    {
        if(flag[tree[node]]==false) res++;
        flag[tree[node]] = true;
        return;
    }

    if(b==e)
    {
        return;
    }

    int mid = (b + e)/2;

    query(node*2, b, mid);

    query(node*2+1, mid+1, e);
}


int main()
{
    int test, cs = 0;

    scanf("%d", &test);

    while(test--)
    {


        memset(flag, 0, sizeof(flag));

        memset(tree, 0, sizeof(tree));

        int n, u, v;

        scanf("%d", &n);

        for(int i = 1; i<=n; i++)
        {
            scanf("%d %d", &u, &v);
            Update(1, 1, n*2, u, v, i);
        }

        res = 0;
        query(1, 1, n*2);

        printf("Case %d: %d\n", ++cs, res);
    }
}

