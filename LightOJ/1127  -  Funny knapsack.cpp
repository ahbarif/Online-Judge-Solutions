#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> v1, v2, s1, s2;

long long cap;

void subset_sum(vector<ll> v, int flag)
{
        int sz = v.size();

        for(int i = 0; i<(1<<sz); i++)
        {
            ll sum = 0;
            for(int j=0; j<sz; j++)
            {
                if((bool)(i&(1<<j)))    sum+=v[j];
            }

            if(flag) s1.push_back(sum);
            else     s2.push_back(sum);
        }
}

int main()
{

        int test, cs = 0;

        scanf("%d", &test);

        while(test--)
        {
                ll n, i, ans = 0;

                scanf("%lld %lld", &n, &cap);

                for(i=1; i<=n/2; i++)
                {
                    ll x;
                    scanf("%lld", &x);
                    v1.push_back(x);
                }

                for(i=n/2 + 1; i<=n; i++)
                {
                    ll x;
                    scanf("%lld", &x);
                    v2.push_back(x);
                }

                subset_sum(v1, 1);
                subset_sum(v2, 0);

                sort(s2.begin(), s2.end());

                for(i = 0; i<s1.size(); i++)
                {
                    ll k = cap - s1[i];

                    if(k<0) continue;

                    ll p = upper_bound(s2.begin(), s2.end(), k) - s2.begin();

                    ans+=p;
                }

               printf("Case %d: %lld\n", ++cs, ans);

               v2.clear(); v1.clear(); s1.clear(); s2.clear();

        }

        return 0;
}
