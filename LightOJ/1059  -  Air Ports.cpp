#include <bits/stdc++.h>
using namespace std;
 
int par[10005];
 
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
    for(int i=0; i<10005; i++)    par[i] = i;
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
 
    int n, m, A, x, y, z, i, test, cs = 0;
 
    scanf("%d", &test);
 
    while(test--)
    {
 
        makeset();
        E.clear();
 
        scanf("%d %d %d", &n, &m, &A);
 
        int res = 0, cnt = 0;
 
        while(m--)
        {
            scanf("%d %d %d", &x, &y, &z);
            if(x+y+z==0)    break;
            if(z<A) E.push_back(edge(x, y, z));
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
                res += z;
            }
        }
 
        set<int> st;
 
        for(i = 1; i<=n; i++)
        {
            st.insert(find_par(i));
        }
 
        cnt = st.size();
 
        printf("Case %d: %d %d\n", ++cs, res + A*cnt, cnt);
    }
 
    return 0;
}