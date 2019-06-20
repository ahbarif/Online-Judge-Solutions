#include<bits/stdc++.h>
using namespace std;
 
int main()
{
 
        long long a[105];
 
        int n, test, cs = 1, i, cnt;
 
        scanf("%d", &test);
 
        while(test--)
        {
 
            scanf("%d", &n);
 
            scanf("%lld", &a[0]);
 
            cnt = (a[0]==1);
 
            for(i=1; i<n; i++)
            {
                scanf("%lld", &a[i]);
 
                if(a[i]==1) cnt++;
 
                a[0] = a[0] ^ a[i];
            }
 
            printf("Case %d: ", cs++);
 
            if(cnt==n)  puts(n&1?"Bob":"Alice");
 
            else puts(a[0]?"Alice":"Bob");
 
        }
 
        return 0;
 
}