#include<bits/stdc++.h>
using namespace std;

vector<int> d;
const int maxn = 100005;
int a[maxn], prefix[maxn], suffix[maxn];

void init()
{

    memset(prefix, 0, sizeof(prefix));
    memset(suffix, 0, sizeof(suffix));
}

int main()
{

    int test, cs = 0;

    scanf("%d", &test);

    while(test--)
    {
        init();

        int n;

        scanf("%d", &n);

        for(int i = 1; i<=n; i++) scanf("%d", &a[i]);

        d.clear();

        for(int i = 1; i<=n; i++)
        {
            int x = a[i];
            vector<int>::iterator it = lower_bound(d.begin(), d.end(), x);
            if (it == d.end()) d.push_back(x);
            else *it = x;
            int sz = d.size();
            prefix[i] = max(prefix[i], sz);

        }

        d.clear();

        for(int i = n; i>0; i--)
        {

            int x = a[i];
            vector<int>::iterator it = lower_bound(d.begin(), d.end(), x);
            if (it == d.end()) d.push_back(x);
            else *it = x;
            int sz = d.size();
            suffix[i] = max(suffix[i], sz);
        }

        int res = 0;

        for(int i = 1; i<=n; i++)
        {
            int tmp = min(suffix[i], prefix[i]);
            res = max(res, 2*tmp-1);

        }

        printf("Case %d: %d\n", ++cs, res);

    }

    return 0;
}

