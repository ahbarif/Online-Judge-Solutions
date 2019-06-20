# include<bits/stdc++.h>
using namespace std;

void solve(double r1, double r2, double h, double p)
{

        double a1, a2, area, x, pi=acos(-1.0), r3;

        x= (h*r2)/(r1-r2);
        r3=(r2/x)*(p+x);
        a1=(1/3.0)*pi*r3*r3*(p+x);
        a2=(1/3.0)*pi*r2*r2*x;
        area = a1-a2;
        printf("%.9lf\n", area);



}

int main()
{
       int test, caseno=0;

       double a, b, c, d;

       cin>>test;

       while(test--)
       {
           cin>>a>>b>>c>>d;
           printf("Case %d: ", ++caseno);
           solve(a, b, c, d);
       }


   return 0;
}
