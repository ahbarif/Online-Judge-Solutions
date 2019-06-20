#include<bits/stdc++.h>
using namespace std;
 
typedef long long LL;
 
int n, ans = 0, m;
 
vector<int> Set;
int a[15];
 
void fun(int index)
{
    if (index > n)
    {
        ++ans;
        return;
    }
 
    for(int i = 0; i <m; i++)
    {
 
        if(abs(Set[i]-a[index-1])>2 && index!=1)    continue;
        a[index] = Set[i];
        fun(index+1);
 
    }
    return;
}
 
int main()
{
 
        int test, C;
 
        cin>>test;
 
        for(C=1; C<=test; C++)
        {
            ans = 0;
            Set.clear();
 
            cin>>m>>n;
 
            for(int i=0; i<m; i++)
            {
                int x;
                scanf("%d", &x);
                Set.push_back(x);
            }
 
            a[0] = 500;
            fun(1);
            cout<<"Case "<<C<<": "<<ans<<endl;
 
        }
 
        return 0;
 
}