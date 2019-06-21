#include<bits/stdc++.h>
using namespace std;

int main()
{
        double p, q, r, s, t, u, res, hi, lo, mid;

        while(cin>>p>>q>>r>>s>>t>>u)
        {
            lo = 0.0;
            hi = 1.0;

            int flag = 0;

            for(int i=0; i<100; i++)
            {
                mid = (hi+lo)/2.0;

                double tmp = p* exp(-mid) + q*sin(mid) + r*cos(mid) + s*tan(mid) + t*mid*mid + u;

                if(abs(tmp-0.0)<=0.000001)
                {
                    flag = 1;
                    res = mid;

                }

                else if(tmp>0)  lo = mid;
                else hi = mid;

            }

            if(flag) cout<<std::fixed<<std::setprecision(4)<<res<<endl;

            else puts("No solution");
        }




	return 0;

}
