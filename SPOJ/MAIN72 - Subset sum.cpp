#include<bits/stdc++.h>
using namespace std;
long long res = 0;
bool vis[105][100005];
bool b[100005];
int a[105], n;
void f(int pos, int sum)
{
    if(b[sum]==0 && sum<=100000)
        res+=sum;
    b[sum] = 1;
     if(pos>=n)  return;
     if(vis[pos][sum]==1)    return;
    vis[pos][sum] = 1;
     f(pos+1, sum);
    f(pos+1, sum+a[pos]);
    return;
}
int main()
{
    int i, t;
     ios_base::sync_with_stdio(false);
     cin>>t;
     while(t--)
    {
        cin>>n;
        for(i=0; i<n; i++)  cin>>a[i];
        memset(vis, 0, sizeof vis);
        memset(b, 0, sizeof b);
         f(0, 0);
         cout<<res<<endl;
        res = 0;
    }
    return 0;
}
