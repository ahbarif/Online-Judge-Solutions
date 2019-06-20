#include<bits/stdc++.h>
using namespace std;

const int maxn = 505;

int sparse[maxn][maxn][12];
int b[maxn][maxn], Logs[maxn];


void build_table(int row, int n)
{

    for (int i = 1; i <= n; i++) sparse[row][i][0] = i;

    for (int j=1; (1<<j)<=n; j++)
    {
        for (int i=1; (i+(1<<j)-1) <= n; i++)
        {
            if (b[row][sparse[row][i][j-1]] >= b[row][sparse[row][i + (1<<(j-1))][j-1]]){

                sparse[row][i][j] = sparse[row][i][j-1];
            }
            else{

                sparse[row][i][j] = sparse[row][i + (1 << (j-1))][j-1];
            }
        }
    }

}

int RangeQuery(int row, int L, int R)
{

    if(L>R) return 0;

    int j = Logs[R-L+1];

    if (b[row][sparse[row][L][j]] > b[row][sparse[row][R - (1<<j) + 1][j]]){

        return b[row][sparse[row][L][j]];
    }

   else return b[row][sparse[row][R - (1<<j) + 1][j]];

}

int Query(int I, int J, int S){

    int L = J;
    int R = J + S - 1;

    int mx = 0;

    for(int i_ = I; i_<=(I+S-1); i_++){
        int x = RangeQuery(i_, L, R);
        if(x>mx) mx = x;

    }

    return mx;

}

void sparse_init(int from, int to, int n){

    memset(sparse, 0, sizeof(sparse));

    for(int i = from; i<=to; i++){
        build_table(i, n);
    }
}



void solve(int cs)
{

        int n, q;

        scanf("%d %d", &n, &q);

        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=n; j++){
                scanf("%d", &b[i][j]);
            }
        }

        sparse_init(1, n, n);

        printf("Case %d:\n", cs);

        while(q--){

            int i, j, s;

            scanf("%d %d %d", &i, &j, &s);

            printf("%d\n", Query(i, j, s));
        }



}

int main ()
{

    for(int i = 1; i<maxn; i++){
        Logs[i] = (int)log2(i);
    }


  //  freopen("in.txt", "r", stdin);

    int test, cs = 0;

    scanf("%d", &test);

    while(test--){

        solve(++cs);

    }


    return 0;
}

