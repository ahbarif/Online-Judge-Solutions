#include<bits/stdc++.h>
using namespace std;

long long gcd(long a, long b)
{
    if(a==0)    return b;
    if(b==0)    return a;
    return a%b ? gcd(b, a%b) : b;

}

int main()
{

      long long int test, a, b, x, y;
      long long int d1, d2, k, i, ans;

       scanf("%lld", &test);

       for(i=1; i<=test; i++)
       {
           scanf("%lld %lld %lld %lld", &a, &b, &x, &y);

           if(a==x)         ans=abs(b-y);
           else if(b==y)    ans=abs(a-x);
           else if(a==-x && b==-y)  ans=abs(a-x);
           else
           {

               d1=abs(y-b);
               d2=abs(a-x);
               k=gcd(d1, d2);
               k=d1/k;
               ans=d1/k;

           }


           printf("Case %lld: %lld\n", i, ++ans);
       }
    return 0;
}
