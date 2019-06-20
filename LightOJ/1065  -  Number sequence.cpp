#include <bits/stdc++.h>
using namespace std;

long long MOD = 1;

struct Matrix
{
    long long r, c, a[20][20];

    Matrix()
    {
        memset(a, 0,sizeof(a));
    }

    Matrix(long long n, long long m)
    {
        r = n;
        c = m;
        memset(a, 0,sizeof(a));
    }

    Matrix(long long n)
    {
        r = c = n;
        memset(a, 0, sizeof(a));
    }

    Matrix operator * (Matrix b)
    {
        Matrix res(r, b.c);

        for(int i=0; i<r; i++)
        {
            for(int j=0; j<b.c; j++)
            {
                long long temp = 0;

                for(int k=0; k<c; k++)
                {
                    temp = (temp + (a[i][k]*b.a[k][j]))%MOD;
                }
                res.a[i][j] = temp%MOD;
            }
        }
        return res;
    }

    Matrix operator ^(long long n)
    {
        Matrix res(r);
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
        for(int i=0; i<20; i++) a[i][i] = 1;
    }

};

int main()
{

        int test, cs = 0;

        scanf("%d", &test);

        while(test--)
        {

            long long c, d, n, m;

            scanf("%lld %lld %lld %lld", &c, &d, &n, &m);

            MOD = 1LL;

            while(m--)  MOD*=10;

            Matrix a(2LL);

            a.a[0][1] = 1;
            a.a[1][0] = 1;
            a.a[1][1] = 1;

            a = a^(n-1);


            Matrix b(2, 1);
            b.a[0][0] = c;
            b.a[1][0] = d;

            a = a*b;

            printf("Case %d: %lld\n", ++cs, a.a[1][0]);

        }



}

