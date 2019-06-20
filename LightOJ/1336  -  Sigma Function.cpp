#include <bits/stdc++.h>
using namespace std;
 
int main()
{
        long long ans, n, a, b;
 
        int test, i;
 
        scanf("%d", &test);
 
        for(i=1; i<=test; i++)
        {
            scanf("%lld", &n);
 
            a = sqrt(n);
            b = sqrt(n/2);
 
            ans = n-a-b;
 
            printf("Case %d: %lld\n", i, ans);
        }
}
 