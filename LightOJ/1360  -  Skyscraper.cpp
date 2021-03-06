#include<bits/stdc++.h>
using namespace std;

const int maxn = 30015;

struct data{
    int st, en, profit;
    data(){}

    data(int st, int en, int profit):st(st), en(en), profit(profit){}

    bool operator<(const data &p)const{
        if(st == p.st) return en<p.en;
        return st<p.st;
    }
}a[maxn];

int points[maxn], dp[maxn], n;

int f(int pos){

    if(pos>=n) return 0;

    if(dp[pos] != -1) return dp[pos];

    int ret = 0;

    // case 1: don't take

    ret = max(ret, f(pos+1));

    // case 2: nibo

    int profit = a[pos].profit;

    int nxt = upper_bound(points, points+n, a[pos].en) - points;

    ret = max(ret, profit + f(nxt));

    return dp[pos] = ret;
}

int main()
{

   // freopen("in.txt", "r", stdin);

    int test, cs = 0;

    scanf("%d", &test);

    while(test--)
    {

        scanf("%d", &n);

        for(int i = 0; i<n; i++){
            int x, y, z;
            scanf("%d %d %d", &x, &y, &z);
            a[i].st = x;
            a[i].en = x + y - 1;
            a[i].profit = z;
            points[i] = x;
        }

        sort(points, points+n);
        sort(a, a+n);

        memset(dp, -1, sizeof(dp));

        int ret = f(0);

        printf("Case %d: %d\n", ++cs, ret);


    }
    return 0;
}

