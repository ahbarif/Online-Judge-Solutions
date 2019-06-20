#include <bits/stdc++.h>
using namespace std;
 
long long a[100005], cnt[100005];
 
int main()
{
 
        int test, cs = 0;
 
        scanf("%d", &test);
 
        while(test--)
        {
            memset(cnt, 0, sizeof(cnt));
 
            long long n, m, res = 0;
 
            scanf("%lld %lld", &n, &m);
 
            for(int i = 1; i<=n; i++)
            {
                scanf("%lld", &a[i]);
                a[i] += a[i-1];
            }
 
            for(int i = 1; i<=n; i++)   a[i]%=m;
        //    puts("");
 
            for(int i = 1; i<=n; i++)
            {
                res = res + cnt[a[i]];
                cnt[a[i]]++;
            }
 
            for(int i = 1; i<=n; i++)   if(a[i]==0) res++;
 
            printf("Case %d: %lld\n", ++cs, res);
 
 
        }
 
 
}
