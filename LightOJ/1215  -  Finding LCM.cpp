#include<bits/stdc++.h>
using namespace std;
 
typedef long long Long;
 
Long gcd(Long a, Long b)
{
       if(b==0) return a;
       if(a==0) return b;
 
       while(1)
       {
           Long c=a%b;
           if(c==0) return b;
 
           a=b;
           b=c;
       }
}
 
Long lcm(Long a, Long b)
{
    return (a*b)/gcd(a, b);
}
 
vector<Long> v;
 
int main()
{
 
        int T, caseno=1;
 
        scanf("%d", &T);
 
        for(caseno=1; caseno<=T; caseno++)
        {
                Long a, b, c, x, f=0, i;
 
                scanf("%lld %lld %lld", &a, &b, &x);
 
                c = lcm(a, b);
 
                for( i=1; i*i<=x; i++)
                {
                    if(x%i==0)  v.push_back(i), v.push_back(x/i);
                }
 
                sort(v.begin(), v.end());
 
                for( i=0; i<v.size(); i++)
                {
                    Long k = lcm(v[i], c);
 
                    if(k==x)
                    {
                        f=1;
                        break;
                    }
                }
 
                printf("Case %d: ", caseno);
                if(!f)  puts("impossible");
                else cout<<v[i]<<endl;
 
                v.clear();
        }
 
 
 
        return 0;
}