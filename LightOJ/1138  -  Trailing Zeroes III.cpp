#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<LL> fives;

inline LL zero(LL x)
{
    LL ans=0, k, i=0;

    while(1)
    {
        if(fives[i]>x)  break;
        k=x/fives[i];
        ans+=k;
        i++;
    }
    return ans;

}

LL ff(LL p)
{

        LL lo=1, hi = 1e17, mid, k, ans=0;

        while(1)
        {
                mid=(lo+hi)/2;
                k=zero(mid);
                if(k>p)         hi=mid;
                else if(k<p)    lo=mid;
                if(k==p)
                {
                    hi=mid;
                    ans=mid;
                }

                if(lo>hi || hi-lo<2)    break;

        }
    return ans;

}

int main(){


        LL x=1, p;
        for(int i=0; i<25; i++) x*=5, fives.push_back(x);


        int test, caseno=0;

        scanf("%d", &test);

        while(test--)
        {
                scanf("%lld", &x);

                p=ff(x);

                printf("Case %d: ", ++caseno);

                if(!p)  puts("impossible");

                else printf("%lld\n", p);
        }

    return 0;

}
