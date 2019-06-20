#include<bits/stdc++.h>
using namespace std;
int a[1010];
 
int container(int n, int cap)
{
        int ans=1, res=0;
 
        for(int i=0; i<n; i++)
        {
            res+=a[i];
            if(res>cap)
            {
                ++ans;
                res=a[i];
            }
        }
 
    return ans;
}
 
int main()
{
 
        int test, caseno=1;
 
        scanf("%d", &test);
 
        while(test--)
        {
                int n, m, i, mini=-1, lo, hi, x, sum=0, ans;
 
                scanf("%d %d", &n, &m);
 
                for(i=0; i<n; i++)
                {
                     scanf("%d", &a[i]);
                     mini=max(mini, a[i]);
                     sum+=a[i];
                }
 
                 lo=mini;
                 hi=sum;
 
                 while(lo<=hi)
                 {
 
                        int mid=(hi+lo)>>1;
 
                        x=container(n, mid);
 
                        if(x<=m)
                        {
                            ans=mid;
                            hi=mid-1;
                        }
 
                        else  lo=mid+1;
 
                 }
 
                 cout<<"Case "<<caseno++<<": "<<ans<<endl;
        }
 
    return 0;
}