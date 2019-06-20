#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll w[1005], panda[1005];
ll mod = 1000000007;

int main()
{
    int test, cs = 0;

    scanf("%d", &test);

    while (test--)
    {

        ll n, i, j=0, ans = 1, done = 0, cap = 0;

        scanf("%lld", &n);

        for(i=0; i<n; i++)  scanf("%lld", &w[i]);
        for(i=0; i<n; i++)  scanf("%lld", &panda[i]);

        sort(w, w+n);
        sort(panda, panda+n);

        for(i=0; i<n; i++)
        {
            while(j<n)
            {
                if(w[j]<=panda[i])
                {
                    cap++;
                    j++;

                }
                else break;
            }

            ll x = cap-done;

            ans = (ans * x)%mod;

            done++;
        }


        printf("Case %d: %lld\n", ++cs, ans);
    }
    return 0;
}


