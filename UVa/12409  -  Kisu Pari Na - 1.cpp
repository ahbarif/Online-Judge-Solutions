#include <bits/stdc++.h>
using namespace std;
 
int main()
{
 
        int test, cs = 1;
 
        scanf("%d", &test);
 
        while(test--)
        {
            long long x, y = 0;
 
            long long i, j, n, m;
 
            scanf("%lld %lld", &n, &m);
 
            for(i=1; i<=n; i++)
            {
                for(j=1; j<=m; j++)
                {
                    scanf("%lld", &x);
 
                    long long dis = n-i + m - j;
                   
                    if(dis%2!=0)    y^=x;
                }
            }
 
            if(y)   cout<<"Case "<<cs++<<": win\n";
           
            else cout<<"Case "<<cs++<<": lose\n";
 
           
        }
 
    return 0;
 
}
