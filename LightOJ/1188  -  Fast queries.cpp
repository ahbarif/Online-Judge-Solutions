#include<bits/stdc++.h>
using namespace std;

int a[100005];

int tree[100005];

int update(int pos,int limit,int x)
{

    while(pos<=limit)
    {
        tree[pos]+=x;
        pos+=(pos)&(-pos);

    }
}
int query(int pos)
{

    int sum = 0;
    while(pos>0)
    {
        sum+=tree[pos];
        pos-=(pos)&(-pos);
    }
    return sum;
}

typedef pair<int, int> pii;

vector<pair<pii,int> > v;

vector<int> que[100005];
int ans [100005];

int main()
{

#ifdef local
    freopen("in.txt", "r", stdin);
#endif // local


    int test, cs = 0;

    scanf("%d", &test);

    while(test--)
    {

        v.clear();

        for(int i = 0; i<=100000; i++)
        {
            que[i].clear();
        }

        int n, q;

        scanf("%d %d", &n, &q);


        for(int i = 1; i<=n; i++)
        {

            scanf("%d", &a[i]);
            que[a[i]].push_back(i);
        }

        for(int i = 0; i<=100000; i++) reverse(que[i].begin(), que[i].end());

        for(int i = 0; i<=100000; i++)
        {
            if(!que[i].empty())
            {

                int f = que[i].back();
                que[i].pop_back();

                update(f, n, 1);

            }
        }


        printf("Case %d:\n", ++cs);



        for(int i= 0;i<q;i++)
        {

            int x, y;

            scanf("%d %d", &x, &y);


            v.push_back(make_pair(make_pair(x, y),i));
        }

        sort(v.begin(), v.end());

        int lo = 1;

        for(int i = 0; i<v.size(); i++)
        {



            while(lo<v[i].first.first)
            {

                if(!que[a[lo]].empty())
                {
                    int f = que[a[lo]].back();
                      //cout<<"f= "<<f<<endl;
                    que[a[lo]].pop_back();

                    update(f, n, 1);
                }

                lo++;
            }

            int res = query(v[i].first.second) - query(v[i].first.first-1);

            ans[v[i].second] = res;

        }
        for(int i = 0;i<q;i++) printf("%d\n",ans[i]);
            memset(tree, 0, sizeof(tree));

    }

    return 0;


}

