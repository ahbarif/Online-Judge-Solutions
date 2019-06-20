#include<bits/stdc++.h>
using namespace std;
 
typedef long long Long;
 
vector<Long> a;
 
int main(){
 
        Long test, caseno=0, i, ans=0, range, x, y, width, n;
 
        scanf("%lld", &test);
 
        while(test--)
        {
                range=-1e15;
                ans=0;
 
                scanf("%lld %lld", &n, &width);
 
                while(n--)
                {
                    scanf("%lld %lld", &x, &y);
                    a.push_back(y);
                }
 
                sort(a.begin(), a.end());
 
                for(i=0; i<a.size(); i++)
                {
                    x=a[i];
                    if(x>range)
                    {
                        ++ans;
                        range=x+width;
                    }
                    else continue;
                }
 
                printf("Case %lld: %lld\n", ++caseno, ans);
 
                a.clear();
 
        }
 
    return 0;
}