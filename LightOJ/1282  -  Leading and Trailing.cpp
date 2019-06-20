#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

LL bigmod(LL a, LL b, LL m)
{
        if(b==0)    return 1;

        return b%2?((a%m)*bigmod(a, b-1, m))%m:(((bigmod(a, b/2, m))%m)*((bigmod(a, b/2, m))%m))%m;

}

void leading(int a, int b)
{
        LL c;
        long double d, k;

        d=b*log10(a);
        c=d;
        d-=c;
        k=pow(10, d);
        k*=10000;
        c=k;
        LL s=0, x;
        while(c)
        {
            x=c%10;
            s=s*10+x;
            c/=10;
        }

        cout<<(s%10)<<(s/10)%10<<(s/100)%10<<" ";

}

int main()
{

        int t, i;
        LL ans, a, b;
        cin>>t;
        for(i=1; i<=t; i++)
        {

            cin>>a>>b;

            cout<<"Case "<<i<<": ";

            leading(a, b);

            ans=bigmod(a, b, 1000LL);

            printf("%03lld\n", ans);

        }
        return 0;
}
