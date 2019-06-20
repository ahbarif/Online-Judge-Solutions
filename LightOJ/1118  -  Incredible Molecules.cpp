#include<bits/stdc++.h>
using namespace std;

const double eps = 1e-9;

double solve()
{
    double x1, y1, x2, y2, r1, r2;

    scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &r1, &x2, &y2, &r2);

    double res = 0.0;

    double d = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));

    double dsq = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);

    if(d>=(r1+r2))  return res;

    if(d<=fabs(r1-r2))
    {
        res = min(r1, r2)*min(r1, r2)*acos(-1.0);
        return res;
    }

    double angle_a = 2.0 * acos((r1*r1 + dsq - r2*r2)/(2.0*r1*d));

    double angle_b = 2.0 * acos((r2*r2 + dsq - r1*r1)/(2.0*r2*d));

    double curve1 = 0.5 * angle_a * r1* r1;

    double curve2 = 0.5 * angle_b * r2* r2;

    res = 0.5 * (r1*r1*(angle_a - sin(angle_a))+ r2*r2*(angle_b - sin(angle_b)));

    return res;

}

int main()
{

        printf("%.10lf\n",  solve()+eps);


}
