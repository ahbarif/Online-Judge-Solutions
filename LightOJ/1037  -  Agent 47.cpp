#include <bits/stdc++.h>
using namespace std;

#define     debug(x)    cerr << #x " = " << (x) << endl

double solve()
{
    double a, b, c, d, area, x, h, res;

    scanf("%lf %lf %lf %lf", &a, &b, &c, &d);

    x = fabs(a-c);

    double s = (x+b+d)*0.5;

    area = sqrt(s*(s-x)*(s-b)*(s-d));

    h = 2.0*area/x;

    res = 0.5 * h * (a+c);

    return res;
}

int main()
{


    int test, cs = 0;

    scanf("%d", &test);

    while(test--)
    {
        printf("Case %d: %.10lf\n", ++cs, solve());
    }


}
