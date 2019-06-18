#include<bits/stdc++.h>
using namespace std;
int bigmod(int a, int b, int mod)
{
    int ans = 1;
    while(b)
    {
        if(b&1) ans = (ans*a)%mod;
        a = (a*a)%mod;
        b = b>>1;
    }
    return ans%mod;
}
int solve(int ret)
{
    int n = ret, sz = 0;
    while(n){
        sz++;
        n/=10;
    }
    int po = bigmod(10, sz, 100000000);
     for(int i = 1; i<=10000; i++){
        int k = i*ret;
        if(k%po == 0) return i;
    }
}
int main()
{
     int t;
     cin>>t;
     while(t--)
    {
        string s;
        cin>>s;
        int pos = -1;
         for(int i = 0; i<s.size(); i++)
        {
            if(s[i]=='.')
            {
                pos = i;
                break;
            }
        }
         if(pos==-1) puts("1");
          else
        {
            int ret = 0;
             for(int i = pos+1; i<s.size(); i++)
            {
                ret = ret * 10 + (s[i]-'0');
            }
             cout<<solve(ret)<<endl;
        }
     }
