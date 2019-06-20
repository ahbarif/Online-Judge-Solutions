#include<bits/stdc++.h>
using namespace std;
const double pi=acos(-1);
int main(){

    double ox, oy, ax, ay, bx, by;

    double a, b, o, angle, ans;

    int n, i;

    cin>>n;

    for(i=1; i<=n; i++){

       cin>>ox>>oy>>ax>>ay>>bx>>by;

       a=sqrt(((ox-bx)*(ox-bx))+((oy-by)*(oy-by)));
       b=sqrt(((ox-ax)*(ox-ax))+((oy-ay)*(oy-ay)));
       o=sqrt(((ax-bx)*(ax-bx))+((ay-by)*(ay-by)));

       angle=acos((a*a+b*b-o*o)/(2*a*b));

       ans=a*angle;

       printf("Case %d: %.8lf\n", i, ans);

    }

    return 0;
}