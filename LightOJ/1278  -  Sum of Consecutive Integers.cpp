#include<bits/stdc++.h>
using namespace std;

void odd_divisors(long long n)
{
   int a=0, ans=1;
   long long i;

   while(n%2==0) n/=2;

   for(i=3; i*i<=n; i+=2)
   {
       a=0;
           while(n%i==0)
           {
               n/=i;
               a++;
           }
       if(a)    ans*=(a+1);
   }
   if(n>1)  ans*=2;

   cout<<--ans<<endl;
}

int main()
{
    int test, i;
    long long x;

    scanf("%d", &test);

    for(i=0; i<test; i++)
    {
        scanf("%lld", &x);
        printf("Case %d: ", i+1);
        odd_divisors(x);
    }
    return 0;
}
