#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int> > v;
vector<int> aa;

template<class T> inline T bigmod(T a, T b, T mod)
{
    T ans = 1;
    while(b)
    {
        if(b&1) ans = (ans*a)%mod;
        a = (a*a)%mod;
        b = b>>1;
    }
    return ans%mod;
}

long long n, m, res, k, block, mod = 1000000000LL;

set<int> vis;

void init()
{
    v.clear();

    res = 1LL;

    vis.clear();
}

void calc()
{

    for(int i = 0; i<aa.size()-1; i++)
    {
        int nxt = aa[i+1];
        int cur = aa[i];

        long long diff = nxt-cur-1;

        if(diff == 0)   continue;

        else
        {
            res = (res * k)%mod;

            long long temp = bigmod(k-1, diff-1, mod);

            res = (res * temp)%mod;
        }

    }

}

int main()
{
    int test, cs = 0;

    scanf("%d", &test);

    while(test--)
    {
        init();

        scanf("%lld %lld", &n, &m);

        scanf("%lld %lld", &k, &block);

        while(block--)
        {
            int x, y;

            scanf("%d %d", &x, &y);

            v.push_back(make_pair(y, x));

            vis.insert(y);
        }

        sort(v.begin(), v.end());

        int cur = 0, j;

        int sz = vis.size();

        long long emp = m - sz;

      //  cout<<emp<<endl;

        res = (res * k)%mod;

        long long temp = bigmod(k-1, n-1, mod);

        res = (res * temp)%mod;

        res = bigmod(res, emp, mod);

   //     res = (res * emp)%mod;


        for(set<int> ::iterator it = vis.begin(); it!= vis.end(); it++)
        {
            int i = *it;

            aa.clear();

            aa.push_back(0);

            for(j = cur; j<v.size(); j++)
            {
                if(v[j].first == i)
                {
                    aa.push_back(v[j].second);
                }
                else
                {
                    cur = j;
                    break;
                }

            }

            aa.push_back(n+1);

            calc();

        }

        printf("Case %d: %lld\n", ++cs, res);

    }

}
