#include<bits/stdc++.h>
using namespace std;
 
int a[100005];
int idx;
 
void factorize(long long n)
{
    n = (n<0?-n:n);
 
    idx = 0;
 
    if(n%2==0)
    {
        while(n%2==0)
        {
            a[idx]++;
            n>>=1;
        }
        idx++;
    }
 
    long long i;
 
    for(i=3; i*i<=n; i+=2)
    {
        if(n%i==0)
        {
            while(n%i==0)
            {
                a[idx]++;
                n/=i;
            }
            idx++;
        }
    }
 
    if(n>1) a[idx++] = 1;
}
 
int main()
{
 
        int test, caseno = 0;
 
        scanf("%d", &test);
 
        for(caseno = 1; caseno <= test; caseno++)
        {
                memset(a, 0, sizeof(a));
                long long n;
                scanf("%lld", &n);
                factorize(n);
                int ans = 0;
 
                for(int i=0; i<idx; i++)    ans = __gcd(ans, a[i]);
 
                if(n<0)
                {
                    while(ans%2==0) ans>>=1;
                }
 
                printf("Case %d: %d\n", caseno, ans);
 
        }
 
        return 0;
}
 