#include<bits/stdc++.h>
using namespace std;
const int N = 30005;
int a[N];
int tree[N*3];
map<string, int> mp;
int query(int node, int lo, int hi, int i, int j)
{
     if(i>hi || j<lo)    return 0;
     if(i<=lo && j>=hi)  return tree[node];
     int x = query(2*node, lo, (lo+hi)/2, i, j);
     int y = query(1 + 2*node, 1 + (lo+hi)/2, hi, i, j);
     return x+y;
}
void update(int node, int lo, int hi, int i, int val)
{
     if(i>hi || i<lo)    return;
     if(lo==hi)
    {
        tree[node] = val;
        return;
    }
     update(2*node, lo, (lo+hi)/2, i, val);
    update(1 + 2*node, 1 + (lo+hi)/2, hi, i, val);
     tree[node] = tree[2*node] + tree[1 + 2*node];
 }
int getInversionCount(int n)
{
    memset(tree, 0, sizeof(tree));
     int res = 0, mx = 0;
     for(int i = 0; i<n; i++) mx = max(mx, a[i]);
     for(int i = 0; i<n; i++) update(1, 0, mx, a[i], 1);
     for(int i = 0; i<n; i++)
    {
         res += query(1, 0, mx, 0, a[i]-1);
         update(1, 0, mx, a[i], 0);
     }
     return res;
 }
int main()
{
     vector<string> v;
     int test;
     cin>>test;
     while(test--)
    {
        int n;
         cin>>n;
         v.clear();
        mp.clear();
         int tmm = 1;
         for(int i = 0; i<n; i++)
        {
            string s;
            cin>>s;
            v.push_back(s);
        }
         for(int i = 0; i<n; i++)
        {
            string s;
            cin>>s;
            if(mp[s]==0) mp[s] = tmm++;
         }
         for(int i = 0; i<n; i++) a[i] = mp[v[i]];
         cout<<getInversionCount(n)<<endl;
     }
     return 0;
}
