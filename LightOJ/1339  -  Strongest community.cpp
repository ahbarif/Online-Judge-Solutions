#include<bits/stdc++.h>
using namespace std;

const int maxn = 100005;

int freq[maxn], sparse[maxn][20];
int a[maxn], b[maxn];

void init()
{
    memset(freq, 0, sizeof(freq));

}

void build_table(int n)
{
    memset(sparse, 0, sizeof(sparse));

    for (int i = 1; i <= n; i++) sparse[i][0] = i;

    for (int j=1; (1<<j)<=n; j++)
    {
        for (int i=1; (i+(1<<j)-1) <= n; i++)
        {
            if (b[sparse[i][j-1]] >= b[sparse[i + (1<<(j-1))][j-1]]){

                sparse[i][j] = sparse[i][j-1];
            }
            else{

                sparse[i][j] = sparse[i + (1 << (j-1))][j-1];
            }
        }
    }

}

int RangeQuery(int L, int R)
{

    if(L>R) return 0;

    int j = (int)log2(R-L+1);

    if (b[sparse[L][j]] > b[sparse[R - (1<<j) + 1][j]]){

        return b[sparse[L][j]];
    }

   else return b[sparse[R - (1<<j) + 1][j]];

}

int find_right(int idx, int n)
{
    int lo = idx, hi = n+1, val = a[idx], mid;
    a[n+1] = -1;
    while(lo<hi){
        mid = (lo+hi)/2;

        if(a[mid] != val){
            hi = mid;
        }
        else lo = mid+1;
    }

    return lo;

}

int find_left(int idx, int n){

    int lo = 1, hi = idx, val = a[idx], mid;
    a[0] = -1;
    while(lo<hi){
        mid = (lo+hi)/2;

        if(a[mid] != val){
            lo = mid+1;
        }
        else hi = mid;
    }

    return lo;


}



void solve(int cs)
{


    init();

    int n, q, c;

    scanf("%d %d %d", &n, &c, &q);

    for(int i = 1; i<=n; i++)
    {
        scanf("%d", &a[i]);
        freq[a[i]]++;
    }

    for(int i = 1; i<=n; i++)
    {
        b[i] = freq[a[i]];
    }

    build_table(n);

    printf("Case %d:\n", cs);

    while(q--){

        int x, y, res = 0;

        scanf("%d %d", &x, &y);

        if(a[x] == a[y]){
            res = y-x+1;
        }

        else{


            int L = find_left(y, n)-1;
            int R = find_right(x, n);



            int xx = RangeQuery(R, L);
            int yy = R - x;
            int zz = y - L;

            res = max(xx, max(yy, zz));
        }

        printf("%d\n", res);

    }




}

int main ()
{

  //  freopen("in.txt", "r", stdin);

    int test, cs = 0;

    scanf("%d", &test);

    while(test--){

        solve(++cs);

    }


    return 0;
}

