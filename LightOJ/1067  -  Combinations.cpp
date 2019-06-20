# include<bits/stdc++.h>

typedef long long LL;

using namespace std;

LL bigmod ( LL a, LL n, LL M){

    if(!n)    return 1;

    return (n%2==0? (((bigmod(a, n/2, M)%M)*(bigmod(a, n/2, M)%M))%M):(((a%M)*(bigmod(a, n-1, M)))%M));
}

int ff[1000006];


int main(){

    LL n, r, b, a, ans, test, i, c, M=1000003;
    ff[0]=1;
    for(i=1; i<1000003; i++)
    {
        ff[i]=((i%M)*(ff[i-1]%M))%M;        // pre-calculating factorials 
    }

    scanf("%lld", &test);

    for(i=1; i<=test; i++)
    {
        scanf("%lld %lld", &n, &r);

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
