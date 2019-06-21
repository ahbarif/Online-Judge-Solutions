#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

i64 mod;

struct Matrix
{
    i64 r, c, a[6][6];

    Matrix()
    {
        memset(a, 0,sizeof(a));
    }

    Matrix(i64 n, i64 m)
    {
        r = n;
        c = m;
        memset(a, 0,sizeof(a));
    }

    Matrix(i64 n)
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
                i64 temp = 0;

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
        for(int i=0; i<6; i++) a[i][i] = 1;
    }

};

int main()
{

    int test, cs = 0;

    scanf("%d", &test);
    Matrix a(6);
    Matrix b(6, 1);

    while(test--)
    {
        i64 n, q, a1, a2, b1, b2, c1, c2;
        i64 f0, f1, f2, g0, g1, g2;

        cin>>a1>>b1>>c1;
        cin>>a2>>b2>>c2;

        cin>>f0>>f1>>f2;
        cin>>g0>>g1>>g2;

        cin>>mod;

        cin>>q;
        printf("Case %d:\n", ++cs);

        while(q--)
        {

            memset(a.a, 0, sizeof(a.a));
            memset(b.a, 0, sizeof(b.a));

            cin>>n;

            if(n<=2){
                if(n==2) cout<<f2%mod<<" "<<g2%mod<<endl;
                if(n==1) cout<<f1%mod<<" "<<g1%mod<<endl;
                if(n==0) cout<<f0%mod<<" "<<g0%mod<<endl;
                continue;
            }

            b.a[0][0] = f2;
            b.a[1][0] = f1;
            b.a[2][0] = f0;
            b.a[3][0] = g2;
            b.a[4][0] = g1;
            b.a[5][0] = g0;

            a.a[0][0] = a1;
            a.a[0][1] = b1;
            a.a[0][5] = c1;

            a.a[1][0] = 1;
            a.a[2][1] = 1;
            a.a[4][3] = 1;
            a.a[5][4] = 1;

            a.a[3][2] = c2;
            a.a[3][3] = a2;
            a.a[3][4] = b2;


            Matrix p = a^(n-1);
            Matrix qq = p*b;

            i64 res1 = qq.a[1][0];
            i64 res2 = qq.a[4][0];

            cout<<res1<<" "<<res2<<endl;
            i64 res = qq.a[0][0];



        }







    }


    return 0;

}

