#include<bits/stdc++.h>
using namespace std;
 
int main()
{
 
        vector<int> v, c;
 
        int a[100005], i, n, d, test, caseno=0, k;
 
        scanf("%d", &test);
 
        while(test--)
        {
 
                    int maxa=-1, mini=1e9, dif=-1;
 
                    scanf("%d %d", &n, &d);
 
                    for(i=0; i<n; i++)  scanf("%d", &a[i]);
 
                    for(i=0; i<d; i++)
                    {
                        if(a[i]>maxa)   maxa=a[i];
                        if(a[i]<mini)   mini=a[i];
                    }
 
                    c.push_back(mini);
                    v.push_back(maxa);
                    dif=abs(maxa-mini);
 
                    for(; i<n; i++)
                    {
                        if(a[i]>v[0]) v.clear(), v.push_back(a[i]);
 
                        else
                        {
                            while(v.size() && a[i]>=v.back())   v.pop_back();
                            v.push_back(a[i]);
                        }
 
                        if(v[0]==a[i-d]) v.erase(v.begin()+0);
                        if(v.size()==0) v.push_back(a[i]);
 
                        if(a[i]<c[0]) c.clear(), c.push_back(a[i]);
                        else
                        {
                          while(c.size() && c.back()>=a[i]) c.pop_back();
                          c.push_back(a[i]);
                        }
                        if(c[0]==a[i-d])  c.erase(c.begin()+0);
                        if(c.size()==0) c.push_back(a[i]);
 
                        k=v[0]-c[0];
                        if(k>dif)   dif=k;
 
                    }
 
                    printf("Case %d: %d\n", ++caseno, dif);
                    v.clear();
                    c.clear();
 
        }
 
        return 0;
}