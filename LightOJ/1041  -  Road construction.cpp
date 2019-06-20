#include <bits/stdc++.h>
using namespace std;

map<string, string> par;
vector<string> v;
struct edge
{
    string u, v;
    int w;

    edge() {}
    edge(string _u, string _v, int _w)
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


void makeset(string s)
{
    par[s] = s;
}

string find_par(string n)
{
    if (par[n]==n) return n;
    par[n]=find_par(par[n]);
    return par[n];
}

void union_(string x, string y)
{
    string u = find_par(x);
    string v = find_par(y);

    if(u==v)    return;
    par[u] = v;
}

int main()
{

    vector<edge> E;
    int n, m, z, i, test, cs=1;
    string x, y;

    scanf("%d", &test);

    while(test--)
    {

        par.clear();

        v.clear();
        E.clear();

        scanf("%d", &m);

        int lo = 0;

        while(m--)
        {
            cin>>x>>y>>z;
            makeset(x);
            makeset(y);
            v.push_back(x);
            v.push_back(y);
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

        int flag = 1;
        string t = find_par(v[0]);
        for(i=1; i<v.size(); i++)
        {
            if(find_par(v[i])!=t)   flag = 0;
        }

        if(!flag)   printf("Case %d: Impossible\n", cs++);
        else printf("Case %d: %d\n", cs++, lo);

    }

    return 0;
}
