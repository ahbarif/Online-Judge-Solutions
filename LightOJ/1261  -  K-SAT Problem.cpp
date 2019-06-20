# include<bits/stdc++.h>
using namespace std;
 
int solve()
{
 
    int taken[50]={0}, happy[50]={0}, i, j, x;
 
    int n, m, p, k;
 
    vector<int> a[50];
 
    scanf("%d %d %d", &n, &m, &k);
 
    for(i=1; i<=n; i++)
    {
        for(j=0; j<k; j++)
        {
            scanf("%d", &x);
            a[i].push_back(x);
        }
    }
    scanf("%d", &p);
 
    while(p--)
    {
        scanf("%d", &x);
        taken[x]=1;
    }
 
    for(i=1; i<=n; i++)
    {
            for(j=0; j<a[i].size(); j++)
            {
                p=a[i][j];
           
                if(p>0)
                {
                    if(taken[p]) happy[i]=1;
                }
                else
                {
                    p=-p;
                    if(!taken[p]) happy[i]=1;
                }
   
            }
 
    }
 
    for(i=1; i<=n; i++)
    {
      if(!happy[i]) return 0;
    }
    return 1;
 
 
}
 
int main()
{
    int test, caseno=0, p;
 
    scanf("%d", &test);
   
    while(test--)
    {
 
            p=solve();
            printf("Case %d: ", ++caseno);
            puts(p?"Yes":"No");
    }
 
 
   return 0;
}