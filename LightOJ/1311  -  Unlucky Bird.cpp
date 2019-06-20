#include<bits/stdc++.h>
using namespace std;
void solve()
{

        double a1, a2, v1, v2, v3, t1, t2, t, bird, train, d1, d2;

        cin>>v1>>v2>>v3>>a1>>a2;

        t1=v1/a1;
        t2=v2/a2;

        t=(t1>t2)?t1:t2;

        bird=v3*t;

        d1=v1*t1 - 0.5*a1*t1*t1;
        d2=v2*t2 - 0.5*a2*t2*t2;

        train=d1+d2;

        printf("%.10lf %.10lf\n", train, bird);

}

int main()
{

            int test, i=1;

            cin>>test;

            while(test--)
            {
                cout<<"Case "<<i++<<": ";
                solve();

            }


    return 0;
}
