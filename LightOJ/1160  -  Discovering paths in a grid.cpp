#include<bits/stdc++.h>
using namespace std;

typedef long long i64;
long long mod = 1000000007;

struct Matrix
{
    i64 r, c, a[40][40];

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
                    temp = (temp + (a[i][k]*b.a[k][j]));
                    temp %= mod;
                }
                res.a[i][j] = temp;
            }
        }
        return res;
    }

    Matrix operator ^(i64 n)
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
        for(int i=0; i<35; i++) a[i][i] = 1;
    }

};
int mp[1024];
int adj[35][35];

void foo(int mask)
{
    vector<int> v[5];
    int j = 0;
    for(int i = 0; i<7; i++)
    {
        if((mask&(1<<i)))
        {
            if(i<6) v[j].push_back(i+1);
            if(i>0) v[j].push_back(i-1);
            j++;
        }
    }

    set<int> st;

    for(int i = 0; i<v[0].size(); i++)
    {
        for(int j = 0; j<v[1].size(); j++)
        {
            for(int k = 0; k<v[2].size(); k++)
            {
                for(int l = 0; l<v[3].size(); l++)
                {
                    st.clear();
                    st.insert(v[0][i]);
                    st.insert(v[1][j]);
                    st.insert(v[2][k]);
                    st.insert(v[3][l]);
                    if(st.size()==4)
                    {

                        int subMask = 0;
                        subMask |= (1<<v[0][i]);
                        subMask |= (1<<v[1][j]);
                        subMask |= (1<<v[2][k]);
                        subMask |= (1<<v[3][l]);

                        adj[mp[mask]][mp[subMask]] = 1;
                    }
                }
            }
        }
    }
}


int preprocess()
{

    vector<int> states;
    memset(mp, -1, sizeof(mp));
    int cnt = 0;
    for(int i = 0; i<(1<<7); i++)
    {
        if(__builtin_popcount(i)==4)
        {
            mp[i] = cnt++;
            states.push_back(i);
        }
    }

    for(int i = 0; i<states.size(); i++) foo(states[i]);




}
int main()
{

  //  freopen("in.txt", "r", stdin);

    preprocess();

    Matrix A(35, 35);

    for(int i = 0; i<35; i++)
    {
        for(int j = 0; j<35; j++)
        {
            A.a[i][j] = adj[i][j];
        }
    }

    int test, cs = 0;

    for(scanf("%d",&test); test; test--)
    {

        long long n;
        scanf("%lld", &n);
        Matrix B = A^(n-1);
        int mask = 0;
        for(int i = 0; i<7; i++)
        {
            int x;
            scanf("%d", &x);
            if(x) mask |= (1<<i);
        }

        int id = mp[mask];

        long long ans = 0;

        for(int i =0; i<35; i++)
        {
            ans += B.a[i][id];
            ans %= mod;
        }
        printf("Case %d: %lld\n", ++cs, ans);

    }

    return 0;
}

