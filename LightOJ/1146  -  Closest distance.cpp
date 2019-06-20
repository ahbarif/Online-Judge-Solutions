#include<bits/stdc++.h>
using namespace std;

struct point{
    double x, y;
};

const double eps = 1e-9;

double euclidean_distance(point a, point b)
{
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

point a, b, c, d, ff, ss;

double f(double mid)
{
    ff.x = a.x + mid*(b.x - a.x);
    ff.y = a.y + mid*(b.y - a.y);

    ss.x = c.x + mid*(d.x - c.x);
    ss.y = c.y + mid*(d.y - c.y);

    return euclidean_distance(ss, ff);
}

double solve()
{
    double hi = 1.0, lo = 0.0, m1, m2;

    for(int j = 0; j<100; j++)
    {

        m1 = (2.0*lo + hi)/3.0;
        m2 = (2.0*hi + lo)/3.0;

        if(f(m1)<f(m2)) hi = m2;
        else lo = m1;

    }

    return min(f(m1), f(m2));

}


int main()
{

        int test, cs = 0;

        cin>>test;

        while(test--)
        {
            cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y>>d.x>>d.y;

            cout<<"Case "<<++cs<<": ";

            cout<<std::fixed<<std::setprecision(8)<<solve()+eps<<endl;
        }

        return 0;


}
