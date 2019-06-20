#include<bits/stdc++.h>
using namespace std;

void solve(int i)
{

        double w, p, q, k, x, y, c;

        scanf("%lf %lf %lf", &x, &y, &c);

        double lo=0.00, hi=x+y+x+y, mid;

        while(true)
        {
                mid=(lo+hi)/2.0;

                p=sqrt(x*x-mid*mid);
                q=sqrt(y*y-mid*mid);

                k=(p*q)/(p+q);

                if(abs(k-c)<0.000000001)   break;
                else if(k>c)    lo=mid;
                else hi=mid;

        }

        printf("Case %d: %.8lf\n", i, mid);

}



int main()
{
        int test, i=0;

        cin>>test;

        while(test--)
        {
            i++;
            solve(i);
        }

        return 0;
}
