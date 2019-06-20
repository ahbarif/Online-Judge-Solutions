#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
 
int main()
{
 
            LL test, caseno=0;
            LL a[2020], x, n, i, j, ans;
 
            scanf("%lld", &test);
 
            while(test--)
            {
                    ans=0;
                    scanf("%lld", &n);
 
                    for(i=0; i<n; i++)  scanf("%lld", &a[i]);
 
                    sort(a, a+n);
 
                    for(i=0; i<n-2; i++)
                    {
                        for(j=i+1; j<n-1; j++)
                        {
                            LL s = a[i]+a[j];
                            x = lower_bound(a, a+n, s)-a;
                            ans+=(x-1-j);
                        }
                    }
 
                    printf("Case %lld: %lld\n", ++caseno, ans);
 
            }
 
    return 0;
}
 