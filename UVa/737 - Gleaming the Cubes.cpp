# include<bits/stdc++.h>
using namespace std;

const long long inf = 1000000000000000LL;

int main()
{
       long long a[3], b[3], n, area;

       while(cin>>n && n)
       {
                a[0]=a[1]=a[2]=0;

                b[0]=b[1]=b[2]=inf;

                while(n--)
                {
                        long long p, q, r, s;

                        cin>>p>>q>>r>>s;

                        a[0] = max(a[0], p);
                        a[1] = max(a[1], q);
                        a[2] = max(a[2], r);

                        b[0] = min(b[0], p + s);
                        b[1] = min(b[1], q + s);
                        b[2] = min(b[2], r + s);

                }

                if(b[0]>a[0] && b[1]>a[1] && b[2]>a[2])
                {
                    area=(b[0]-a[0])*(b[1]-a[1])*(b[2]-a[2]);
                }
                else area=0;

                printf("%lld\n", area);
       }

       return 0;
}
