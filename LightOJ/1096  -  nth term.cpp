#include <bits/stdc++.h>
using namespace std;

long long MOD = 10007LL;

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

    void print()
    {
        for(int i = 0; i<r; i++)
        {
            for(int j = 0; j<c; j++)    cout<<a[i][j]<<" ";
            puts("");
        }
    }
};

int main()
{

    int test, cs = 0;

    scanf("%d", &test);

    while(test--)
    {
        long long n, a, b, c;

        scanf("%lld %lld %lld %lld", &n, &a, &b, &c);

        Matrix Function(4, 4);

        Function.a[0][0] = a;
        Function.a[0][2] = b;
        Function.a[0][3] = c;
        Function.a[1][0] = 1;
        Function.a[2][1] = 1;
        Function.a[3][3] = 1;

        Function = Function^n;

        Matrix base(4, 1);
        base.a[0][0] = 0;
        base.a[1][0] = 0;
        base.a[2][0] = 0;
        base.a[3][0] = 1;

        Function= Function*base;

        printf("Case %d: %lld\n", ++cs, Function.a[2][0]);


   //     base.print();

    }



}

