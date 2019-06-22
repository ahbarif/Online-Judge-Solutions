#include <bits/stdc++.h>
using namespace std;

int mod = 10007;

struct Matrix
{
    int r, c, a[5][5];

    Matrix()
    {
        memset(a, 0,sizeof(a));
    }

    Matrix(int n, int m)
    {
        r = n;
        c = m;
        memset(a, 0,sizeof(a));
    }

    Matrix(int n)
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
                int temp = 0;

                for(int k=0; k<c; k++)
                {
                    int val = (a[i][k]%mod) * (b.a[k][j])%mod;
                    temp += val;
                    temp %= mod;
                }
                res.a[i][j] = temp;
            }
        }
        return res;
    }

    Matrix operator ^(int n)
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
        for(int i=0; i<5; i++) a[i][i] = 1;
    }

};

int main()
{

    int test, cs = 0;

    scanf("%d", &test);

    while(test--)
    {
        int n;

        cin>>n;

        Matrix a(3);

        a.a[0][0] = 2;
        a.a[0][2] = 1;
        a.a[1][0] = 1;
        a.a[2][1] = 1;

        int res = 0;

        //  a = a^(n-1);

        Matrix p = a^(n-1);

        Matrix b(3, 1);
        b.a[0][0] = 5;
        b.a[1][0] = 2;
        b.a[2][0] = 1;

        Matrix c = p*b;

        res = c.a[2][0];

        printf("Case %d: %lld\n", ++cs, res);



    }


    return 0;

}

