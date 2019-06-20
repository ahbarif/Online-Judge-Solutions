#include<bits/stdc++.h>
using namespace std;

int a[2000005];

set<int> st;
vector<int> v;
map<int, int> mp;
vector<pair<int, int> > lines;

int main()
{
    int test, cs = 0;

    scanf("%d", &test);

    while(test--)
    {
        int n, query, q, res, mapping = 1, i, x, y;

        memset(a, 0, sizeof(a));
        mp.clear();
        st.clear();
        v.clear();
        lines.clear();

        scanf("%d %d", &n, &query);

        for(i=0; i<n; i++)
        {
            scanf("%d %d", &x, &y);
            if(x>y)swap(x, y);
            lines.push_back(make_pair(x, y));

            st.insert(x);
            st.insert(y);
        }

        for(i=0; i<query; i++)
        {
            scanf("%d", &q);
            v.push_back(q);
            st.insert(q);
        }

        for(set<int> ::iterator it = st.begin(); it!=st.end(); it++)
        {
            if(mp[*it]==0)  mp[*it] = mapping++;
        }

        for(i=0; i<n; i++)
        {
            a[mp[lines[i].first]]++;
            a[mp[lines[i].second]+1]--;
        }

        for(i=1; i<=mapping; i++)   a[i]+= a[i-1];

        printf("Case %d:\n", ++cs);

        for(i=0; i<query; i++)
        {
            printf("%d\n", a[mp[v[i]]]);
        }
    }

    return 0;

}

