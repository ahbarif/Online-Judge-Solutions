#include<bits/stdc++.h>
using namespace std;
 
int main()
{
 
    int T, caseno = 1;
 
    scanf("%d", &T);
 
    while(T--)
    {
 
        long long n, c, ans, x1, x2, f1, f2;
 
        scanf("%lld %lld", &n, &c);
 
        if(n==0)    ans = 0;
 
        else
        {
 
            x1 = c/(2*n);
            x2 = x1+1;
 
            f1 = x1*(c-x1*n);
            f2 = x2*(c-x2*n);
 
            ans = (f1>=f2?x1:x2);
 
        }
 
        printf("Case %d: %lld\n", caseno++, ans);
 
    }
 
    return 0;
}