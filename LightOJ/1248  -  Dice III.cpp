#include <bits/stdc++.h>
using namespace std;

int main()
{

        int test, cs = 0;

        scanf("%d", &test);

        while(test--)
        {
              double n, res = 0;

              cin>>n;

              for(int i=1; i<=n; i++)
              {
                  res = res + n/i;
              }

              cout<<"Case "<<++cs<<": "<<std::fixed<<std::setprecision(8)<<res<<endl;

        }

     return 0;
}

