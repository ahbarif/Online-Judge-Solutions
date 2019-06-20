#include<bits/stdc++.h>
using namespace std;
 
vector<int> a;
map<int, int> mp;
 
int main()
{
 
    int test, caseno = 1;
 
    scanf("%d", &test);
 
    while(test--)
    {
        int n, x, res = 0;
        a.clear();
        mp.clear();
 
        scanf("%d", &n);
 
        while(n--)
        {
            int flag = 0;
            scanf("%d", &x);
            for(int i=0; i<a.size(); i++)
            {
                if(a[i]==x+1 && a[i]>mp[i])
                {
                    mp[i]++;
                    flag = 1;
                    break;
                }
            }
            if(flag) continue;
            a.push_back(x+1);
            mp[a.size()-1]++;
        }
 
        for(int i=0; i<a.size(); i++)  res+=a[i];
 
        printf("Case %d: %d\n", caseno++, res);
 
    }
    return 0;
}
 