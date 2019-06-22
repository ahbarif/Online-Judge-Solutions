#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
map<pii, int> mp;

pii a[705];

pii f(int i, int j){

    int xDiff = a[i].first - a[j].first;
    int yDiff = a[i].second - a[j].second;

    if (xDiff > 0 && yDiff < 0)
    {
        xDiff *= -1;
        yDiff *= -1;
    }
    else if (xDiff < 0 && yDiff < 0)
    {
        xDiff *= -1;
        yDiff *= -1;
    }
    else if (xDiff == 0)
    {

        yDiff = 1;
    }
    else if (yDiff == 0)
    {

        xDiff = 1;
    }

    int gcd = __gcd(abs(xDiff), abs(yDiff));

    pii slope = make_pair(xDiff / gcd, yDiff / gcd);

    return slope;
}

void solve(int cs){

    int n;

    scanf("%d", &n);

    for(int i = 0; i<n; i++) scanf("%d %d", &a[i].first, &a[i].second);

    int res = 0;

    for(int i = 0; i<n; i++){
        mp.clear();

        for(int j = 0; j<n; j++){
            if(i==j) continue;
            
            pii slope = f(i, j);

            mp[slope]++;

            int cnt = mp[slope];

            if(cnt>res) res = cnt;

        }

    }

    printf("Case %d: %d\n", cs, 1+res);


}

int main()
{

   // freopen("in.txt", "r", stdin);

    int test, cs = 0;

    scanf("%d", &test);

    while (test--)
    {

        solve(++cs);
    }

    return 0;
}
