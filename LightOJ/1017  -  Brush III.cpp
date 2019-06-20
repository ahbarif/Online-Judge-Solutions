#include<bits/stdc++.h>
using namespace std;

struct point{

    int x, y;

    point(){}

    point(int _x, int _y)
    {
        x = _x;
        y = _y;
    }

}a[20];

int dp[101][101][101];

vector<pair<int, int> > v;

int sz, w;

bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.second<b.second;
}

int f(int i, int k, int done)
{
//    cout<<i<<" "<<k<<" "<<done<<endl;

    if(k<=0 || i>=sz)   return done;


    if(dp[i][k][done]!=-1)  return dp[i][k][done];

    int cnt = 0;

    int last = v[i].second + w;


    int c;

    for(c = i; c<sz; c++)
    {
        if(v[c].second<=last) cnt++;
        else break;
    }
//    cout<<"debug: "<<i<<" - > "<<last<<" "<<cnt<<endl;

    int res1 = 0, res2 = 0;

    res1 = f(c, k-1, done+cnt);

    res2 = f(i+1, k, done);

    return dp[i][k][done] = max(res1, res2);


}

int main()
{

    int test, cs = 0;

    scanf("%d", &test);

    while(test--)
    {
        memset(dp, -1, sizeof(dp));

        int n, k, i, x, y;

        scanf("%d %d %d", &n, &w, &k);

        v.clear();

        for(i=0; i<n; i++)
        {
            scanf("%d %d", &x, &y);
            v.push_back(make_pair(x, y));

        }

        sz = v.size();

        sort(v.begin(), v.end(), compare);

        int res = f(0, k, 0);

        printf("Case %d: %d\n", ++cs, res);

    }


    return 0;

}
