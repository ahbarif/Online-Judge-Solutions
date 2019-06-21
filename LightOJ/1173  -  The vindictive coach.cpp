#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long i64;

i64 dp[53][53][3];
bool vis[53][53][3];

i64 f(int choto, int boro, int type)
{
    if(choto == 0 && boro == 0) return 1;
    if(choto == 0 && type == 0) return 0;
    if(boro == 0 && type == 1) return 0;

    if(vis[choto][boro][type]) return dp[choto][boro][type];

    vis[choto][boro][type] = 1;

    i64 res = 0;

    if(type == 0)
    {

        for(int i = choto-1; i>=0; i--)
        {
            res = res + f(i, choto + boro - i - 1, type^1);
        }
    }

    else
    {

         for(int i = boro-1; i>=0; i--)
        {
            res = res + f(choto + boro - i - 1, i, type^1);

        }
    }

    return dp[choto][boro][type] = res;
}

int main()
{

    int test, cs = 0;

    cin>>test;

    while(test--)
    {

        int n,m;

        cin>>n>>m;

        memset(vis, 0, sizeof(vis));

        i64 res = 0;

        if(m==1)
        {
            res = f(1, n-3, 0);
        }

        else
        {
            res = f(m-1, n-m, 0);
        }

        if(res == 0) res = 1;

        cout<<"Case "<<++cs<<": "<<res<<endl;
    }
    return 0;
}

