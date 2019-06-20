#include<bits/stdc++.h>
using namespace std;

struct point{
    double x, y, z;

    point(){}

    point(double _x, double _y, double _z)
    {
        x = _x;
        y = _y;
        z = _z;
    }

};

point a, b, p;

const double eps = 1e-9;

double f(point m)
{
    return sqrt((p.x - m.x)*(p.x - m.x) + (p.y - m.y)*(p.y - m.y) + (p.z - m.z)*(p.z - m.z));
}


double solve(point a, point b, point p)
{

    point hi = b, lo = a, m1, m2;

    for(int j = 0; j<100; j++)
    {

        double d1 = (hi.x - lo.x)/3.0;
        double d2 = (hi.y - lo.y)/3.0;
        double d3 = (hi.z - lo.z)/3.0;

        m1 = point(lo.x + d1, lo.y + d2, lo.z + d3);

        m2 = point(hi.x - d1, hi.y - d2, hi.z - d3);

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
            cin>>a.x>>a.y>>a.z>>b.x>>b.y>>b.z>>p.x>>p.y>>p.z;

            cout<<"Case "<<++cs<<": ";

            cout<<std::fixed<<std::setprecision(8)<<solve(a, b, p)+eps<<endl;
        }

        return 0;


}
