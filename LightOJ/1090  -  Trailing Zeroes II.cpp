#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

vector<long long> fi, tw;

LL twos(LL x)
{
    LL ans=0, k, i=0;

    while(1)
    {
        if(tw[i]>x)  break;
        k=x/tw[i];
        ans+=k;
        i++;
    }
    return ans;
}

LL fives(LL x)
{
    LL ans=0, k, i=0;

    while(1)
    {
        if(fi[i]>x)  break;
        k=x/fi[i];
        ans+=k;
        i++;
    }
    return ans;
}

LL calc(LL n, LL x)
{
    LL c = 0;
    while(n % x == 0)
    {
        c++;
        n/= x;
    }
    return c;
}

int main()
{

        LL x=1;
        for(int i=0; i<20; i++) x*=5, fi.push_back(x);

        x=1;
        for(int i=0; i<32; i++) x*=2, tw.push_back(x);

        int test, caseno=0;

        cin>>test;

        while(test--)
        {
                LL i, j, k, l, m, n, r, p, q, y, a, b;

                cin>>a>>b>>p>>q;

                i=twos(a);
                j=fives(a);

                k=twos(b);
                l=fives(b);

                m=twos(a-b);
                n=fives(a-b);

                x=calc(p, 2);
                y=calc(p, 5);

                x*=q;
                y*=q;

                a=i - k - m + x;
                b=j - l - n + y;

                cout<<"Case "<<++caseno<<": "<<min(a, b)<<endl;

        }
    return 0;
}
