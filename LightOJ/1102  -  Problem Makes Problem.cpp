# include<bits/stdc++.h>

// n+k-1 C k-1

typedef long long LL;

using namespace std;

template<class T> inline T bigmod(T a, T b, T mod)
{
    T ans = 1;
    while(b)
    {
        if(b&1) ans = (ans*a)%mod;
        a = (a*a)%mod;
        b = b>>1;
    }
    return ans%mod;
}

int ff[2000006];


int main(){

    LL n, r, b, a, ans, test, i, c, M=1000000007;
    ff[0]=1;
    for(i=1; i<2000003; i++)
    {
        ff[i]=((i%M)*(ff[i-1]%M))%M;        // pre-calculating factorials
    }

    scanf("%lld", &test);

    for(i=1; i<=test; i++)
    {
        scanf("%lld %lld", &n, &r);

       r--;
       n+=r;


        if(r==0)    ans=1;
        else
        {

            a=ff[n];        // factorial n

            b=((ff[r]%M)*(ff[n-r]%M))%M;        // factorial r * factorial (n-r)

            c=bigmod(b, M-2, M );     // finding modular multiplicative inverse

            ans=((a%M)*(c%M))%M;      // finding answer

        }

        printf("Case %lld: %lld\n", i, ans);
    }

    return 0;
}
