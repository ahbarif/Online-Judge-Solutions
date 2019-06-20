#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
 
LL biton(LL n, LL pos)    {   return n | (1<<pos);  }
LL bitoff(LL n, LL pos)   {   return n & ~(1<<pos); }
int bitck(LL n, LL pos)   {   return {(bool)(n & (1<<pos))};}
LL gcd(LL a, LL b)        {   return a%b?gcd(b, a%b):b;}
LL lcm(LL a, LL b)        {   int x = a/gcd(a, b); return x*b;};
 
int main() {
 
            int test, caseno=0;
            long long tmp, n, a[20], m, res, ans, cnt=0, i, j;
 
            scanf("%d", &test);
 
            while(test--)
            {
 
                       scanf("%lld %lld", &n, &m);
 
                       for(i=0; i<m; i++)   scanf("%lld", &a[i]);
                       ans=n;
 
                       LL pp=ceil(pow(2, m));
 
                       for(i=1; i<pp; i++)
                       {
                           cnt=0; tmp=1;
 
                           for(j=0; j<m; j++)
                           {
                                if(bitck(i, j))
                                {
                                    cnt++;
                                    LL k = lcm(tmp, a[j]);
                                    tmp=k;
                                }
                           }
 
                           res=n/tmp;
                           ans=(cnt%2?ans-res:ans+res);
                       }
 
                printf("Case %d: %lld\n", ++caseno,ans);
            }
 
        return 0;
 
}
 