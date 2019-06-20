#include<bits/stdc++.h>
using namespace std;

 void divisors( long long x, int s)
{
    long long i, p=0, ans=1;

    while(x%2==0)
    {
        x/=2;
        p++;
    }
    ans*=(p+1);

    for(i=3; i*i<=x; i+=2)
    {
        p=0;
        while(x%i==0)
        {
            x/=i;
            p++;
        }

        ans*=(p+1);

    }
    if(x>1) ans*=2;
    printf("Case %d: %lld\n", s, --ans);

}

int main()
{

    int test, i;
    long long n;

    scanf("%d", &test);

    for(i=1; i<=test; i++)
    {
        scanf("%lld", &n);
        divisors(n, i);
    }

return 0;
}
