#include<bits/stdc++.h>
using namespace std;
int a[2020];
 
inline bool verify(int n, int k, int cap)
{
        int i, cnt=1, res=0;
 
        for(i=0; i<=n; i++)
        {
            if(a[i]>cap)    return 0;
            res+=a[i];
            if(res>cap)     res=a[i], cnt++;
        }
 
        return cnt<=k+1;
}
 
int main()
{
 
        int n, k, test, caseno=0;
        vector<int> v;
 
        scanf("%d", &test);
 
        while(test--)
        {
 
                scanf("%d %d", &n, &k);
 
                for(int i=0; i<=n; i++) scanf("%d", &a[i]);
 
                int lo=1, mid, hi=100000000, ans;
 
                while(lo+1<hi)
                {
                        mid=(hi+lo)>>1;
                        if(verify(n, k, mid))
                        {
                            ans=mid;
                            hi=mid;
                        }
                        else lo=mid;
                }
 
                cout<<"Case "<<++caseno<<": "<<ans<<endl;
 
                for(int i=0; i<=n; i++) v.push_back(a[i]);
 
                int res=v.size();
                int p=0;
 
                while(res>k+1)
                {
                        if(v[p+1]+v[p]<=ans)
                        {
                            v[p]+=v[p+1];
                            res--;
                            v.erase(v.begin()+p+1);
                        }
 
                        else p++;
 
                }
 
                for(int i=0; i<v.size(); i++)     printf("%d\n", v[i]);
                v.clear();
        }
 
    return 0;
}