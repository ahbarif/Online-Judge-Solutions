#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
 
int main()
{
 
        int test, cs = 0;
 
        scanf("%d", &test);
 
        while(test--)
        {
            double l, w;
 
            double angle, r, s;
 
            scanf("%lf : %lf", &l, &w);
 
            r = sqrt(l*l + w*w);
 
            angle = atan(w/l);
 
            s = r * angle;
 
            double ra = 400.0 / (2.0 * l + 2 * s);
 
            printf("Case %d: %.10lf %.10lf\n", ++cs, l*ra, w * ra);
 
 
        }
 
    return 0;
 
}
 