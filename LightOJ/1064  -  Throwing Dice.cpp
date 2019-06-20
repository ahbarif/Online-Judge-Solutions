#include<bits/stdc++.h>
using namespace std;

typedef long long i64;
typedef pair<i64, i64> pii;

void print_fraction(pii a)
{
    if(a.second == 1) cout<<a.first<<endl;
    else if(a.first == 0)   cout<<0<<endl;
    else cout<<a.first<<"/"<<a.second<<endl;
}

pii simplify(pii a)
{
    if(a.first == 0 || a.second == 0)    return {0, 0};

    i64 gcd = __gcd(a.first, a.second);

    a.first /= gcd;
    a.second /= gcd;

    return a;
}

pii multiply(pii a, pii b)
{
    pii res = make_pair(a.first*b.first, a.second*b.second);

    return res;
}

i64 lcm(i64 a, i64 b)
{
    i64 g = __gcd(a, b);

    a /= g;

    return a*b;
}

pii Add(pii a, pii b)
{
    if(a.first == 0 && a.second == 0)   return b;
    if(b.first == 0 && b.second == 0)   return a;

    i64 hor = lcm(a.second, b.second);

    i64 lob = (hor/a.second)*a.first + (hor/b.second)*b.first;

    pii res = make_pair(lob, hor);

    return simplify(res);
}

pii dp[30][160];
bool vis[30][160];

pii f(int n, int sum)
{
    if(n==0)
    {
        if(sum<=0)  return make_pair(1, 1);
        else return make_pair(0, 0);
    }

    if(sum<=0)  return make_pair(1, 1);

    if(vis[n][sum]) return dp[n][sum];

    vis[n][sum] = true;

    pii res = make_pair(0, 0);

    for(int i = 1; i<=6; i++)
    {
        pii probability = make_pair(1, 6);

        pii rem = f(n-1, sum-i);

        pii tmp = multiply(probability, rem);

        res = Add(res, tmp);

    }

    return dp[n][sum] = simplify(res);
}

int main()
{

    int test, cs = 0;

    scanf("%d", &test);

    while(test--)
    {

        int n, sum;

        memset(vis, 0, sizeof(vis));

        scanf("%d %d", &n, &sum);

        pii res = f(n, sum);

        printf("Case %d: ", ++cs);

        print_fraction(res);
    }

}
