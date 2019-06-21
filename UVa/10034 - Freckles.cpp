#include<bits/stdc++.h>
using namespace std;

const int mx = 1005;

struct point
{
    double x, y;

    point() {}

    point(double x, double y) : x(x), y(y) {}

};

double distancee(point a, point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

struct edge
{
    int u, v;

    double w;

    edge(int u, int v, double w): u(u), v(v), w(w) {}

    bool operator<(const edge &p)const
    {
        return w<p.w;
    }
};

vector<edge> E;
int par[mx];

void makeset(int n)
{
    par[n] = n;
}

int find_par(int n)
{
    if (par[n]==n) return n;
    par[n]=find_par(par[n]);
    return par[n];
}

void Merge(int x, int y)
{
    int u = find_par(x);
    int v = find_par(y);

    if(u==v)    return;
    par[u] = v;
}

point a[1005];

void Kruskal()
{
    double res = 0.0;

    sort(E.begin(), E.end());

    for(int i=0; i<E.size(); i++)
    {

        if(find_par(E[i].u)==find_par(E[i].v))    continue;

        else
        {
            Merge(E[i].u, E[i].v);

            res += E[i].w;
        }
    }

    cout<<std::fixed<<std::setprecision(2)<<res<<endl;
}

int main()
{



    int test;

    cin>>test;

    for(int k = 0; k<test; k++)
    {
        if(k)   puts("");
        
        int n;

        cin>>n;

        E.clear();

        for(int i = 0; i<n; i++)    cin>>a[i].x >> a[i].y;

        for(int i=0; i<mx; i++)    makeset(i);

        for(int i = 0; i<n; i++)
        {
            for(int j = i+1; j<n; j++)
            {
                E.push_back(edge(i, j, distancee(a[i], a[j])));
            }
        }

        Kruskal();
    }



}
