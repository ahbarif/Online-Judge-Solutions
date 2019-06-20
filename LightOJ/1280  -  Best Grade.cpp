#include <bits/stdc++.h>
using namespace std;

pair<double, double> a[20001];
double f[20001];
int n, d;
const double eps = 1e-9;

bool possible(double mid){
        for(int i = 0; i<n; i++) f[i] = a[i].first - mid*a[i].second;

        sort(f, f+n);

        double ret = 0.0;

        for(int i = d; i<n; i++) ret += f[i];

        return ret+eps>=0.0;
}

int main()
{

    int test, cs = 0;

    scanf("%d", &test);

    while(test--)
    {

        scanf("%d %d", &n, &d);

        for(int i = 0; i<n; i++)
        {
            scanf("%lf %lf", &a[i].first, &a[i].second);
        }

        double lo = 0, hi = 100.0, mid, ans = 0.0;

        for(int j = 0; j<50; j++){
            mid = (lo+hi)/2.0;
            if(possible(mid)){
                ans = mid;
                lo = mid;
            }
            else hi = mid;
        }

        printf("Case %d: %.10lf\n", ++cs, ans*100);
    }

    return 0;
}
/*
1
4 2
100 100
9 90
90 900
1 30
*/

