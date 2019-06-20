#include<bits/stdc++.h>
using namespace std;
 
int main()
{
 
        vector<long long> v;
 
        int test, i, j, cs = 1, n, m, count;
 
        long long a[55][55];
 
        scanf("%d", &test);
 
        while(test--)
        {
                count = 0;
                v.clear();
 
                scanf("%d %d", &n, &m);
 
                for(i=0; i<n; i++)
                {
                    long long sum = 0;
 
                    for(j=0; j<m; j++)
                    {
                        scanf("%lld", &a[i][j]);
                        sum+=a[i][j];
                    }
                    v.push_back(sum);
                }
 
 
                for(i=0; i<v.size(); i++)
                {
                    if(v[i]==1) count++;
 
                    if(i)   v[0]^=v[i];
                }
 
                printf("Case %d: ", cs++);
 
                if(count==n) puts(count&1?"Alice":"Bob");
 
                else puts(!v[0]?"Bob":"Alice");
 
        }
 
        return 0;
 
}
 