#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 1000000007;

struct Matrix
{
    ll r, c, a[4][4];

    Matrix(){}

    Matrix(ll n, ll m)
    {
        r = n;
        c = m;
    }

    Matrix operator * (Matrix b)
    {
        Matrix res(r, b.c);

        for(int i=0; i<r; i++)
        {
            for(int j=0; j<b.c; j++)
            {
                ll temp = 0;

                for(int k=0; k<c; k++)
                {
                    temp = (temp + (a[i][k]*b.a[k][j]));
                    temp %= mod;
                }
                res.a[i][j] = temp;
            }
        }
        return res;
    }

    Matrix operator ^(ll n)
    {
        Matrix res(r, r);
        res.identity();
        Matrix p(r, c);
        for(int i = 0; i<r; i++)
            for(int j=0; j<c; j++)  p.a[i][j] = a[i][j];

        while(n)
        {
            if( n & 1 ) res = res * p;
            p = p * p;
            n >>= 1;
        }

        return res;
    }

    void identity()
    {
        memset(a, 0, sizeof(a));
        for(int i=0; i<4; i++) a[i][i] = 1;
    }

};

long long fibo[101];

void solve(){

    long long n, m, x, y, k;

    cin>>n>>x>>m>>y>>k;

    if(n>45 || m>45) {
        puts("Impossible");
        return;
    }

    long long a1 = fibo[n], b1 = fibo[n+1], c1 = -x;
    long long a2 = fibo[m], b2 = fibo[m+1], c2 = -y;

    long long d = a1*b2 - a2*b1;
    long long dx = b1*c2 - b2*c1;
    long long dy = a2*c1 - a1*c2;

    if(d == 0 || dx/d < 0 || dy/d <0 || dx%d || dy%d){
        puts("Impossible");
        return;
    }

    long long a = dx/d;
    long long b = dy/d;

    Matrix A(2, 2);
    A.a[0][0] = 1;
    A.a[0][1] = 1;
    A.a[1][0] = 1;
    A.a[1][1] = 0;

    Matrix B = A^k;

    long long ret = B.a[1][0] * a + B.a[0][0] * b;
    ret %= mod;

    cout<<ret<<endl;


//    long long


}

int main()
{
    fibo[0] = 0 ;
    fibo[1] = 1 ;
    for ( int i = 2 ; i < 58 ; i++ ) fibo[ i ] = fibo[ i - 1 ] + fibo[ i - 2 ];

   // freopen("in.txt", "r", stdin);

    int test, cs = 0;

    scanf("%d", &test);

    while(test--)
    {
        printf("Case %d: ", ++cs);
        solve();

    }

    return 0;
}



