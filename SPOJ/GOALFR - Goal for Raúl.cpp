#include<bits/stdc++.h>
using namespace std;

struct point{
    double x, y;

    point(){}

    point(double _x, double _y)
    {
        x = _x;
        y = _y;
    }

};

point a, b, p;

const double eps = 1e-9;

double f(point m)
{
    return sqrt((p.x - m.x)*(p.x - m.x) + (p.y - m.y)*(p.y - m.y));
}


double solve(point a, point b)
{

    point hi = b, lo = a, m1, m2;

    for(int j = 0; j<100; j++)
    {

        double d1 = (hi.x - lo.x)/3.0;
        double d2 = (hi.y - lo.y)/3.0;

        m1 = point(lo.x + d1, lo.y + d2);

        m2 = point(hi.x - d1, hi.y - d2);

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
            double r;
            point a, b, c;
            cin>>a.x>>a.y;
            cin>>p.x>>p.y>>r;
            b = point(52.5, 3.66);
            c = point(52.5, -3.66);

            double ffa = solve(a, b);
            double ffb = solve(a, c);

         //   cout<<"dis = "<<fixed<<setprecision(5)<<ffa<<" "<<ffb<<endl;

            if(ffa+eps<=r && ffb+eps<=r) cout<<"No goal..."<<endl;
            else cout<<"Goal!"<<endl;
        }

}


