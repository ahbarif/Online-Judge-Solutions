#include<bits/stdc++.h>
using namespace std;
const double pi=acos(-1);
const double eps=1e-9;
int main(){

   int test, i;

   double r1, r2, r3, a, b, c, s, area, result, A, B, C;

   cin>>test;

   for(i=1; i<=test; i++){

    cin>>r1>>r2>>r3;

    a=r1+r2; b=r2+r3; c=r3+r1;

    s=(a+b+c)/2.0;

    area=sqrt(s*(s-a)*(s-b)*(s-c));

    A=acos((b*b+c*c-a*a)/(2*b*c));

    B=acos((a*a+c*c-b*b)/(2*a*c));

    C=acos((b*b+a*a-c*c)/(2*b*a));

    result=area-0.5*(B*r1*r1 + C*r2*r2 + A*r3*r3);

    printf("Case %d: %.8lf\n", i, result+eps);


   }


    return 0;


}
