#include<bits/stdc++.h>
using namespace std;
 
double L, arc, c, n, eps = 1e-9;
 
double f(double h)
{
    double x = L/2.0;
 
    double r = (h/2.0) + (x*x/(2.0*h));
 
    double a = 2 * asin(x/r);
 
    return a*r;
}
 
int main()
{
    int test, cs = 0;
 
    cin>>test;
 
    while(test--)
    {
        cin>>L>>n>>c;
 
        arc = (1.0 + (n*c)) * L;
 
        double lo = 0.0, hi = L, mid;
 
        for(int j = 0; j<100; j++)
        {
 
            mid = (hi+lo)/2.0;
 
            if(f(mid)>arc) hi = mid;
 
            else lo = mid;
        }
 
        printf("Case %d: %lf\n",++cs,mid);
    }
    return 0;
}
 