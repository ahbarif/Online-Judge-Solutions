#include<bits/stdc++.h>
using namespace std;
 
int main()
{
 
    int test, a[55], b[55], i, j, current, x, n, ans;
 
    scanf("%d", &test);
 
    for(x=1; x<=test; x++){
 
       scanf("%d", &n);
 
       for(i=0; i<n; i++)   scanf("%d", &a[i]);
       for(i=0; i<n; i++)   scanf("%d", &b[i]);
 
       sort(a, a+n);
       sort(b, b+n);
 
       ans=0;
 
       for(i=0; i<n; i++)
        {
            current=a[i];
            for(j=n-1; j>=0; j--)
            {
 
                if(b[j]<current && b[j]!=0)
                {
                    a[i]=0;
                    b[j]=0;
                    ans+=2;
                    break;
                }
            }
 
       }
 
       for(i=0; i<n; i++)
        {
            if(a[i]!=0)
            {
                for(j=0; j<n; j++)
                {
                    if(b[j]==a[i])
                    {
                        b[j]=0;
                        ans++;
                        break;
                    }
                }
            }
       }
 
       printf("Case %d: %d\n", x, ans);
 
    }
 
    return 0;
 
}