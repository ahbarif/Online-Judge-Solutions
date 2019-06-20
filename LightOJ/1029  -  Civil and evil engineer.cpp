// Minimum spanning tree

#include <bits/stdc++.h>
using namespace std;

int par[105];

struct edge
{
    int u, v, w;

    edge() {}
    edge(int _u, int _v, int _w)
    {
        u = _u;
        v = _v;
        w = _w;
    }

    bool operator<(const edge &p)const
    {
        return w<p.w;
    }
};


void makeset()
{
    for(int i=0; i<105; i++)    par[i] = i;
}

int find_par(int n)
{
    if (par[n]==n) return n;
    par[n]=find_par(par[n]);
    return par[n];
}

void union_(int x, int y)
{
    int u = find_par(x);
    int v = find_par(y);

    if(u==v)    return;
    par[u] = v;
}

int main()
{

    vector<edge> E;

    int n, m, x, y, z, i, test, cs=1, mycity;

    scanf("%d", &test);

    while(test--)
    {

        makeset();
        E.clear();

        scanf("%d", &n, &m);

        int lo = 0, hi = 0;

        while(1)
        {
            scanf("%d %d %d", &x, &y, &z);
            if(x+y+z==0)    break;
            E.push_back(edge(x, y, z));
        }

        sort(E.begin(), E.end());

        for(i=0; i<E.size(); i++)
        {
            x = E[i].u;
            y = E[i].v;
            z = E[i].w;

            if(find_par(x)==find_par(y))    continue;

            else
            {
                union_(x, y);
                lo += z;
            }
        }

        makeset();
        reverse(E.begin(), E.end());

        for(i=0; i<E.size(); i++)
        {
            x = E[i].u;
            y = E[i].v;
            z = E[i].w;

            if(find_par(x)==find_par(y))    continue;

            else
            {
                union_(x, y);
                hi += z;
            }
        }

        int total = (hi+lo);

        printf("Case %d: ", cs++);

        if(total%2==0)  printf("%d\n", total/2);
        else printf("%d/%d\n", total, 2);

    }

    return 0;
}
