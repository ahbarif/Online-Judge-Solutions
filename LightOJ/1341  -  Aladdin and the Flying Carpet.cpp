#include<bits/stdc++.h>
using namespace std;
 
template<class T> inline T NOD(T n)
{
    T i, p = 0, ans = 1;
 
    if(n%2==0)
        while(n%2==0) n = n>>1, p++;
 
    ans*= (p+1);
 
    for(i=3; i*i<=n; i+=2){
        if(n%i==0){
            p = 0;
            while(n%i==0) n/=i, ++p;
            ans*=(p+1);
    }}
 
    return (n>1?ans*2:ans);
}
 
int main()
{
//    sieve();
 
    int test, cs = 0;
 
    cin>>test;
 
    while(test--)
    {
 
        long long a, b, sum;
 
        scanf("%lld %lld", &a, &b);
 
        if(a/b < b) sum = 0;
 
        else
        {
            sum = NOD(a);
            sum/=2;
 
            for(int i = 1; i<b; i++)
            {
                if(a%i==0)  sum--;
            }
        }
 
        printf("Case %d: %lld\n", ++cs, sum);
 
    }
 
    return 0;
}
